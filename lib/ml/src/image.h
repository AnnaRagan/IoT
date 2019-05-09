#include <iostream>
#include <vector>
#include <signal.h>
#include <time.h>
#include <thread>
#include <grpcpp/grpcpp.h>

#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"

#include "opencv2/highgui.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/xfeatures2d.hpp"

#include "MJPEGWriter.h"

#include "lights.grpc.pb.h"
#include "lights.pb.h"

using namespace std;
using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerReaderWriter;
using grpc::Status;

typedef void (*stop)();

void startProcessing(string mode, int cameraId, ServerReaderWriter<Detection, Action>* stream);
void stopProcessing();
