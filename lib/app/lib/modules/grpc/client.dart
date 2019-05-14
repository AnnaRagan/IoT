import 'dart:async';
import 'package:flutter/widgets.dart';
import 'package:grpc/grpc.dart';
import 'package:app/modules/grpc/generated/app.pb.dart';
import 'package:app/modules/grpc/generated/app.pbgrpc.dart';


Stream<Action> generateCommands() async* {
  Action tmp;
  tmp.type = 'start_processing';
  yield tmp;

//  for (int i = 0; i < 10; i++) {
//    Future.delayed(Duration(seconds: 1));
//    yield tmp;
//  }
}


Future<void> detectType() async {
  final channel = ClientChannel('127.0.0.1',
      port: 50051,
      options: ChannelOptions(
        credentials: ChannelCredentials.insecure(),
      ));

  final LightsClient client = LightsClient(channel,
      options: CallOptions(timeout: Duration(seconds: 20));

      await for(Detection detection in client.connect(generateCommands())){
  debugPrint(detection.light);
  }


}


//class ConnToRPi extends LightsServiceBase{
//  final channel = ClientChannel('127.0.0.1',
//      port: 50051,
//      options: ChannelOptions(
//        credentials: ChannelCredentials.insecure(),
//      ));
//
//  LightsClient client;
//
//  ConnToRPi() {
//    client = LightsClient(channel,
//        options: CallOptions(
//          timeout: Duration(seconds: 20),
//        ));
//
////    client.connect('start_processing');
//  }
//
//
////  receiveNotifications() async {
////
////    client.connect(request)
////
////  }
//
//  @override
//  Stream<Detection> connect(ServiceCall call, Stream<Action> request) async* {
//
////    call.
//    // TODO: implement connect
//    return null;
//  }
//}
//class ConnToPi2 extends LightsClient {
//  ConnToPi2(ClientChannel channel) : super(channel);
//@override ResponseStream<Detection> connect(Stream<Action> request, {CallOptions options}) {
//    // TODO: implement connect
//  return super.connect(request, options);
//  }
////  ClientChannel('127.0.0.1',
////      port: 50051,
////      options: ChannelOptions(
////        credentials: ChannelCredentials.insecure(),
////      ));
//
//}
