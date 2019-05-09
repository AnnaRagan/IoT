import 'dart:async';
import 'dart:io';
import 'package:flutter/material.dart';
import 'package:flutter_tts/flutter_tts.dart';

import 'package:image_picker/image_picker.dart';
import 'package:firebase_ml_vision/firebase_ml_vision.dart';

class TextToSpeech extends StatefulWidget {
  @override
  _TextToSpeechState createState() => _TextToSpeechState();
  static FlutterTts flutterTts;

  void speakFromOutside(String string) {
    flutterTts.speak(string);
  }
}

enum TtsState { playing, stopped }

class _TextToSpeechState extends State<TextToSpeech> {
//  FlutterTts flutterTts;
  dynamic languages;
  dynamic voices;
  String language;
  String voice;

  String _newVoiceText = '';

  TtsState ttsState = TtsState.stopped;

  get isPlaying => ttsState == TtsState.playing;

  get isStopped => ttsState == TtsState.stopped;

  @override
  initState() {
    super.initState();
    initTts();
  }

  initTts() {
    TextToSpeech.flutterTts = FlutterTts();

    if (Platform.isAndroid) {
      TextToSpeech.flutterTts.ttsInitHandler(() {
        _getLanguages();
        _getVoices();
      });
    } else if (Platform.isIOS) {
      _getLanguages();
    }

    TextToSpeech.flutterTts.setStartHandler(() {
      setState(() {
        ttsState = TtsState.playing;
      });
    });

    TextToSpeech.flutterTts.setCompletionHandler(() {
      setState(() {
        ttsState = TtsState.stopped;
      });
    });

    TextToSpeech.flutterTts.setErrorHandler((msg) {
      setState(() {
        ttsState = TtsState.stopped;
      });
    });
  }

  Future _getLanguages() async {
    languages = await TextToSpeech.flutterTts.getLanguages;
    if (languages != null) setState(() => languages);
  }

  Future _getVoices() async {
    voices = await TextToSpeech.flutterTts.getVoices;
    if (voices != null) setState(() => voices);
  }

  Future _speak() async {
    if (_newVoiceText != null) {
      if (_newVoiceText.isNotEmpty) {
        var result = await TextToSpeech.flutterTts.speak(_newVoiceText);
        if (result == 1) setState(() => ttsState = TtsState.playing);
      }
    }
  }

  Future _stop() async {
    var result = await TextToSpeech.flutterTts.stop();
    if (result == 1) setState(() => ttsState = TtsState.stopped);
  }

  @override
  void dispose() {
    super.dispose();
    TextToSpeech.flutterTts.stop();
  }

  List<DropdownMenuItem<String>> getLanguageDropDownMenuItems() {
    var items = List<DropdownMenuItem<String>>();
    for (String type in languages) {
      items.add(DropdownMenuItem(value: type, child: Text(type)));
    }
    return items;
  }

  List<DropdownMenuItem<String>> getVoiceDropDownMenuItems() {
    var items = List<DropdownMenuItem<String>>();
    for (String type in voices) {
      items.add(DropdownMenuItem(value: type, child: Text(type)));
    }
    return items;
  }

  void changedLanguageDropDownItem(String selectedType) {
    setState(() {
      language = selectedType;
      TextToSpeech.flutterTts.setLanguage(language);
    });
  }

  void changedVoiceDropDownItem(String selectedType) {
    setState(() {
      voice = selectedType;
      TextToSpeech.flutterTts.setVoice(voice);
    });
  }

  void _onChange(String text) {
    setState(() {
      _newVoiceText = text;
    });
  }

  File _pickedImage;
  bool _isImageLoaded = false;

  Future pickImage() async {
    TextToSpeech.flutterTts.speak('Zrób zdjęcie');
    var tempStorage = await ImagePicker.pickImage(source: ImageSource.camera);
    setState(() {
      if (tempStorage != null) {
        _pickedImage = tempStorage;
        _isImageLoaded = true;
      }
    });
    TextToSpeech.flutterTts.speak('Czekaj na przetworzenie');

    processText();
  }

