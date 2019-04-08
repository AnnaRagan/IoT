import 'package:flutter/material.dart';
import 'package:flutter_tts/flutter_tts.dart';
import 'package:app/modules/tts/tts.dart';
import 'package:app/modules/gps/geolocation.dart';

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

  int _currentTabIndex = 0;

  @override
  Widget build(BuildContext context) {
    final btmNavBaarPages = <Widget>[
      TextToSpeech(),
      Geolocator(),
      Container(),
//      Container(),
    ];
    return MaterialApp(
        home: SafeArea(
            child: Scaffold(
      bottomNavigationBar: BottomNavigationBar(
        items: [
          BottomNavigationBarItem(icon: Icon(Icons.record_voice_over), title: Text('Rozp. mowy')),
          BottomNavigationBarItem(icon: Icon(Icons.map), title: Text('Geolok.')),
          BottomNavigationBarItem(icon: Icon(Icons.settings), title: Text('Ustawienia')),
//          BottomNavigationBarItem(icon: Icon(Icons.perm_data_setting), title: Text('Dane')),
        ],
        currentIndex: _currentTabIndex,
        type: BottomNavigationBarType.fixed,
        onTap: (index) {
          setState(() {
            _currentTabIndex = index;
          });
        },
      ),
      body: btmNavBaarPages[_currentTabIndex],
//            appBar: AppBar(
//              title: const Text('KaZaPsa'),
//
//            ),
    )));
  }

  Widget visionToSpeech() {
    return Container(
      child: RaisedButton(
        onPressed: () => _speak(),
        child: Text('asdasd'),
      ),
    );
  }
}
