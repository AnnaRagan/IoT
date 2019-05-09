#include "rpc.h"

unique_ptr<Server> server;
string mode;
int cameraId;
bool isProcessing;
thread processingThread;

class LightsServiceImpl final : public Lights::Service {
  Status Connect(ServerContext* context, ServerReaderWriter<Detection, Action>* stream) override {
    cout << "Connected" << endl;

    std::vector<Action> receivedActions;
    Action action;
    while (!context->IsCancelled() && stream->Read(&action)) {
      cout << "Received action: " << action.type() << endl;

      auto type = action.type();
      if (type == "start_processing" && !isProcessing) {
        isProcessing = true;
        processingThread = thread([&](){
          cout << "Processing started" << endl;
          startProcessing(mode, cameraId, stream);
        });
      } else if (type == "stop_processing" && isProcessing) {
        stopProcessing();
        processingThread.join();
        isProcessing = false;
        cout << "Processing stopped" << endl;
      }
    }

    return Status::OK;
  }
};

void stopServer() {
  terminate();
  // server->Shutdown();
}

void startServer(string _mode, int _cameraId) {
  mode = _mode;
  cameraId = _cameraId;

  string server_address("0.0.0.0:50051");
  LightsServiceImpl *service = new LightsServiceImpl();

  ServerBuilder builder;
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  builder.RegisterService(service);

  server = unique_ptr<Server>(builder.BuildAndStart());
  cout << "Server listening on " << server_address << endl;
  server->Wait();
}