  Future processText() async {
    FirebaseVisionImage _firebaseVisionImage = FirebaseVisionImage.fromFile(_pickedImage);
    TextRecognizer _textRecognizer = FirebaseVision.instance.textRecognizer();
    VisionText _visionText = await _textRecognizer.processImage(_firebaseVisionImage);

    String _voiceText = "";

    for (TextBlock block in _visionText.blocks) {
//      debugPrint(block.toString());
      for (TextLine line in block.lines) {
        for (TextElement element in line.elements) {
          debugPrint(element.text);
          _voiceText = _voiceText + " " + element.text;
//          _voiceText.add
        }
      }
    }
    debugPrint(_newVoiceText);
    setState(
      () {
        _newVoiceText = _voiceText;
      },
    );
    debugPrint("Otrzymano: $_newVoiceText");
    TextToSpeech.flutterTts.speak('Tekst przetworzony');
    if (_newVoiceText == "") {
      TextToSpeech.flutterTts.speak('Brak wyrazów, lub niedokładne zdjęcie. Spróbuj ponownie.');
    } else {
      _speak();
    }
  }

  @override
  Widget build(BuildContext context) {
    return SingleChildScrollView(
        scrollDirection: Axis.vertical,
        child: Column(children: [
          SizedBox(height: 16),
          _isImageLoaded
              ? Container(
                  height: 200,
                  width: 200,
                  decoration: BoxDecoration(
                      image: DecorationImage(
                    image: FileImage(_pickedImage),
                    fit: BoxFit.cover,
                  )))
              : Text('Wybierz zdjęcie'),
          SizedBox(height: 8),
          Container(
            height: 100,
            width: 300,
            child: RaisedButton(
              child: Text('Zrób zdjęcie'),
              onPressed: pickImage,
            ),
          ),

//          RaisedButton(
//            child: Text('Przetwórz zdjęcie'),
//            onPressed: processText,
//          ),
          inputSection(),
          btnSection(),
          languages != null ? languageDropDownSection() : Text(""),
          voices != null ? voiceDropDownSection() : Text("")
        ]));
  }

  Widget inputSection() => Container(
        alignment: Alignment.topCenter,
        padding: EdgeInsets.only(top: 25.0, left: 25.0, right: 25.0),
        child: Text(_newVoiceText),
//      TextField(
//        onChanged: (String value) {
//          _onChange(value);
//
//        },

//      )
      );

  Widget btnSection() => Container(
      padding: EdgeInsets.only(top: 50.0),
      child: Row(mainAxisAlignment: MainAxisAlignment.spaceEvenly, children: [
        _buildButtonColumn(Colors.green, Colors.greenAccent, Icons.play_arrow, 'PLAY', _speak),
        _buildButtonColumn(Colors.red, Colors.redAccent, Icons.stop, 'STOP', _stop)
      ]));

  Widget languageDropDownSection() => Container(
      padding: EdgeInsets.only(top: 50.0),
      child: Row(mainAxisAlignment: MainAxisAlignment.center, children: [
        DropdownButton(
          value: language,
          items: getLanguageDropDownMenuItems(),
          onChanged: changedLanguageDropDownItem,
        )
      ]));

  Widget voiceDropDownSection() => Container(
      padding: EdgeInsets.only(top: 50.0),
      child: Row(mainAxisAlignment: MainAxisAlignment.center, children: [
        DropdownButton(
          value: voice,
          items: getVoiceDropDownMenuItems(),
          onChanged: changedVoiceDropDownItem,
        )
      ]));

  Column _buildButtonColumn(
      Color color, Color splashColor, IconData icon, String label, Function func) {
    return Column(
        mainAxisSize: MainAxisSize.min,
        mainAxisAlignment: MainAxisAlignment.center,
        children: [
          IconButton(
              icon: Icon(icon), color: color, splashColor: splashColor, onPressed: () => func()),
          Container(
              margin: const EdgeInsets.only(top: 8.0),
              child: Text(label,
                  style: TextStyle(fontSize: 12.0, fontWeight: FontWeight.w400, color: color)))
        ]);
  }
}
