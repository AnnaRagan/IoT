import 'package:flutter/material.dart';
import 'package:toast/toast.dart';

//import 'package:geolocator/geolocator.dart';
import 'dart:async';
//import 'package:flutter_map/flutter_map.dart';

//import 'package:latlong/latlong.dart';
import 'package:flutter/services.dart';
import 'package:location/location.dart';
import 'package:flutter/material.dart';
import 'package:google_maps_flutter/google_maps_flutter.dart';
import 'package:geocoder/geocoder.dart';

import 'package:app/modules/tts/tts.dart';
/////////////////////

/////////////////

class Geolocator extends StatefulWidget {
  @override
  State<Geolocator> createState() => GeolocatorState();
}

class GeolocatorState extends State<Geolocator> {
  Completer<GoogleMapController> _controller = Completer();

  static final CameraPosition _kKrk = CameraPosition(
    target: LatLng(50.062, 19.937),
    zoom: 13,
  );

  static final CameraPosition _kKrKCentrum = CameraPosition(
//      bearing: 192.8334901395799,
      target: LatLng(50.062, 19.9370),
//      tilt: 59.440717697143555,
      zoom: 15);

//  Marker marker = Marker(
//    markerId: MarkerId('myloc'),
////    icon: Icon(Icons.add_location),
//    visible: true,
//    position: LatLng(_currentLocation.latitude, _currentLocation.longitude), // _currentLocation,
//  );
  Map<MarkerId, Marker> markers = <MarkerId, Marker>{}; // CLASS MEMBER, MAP OF MARKS

  void _add() {
    final MarkerId markerId = MarkerId('myloc');

    // creating a new MARKER
    final Marker marker = Marker(
      markerId: markerId,
      position: LatLng(
        _currentLocation.latitude,
        _currentLocation.longitude,
      ),
    );

    setState(() {
      // adding a new marker to map
      markers[markerId] = marker;
    });
  }

  @override
  Widget build(BuildContext context) {
    return SafeArea(
        child: Scaffold(
      body: GoogleMap(
        mapType: MapType.hybrid,
        initialCameraPosition: _kKrk,
        markers: Set<Marker>.of(markers.values), // YOUR MARKS IN MAP
//            markers: Set<Marker>.of(marker)

//                    xOf(Marker(markerId: MarkerId('adad')))
//            markers: <Set>[
//        Marker(
//        markerId: MarkerId('myloc'),
//            icon:
//            Icon(Icons.add_location)

//        visible: true,
//        position: LatLng(
//            _currentLocation.latitude, _currentLocation.longitude), // _currentLocation,
//      );
//
//      ],
        onMapCreated: (GoogleMapController controller) {
          _controller.complete(controller);
        },
      ),
      floatingActionButton: Row(
          mainAxisAlignment: MainAxisAlignment.spaceEvenly,
          crossAxisAlignment: CrossAxisAlignment.center,
          children: <Widget>[
            FloatingActionButton.extended(
              onPressed: _goToTheCntr,
              label: Text('Centrum'),
              icon: Icon(Icons.directions),
            ),
//            FloatingActionButton.extended(
//              onPressed: () {},
//              label: Text('Ja'),
//              icon: Icon(Icons.my_location),
//            ),

            FloatingActionButton.extended(
              onPressed: () => slowRefresh(),
              label: Text('Ja'),
              icon: Icon(Icons.my_location),
            )
          ]),
    ));
  }

  Future<void> _goToTheCntr() async {
    final GoogleMapController controller = await _controller.future;
    controller.animateCamera(CameraUpdate.newCameraPosition(_kKrKCentrum));
  }

  Future<void> _goToCurrentPosition(LatLng latlng) async {
    final GoogleMapController controller = await _controller.future;

    controller
        .animateCamera(CameraUpdate.newCameraPosition(CameraPosition(target: latlng, zoom: 16)));
  }

////////////////////////////////////////////////////////////
  LocationData _startLocation;

  LocationData _currentLocation;

  StreamSubscription<LocationData> _locationSubscription;

  Location _locationService = new Location();
  bool _permission = false;
  String error;

  bool currentWidget = true;

  Image image1;

  @override
  void initState() {
    super.initState();

    initPlatformState();

    ///TODO: GPS location is fetched continously
    slowRefresh();
  }

  // Platform messages are asynchronous, so we initialize in an async method.
  initPlatformState() async {
    await _locationService.changeSettings(accuracy: LocationAccuracy.HIGH, interval: 1000);

    LocationData location;
    // Platform messages may fail, so we use a try/catch PlatformException.
    try {
      bool serviceStatus = await _locationService.serviceEnabled();
      print("Service status: $serviceStatus");
      if (serviceStatus) {
        _permission = await _locationService.requestPermission();
        print("Permission: $_permission");
        if (_permission) {
          location = await _locationService.getLocation();
          print("Location: ${location.latitude}");
          _locationSubscription =
              _locationService.onLocationChanged().listen((LocationData result) {
            if (mounted) {
              setState(() {
                _currentLocation = result;
              });
            }
          });
        }
      } else {
        bool serviceStatusResult = await _locationService.requestService();
        print("Service status activated after request: $serviceStatusResult");
        if (serviceStatusResult) {
          initPlatformState();
        }
      }
    } on PlatformException catch (e) {
      print(e);
      if (e.code == 'PERMISSION_DENIED') {
        error = e.message;
      } else if (e.code == 'SERVICE_STATUS_ERROR') {
        error = e.message;
      }
      location = null;
    }

    setState(() {
      _startLocation = location;
    });
  }

  slowRefresh() async {
    _locationSubscription.cancel();
    await _locationService.changeSettings(accuracy: LocationAccuracy.BALANCED, interval: 10000);
    _locationSubscription = _locationService.onLocationChanged().listen((LocationData result) {
      if (mounted) {
        setState(() {
          _goToCurrentPosition(LatLng(result.latitude, result.longitude));
//          _currentLocation = result;
        });
      }
    });

    ///TODO: add marker //DONE
    _add();
    final coordinates = new Coordinates(_currentLocation.latitude, _currentLocation.longitude);
    var addresses = await Geocoder.local.findAddressesFromCoordinates(coordinates);
    var first = addresses.first;
    debugPrint("${first.featureName} ${first.addressLine}");
//    print("${first.featureName} : ${ first
//    addressLine
//    }
//    "
//    );
    Toast.show("Znajdujesz się koło:\n ${first.featureName} ${first.addressLine}", context,
        duration: 10, gravity: Toast.BOTTOM, backgroundRadius: 10);
    debugPrint(first.featureName);

    ///TODO: add reverse geolocalization
    TextToSpeech.flutterTts.speak("Znajdujesz się na ulicy ${first.addressLine}");
//    tts.speakFromOutside('adasda');
  }
}
