#include <iostream>

#include "rpc.h"

using namespace std;

int main(int argc, char *argv[]) {
  if (argc < 2) {
    cout << "No mode provided" << endl;
    exit(1);
  }

  string mode = argv[1];
  int cameraId = atoi(argv[2]);
  startServer(mode, cameraId);

  return 0;
}
