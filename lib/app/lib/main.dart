import 'package:flutter/material.dart';
import 'package:flutter_tts/flutter_tts.dart';
import 'package:app/modules/tts/tts.dart';

void main() => runApp(MyApp());

class MyApp extends StatelessWidget {
  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
      theme: ThemeData(
        primarySwatch: Colors.blue,
      ),
      home: MyHomePage(title: 'Flutter Demo Home Page'),
    );
  }
}

class MyHomePage extends StatefulWidget {
  MyHomePage({Key key, this.title}) : super(key: key);

  final String title;

  @override
  _MyHomePageState createState() => _MyHomePageState();
}

enum TtsState { playing, stopped }

class _MyHomePageState extends State<MyHomePage> {
  FlutterTts _flutterTts = new FlutterTts();
  TtsState _ttsState = TtsState.stopped;

  Future _speak() async {
    var result = await _flutterTts.speak("Hello World");
    if (result == 1) setState(() => _ttsState = TtsState.playing);
  }

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: DefaultTabController(
        length: 4,
        child: Scaffold(
            appBar: AppBar(
              title: const Text('KaZaPsa'),
              bottom: TabBar(tabs: [
                Tab(icon: Icon(Icons.record_voice_over)),
                Tab(icon: Icon(Icons.map)),
                Tab(icon: Icon(Icons.settings)),
                Tab(icon: Icon(Icons.perm_data_setting)),
              ]),
            ),
            body: TabBarView(children: [
              ///TODO: process phone camera's capture and voice all recognized text
              TextToSpeech(),
//              visionToSpeech(),

              ///TODO: reverse geolocation; by pressing a button or speaking, user gets to know own location (street name)
              geoLocation(),

//              Container(),
              Container(),
              Container(),
            ])),
      ),
    );
  }

  Widget visionToSpeech() {
    return Container(
      child: RaisedButton(
        onPressed: () => _speak(),
        child: Text('asdasd'),
      ),
    );
  }

  Widget geoLocation() {
    return Column(
      children: <Widget>[Container()],
    );
  }
}
