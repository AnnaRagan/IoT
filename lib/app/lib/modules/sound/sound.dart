import 'package:flutter/material.dart';
import 'package:flutter_sound/flutter_sound.dart';
import 'dart:async';
import 'dart:io';
import 'package:intl/intl.dart' show DateFormat;

class Sound extends StatefulWidget {
  @override
  _SoundState createState() => _SoundState();
}

class _SoundState extends State<Sound> {
  FlutterSound flutterSound;
  StreamSubscription _recorderSubscription;
  StreamSubscription _dbPeakSubscription;
  StreamSubscription _playerSubscription;

  bool _isRecording = false;
  bool _isPlaying = false;

//String _recorderTxt = '00:00:00';

  @override
  void initState() {
    super.initState();
    flutterSound = FlutterSound();
    flutterSound
      ..setSubscriptionDuration(0.01)
      ..setDbPeakLevelUpdate(0.8)
      ..setDbLevelEnabled(true);
  }

  void startRecorder() async {
    try {
      String path = await flutterSound.startRecorder(null);
      debugPrint("Recorder started: $path");

      _recorderSubscription = flutterSound.onRecorderStateChanged.listen((e) {
        DateTime date = DateTime.fromMicrosecondsSinceEpoch(e.currentPosition.toInt(), isUtc: true);
        String txt = DateFormat('mm:ss:SS', 'pl_PL').format(date);
//        this.setState((){
//          this
//        })
      });
      _dbPeakSubscription = flutterSound.onRecorderDbPeakChanged.listen((onData) {
        debugPrint("Got update -> $onData");
      });
      _isRecording = true;
    } catch (e) {
      print("startRecorder error: $e");
    }
  }



  @override
  Widget build(BuildContext context) {
    return Container();
  }
}
