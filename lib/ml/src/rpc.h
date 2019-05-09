#include <iostream>
#include <grpcpp/grpcpp.h>

#include "lights.grpc.pb.h"
#include "lights.pb.h"

#include "image.h"

using namespace std;
using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerReaderWriter;
using grpc::Status;

void stopServer();
void startServer(string mode, int cameraId);
