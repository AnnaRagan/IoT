#include "image.h"

using namespace cv;
using namespace cv::xfeatures2d;
using namespace std;

enum Light {
  GREEN = 1,
  RED = 0
};

void resizeCols (Mat &mat, int cols) {
  int matCols = cols;
  int matRows = cols * ((double) mat.size().height / mat.size().width);
  resize(mat, mat, Size(matCols, matRows));
}

bool isLoop = true;
Mat humanRedColor, humanRedGray;
Mat humanGreenColor, humanGreenGray;

void my_handler (int sig) {
  printf("Caught signal %d\n", sig);
  isLoop = false;
  terminate();
}

bool intersects (Rect &a, Rect &b) {
  if (a.tl().x > b.br().x || b.tl().x > a.br().x) return false;
  if (a.tl().y > b.br().y || b.tl().y > a.br().y) return false;
  return true;
}

double countNonZeroRatio (Mat &mat) {
  double totalItems = mat.cols * mat.rows;
  return countNonZero(mat) / totalItems;
}

void binarizeColor(Light currentLight, Mat &mat, Mat &output) {
  if (currentLight == RED) {
    Mat lowerRedHueRange, upperRedHueRange, veryBright;
    inRange(mat, Scalar(0, 200, 200), Scalar(10, 255, 255), lowerRedHueRange);
    inRange(mat, Scalar(160, 200, 200), Scalar(179, 255, 255), upperRedHueRange);
    addWeighted(lowerRedHueRange, 1.0, upperRedHueRange, 1.0, 0.0, output);
  } else if (currentLight == GREEN) {
    Mat greenHueRange, veryBright;
    inRange(mat, Scalar(80, 200, 200), Scalar(100, 255, 255), greenHueRange);
    greenHueRange.copyTo(output);
  }
}

void binarizeVeryDark(Mat &mat, Mat &output) {
  cvtColor(mat, output, COLOR_BGR2HSV);
  inRange(output, Scalar(0, 0, 150), Scalar(179, 255, 255), output);
}

double compareShapes(Mat &a, Mat &b) {
  vector<vector<Point>> aContours, bContours;
  vector<Vec4i> aHierarchy, bHierarchy;

  findContours(a, aContours, aHierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));
  findContours(b, bContours, bHierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));

  if (aContours.size() <= 0 || bContours.size() <= 0) return 1.0;
  return matchShapes(aContours[0], bContours[0], 1, 0.0);
}

double detectLight (Mat &frame, Mat &scene, Light currentLight, Mat &output, int cols, int rows, bool printColor) {
  Mat humanColor, humanGray, mask;

  binarizeColor(currentLight, frame, mask);
  humanColor = currentLight == RED ? humanRedColor : humanGreenColor;
  humanGray = currentLight == RED ? humanRedGray : humanGreenGray;

  Mat dilateElement = getStructuringElement(MORPH_ELLIPSE, Size(30, 30), Point(0, 0));
  dilate(mask, mask, dilateElement);

  Mat cannyOutput;
  vector<vector<Point>> contours;
  vector<Vec4i> hierarchy;

  Canny(mask, cannyOutput, 100, 200, 3);

  findContours(cannyOutput, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));

  Mat boxes;
  scene.copyTo(boxes);
  vector<Rect> boundRects(contours.size());
  RNG rng(12345);

  Mat bestImageFoundColor, bestImageFoundGray;
  double maxValFound = 0;
  double minValFound = 1;

  Scalar color = Scalar(255, 255, 255);

  for (int i = 0; i < contours.size(); i++) {
    boundRects[i] = boundingRect(Mat(contours[i]));
  }

  sort(boundRects.begin(), boundRects.end(), [](auto &a, auto &b){
    return ((b.br().x - b.tl().x) * (b.br().y - b.tl().y)) < ((a.br().x - a.tl().x) * (a.br().y - a.tl().y));
  });

  auto it = boundRects.begin();
  while (it != boundRects.end()) {
    auto itNext = it + 1;
    while (itNext != boundRects.end()) {
      if (intersects(*it, *itNext)) {
        boundRects.erase(itNext);
      } else {
        ++itNext;
      }
    }
    ++it;
  }

  for (int i = 0; i < boundRects.size(); i++) {
    auto tl = boundRects[i].tl();
    auto br = boundRects[i].br();

    rectangle(boxes, tl, br, color, 2, 8, 0);
    rectangle(mask, tl, br, color, 2, 8, 0);

    Rect roi(tl.x, tl.y, br.x - tl.x, br.y - tl.y);
    Size size(humanColor.cols, humanColor.rows);

    Mat croppedImageColor = scene(roi);
    resize(croppedImageColor, croppedImageColor, size);

    Mat croppedImageGray;
    binarizeVeryDark(croppedImageColor, croppedImageGray);

    double croppedImageNonZeroRatio = countNonZeroRatio(croppedImageGray);
    double humanNonZeroRatio = countNonZeroRatio(humanGray);

    if (abs(croppedImageNonZeroRatio - humanNonZeroRatio) > 0.2) continue;

    Mat result;
    double minVal, maxVal;
    Point minLoc, maxLoc;
    result.create(1, 1, CV_32FC1);
    matchTemplate(croppedImageColor, humanColor, result, TM_CCOEFF_NORMED);
    minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, Mat());
    if (maxVal > maxValFound) {
      maxValFound = maxVal;
      bestImageFoundColor = croppedImageColor;
      bestImageFoundGray = croppedImageGray;
    }

    // double result = compareShapes(croppedImageGray, humanGray);
    // if (result < minValFound) {
    //   minValFound = result;
    //   bestImageFoundColor = croppedImageColor;
    //   bestImageFoundGray = croppedImageGray;
    // }
  }

  rectangle(output, Point(0, 0), Point(cols, rows), Scalar(0, 0, 0), -1);

  if (printColor) {
    Mat sceneHsv;
    cvtColor(scene, sceneHsv, COLOR_BGR2HSV);
    auto center = Point(sceneHsv.cols / 2, sceneHsv.rows / 2);
    Vec3b color = sceneHsv.at<Vec3b>(center);
    cout
      << (int) color[0] << " (" << (int) color[0] * 360 / 180 << ")" << "\t\t"
      << (int) color[1] << " (" << (int) color[1] * 100 / 255 << ")" << "\t\t"
      << (int) color[2] << " (" << (int) color[2] * 100 / 255 << ")"
      << endl;

    circle(boxes, center, 5, Scalar(255, 255, 255), -1);
  }

  resizeCols(boxes, 500);
  boxes.copyTo(output(Rect(0, 0, boxes.cols, boxes.rows)));

  cvtColor(mask, mask, COLOR_GRAY2BGR);
  resizeCols(mask, 500);
  mask.copyTo(output(Rect(500, 0, mask.cols, mask.rows)));

  if (bestImageFoundColor.rows > 0 && maxValFound > 0.5) {
    resizeCols(bestImageFoundColor, 100);
    resizeCols(humanColor, 100);
    bestImageFoundColor.copyTo(output(Rect(0, boxes.rows, bestImageFoundColor.cols, bestImageFoundColor.rows)));
    humanColor.copyTo(output(Rect(bestImageFoundColor.cols, boxes.rows, humanColor.cols, humanColor.rows)));

    Mat bestImageFoundGrayCopy, humanGrayCopy;
    cvtColor(bestImageFoundGray, bestImageFoundGrayCopy, COLOR_GRAY2BGR);
    resizeCols(bestImageFoundGrayCopy, 100);
    bestImageFoundGrayCopy.copyTo(output(Rect(
      bestImageFoundColor.cols + humanColor.cols,
      boxes.rows,
      bestImageFoundGrayCopy.cols,
      bestImageFoundGrayCopy.rows
    )));
    cvtColor(humanGray, humanGrayCopy, COLOR_GRAY2BGR);
    resizeCols(humanGrayCopy, 100);
    humanGrayCopy.copyTo(output(Rect(
      bestImageFoundColor.cols + humanColor.cols + bestImageFoundGrayCopy.cols,
      boxes.rows,
      humanGrayCopy.cols,
      humanGrayCopy.rows
    )));

    // putText(
    //   output,
    //   to_string(maxValFound),
    //   Point(bestImageFoundColor.cols + humanColor.cols + 50, boxes.rows + 50),
    //   FONT_HERSHEY_DUPLEX,
    //   0.8,
    //   Scalar(255, 255, 255)
    // );
  };

  return maxValFound;
}

void countEach(vector<string> &infoArray, unordered_map<string, int> &output) {
  for (int i = 0; i < infoArray.size(); i += 1) {
    output[infoArray[i]] += 1;
  }
}

void stopProcessing() {
  isLoop = false;
}

void startProcessing(string mode, int cameraId, ServerReaderWriter<Detection, Action>* stream) {
  vector<string> infoArray;
  string lastInfo = "none";

  signal(SIGINT, my_handler);
  srand(time(NULL));

  MJPEGWriter *server;

  if (mode == "stream") {
    int port = rand() % 2000 + 3000;
    server = new MJPEGWriter(port);
    cout << "Listening on " << port << endl;
  }

  VideoCapture cap(cameraId);
  if (!cap.isOpened()) return;

  humanRedColor = imread("./images/humanRed.png", IMREAD_COLOR);
  humanGreenColor = imread("./images/humanGreen.png", IMREAD_COLOR);

  Mat scene = imread("./images/scene3.png", IMREAD_COLOR);

  if (!humanRedColor.data || !humanGreenColor.data || !scene.data) {
    printf("Error reading images \n");
    return;
  }

  binarizeVeryDark(humanRedColor, humanRedGray);
  binarizeVeryDark(humanGreenColor, humanGreenGray);

  Mat element = getStructuringElement(MORPH_ELLIPSE, Size(20, 20), Point(0, 0));
  dilate(humanGreenGray, humanGreenGray, element);

  Mat frame;

  if (mode == "stream") {
    cap >> frame;
    server->write(frame);
    frame.release();
    server->start();
  } else if (mode == "window") {
    namedWindow("Traffic lights");
  }

  auto white = Scalar(255, 255, 255);

  auto counter = 0;
  auto prevTime = time(NULL);

  while (isLoop) {
    auto now = time(NULL);
    if (now == prevTime) {
      counter += 1;
    } else {
      cout << counter << endl;
      prevTime = now;
      counter = 0;
    }

    auto center = Point(scene.cols / 2, scene.rows / 2);

    Mat scene;
    cap >> scene;
    cvtColor(scene, frame, COLOR_BGR2HSV);

    int rows = 700;
    int cols = 1000;
    Mat outputRed(rows, cols, CV_8UC3);
    Mat outputGreen(rows, cols, CV_8UC3);

    auto maxValFoundForRed = detectLight(frame, scene, RED, outputRed, cols, rows, false);
    auto maxValFoundForGreen = detectLight(frame, scene, GREEN, outputGreen, cols, rows, false);

    auto maxValFound = max(maxValFoundForRed, maxValFoundForGreen);
    auto output = maxValFoundForRed > maxValFoundForGreen ? outputRed : outputGreen;

    if (mode == "stream") {
      server->write(output);
    } else if (mode == "window") {
      imshow("Traffic lights", output);
    } else if (mode == "log") {
      auto newInfo = maxValFoundForRed > maxValFoundForGreen ? "red" : "green";
      if (maxValFound < 0.5) newInfo = "none";
      infoArray.push_back(newInfo);

      unordered_map<string, int> output;
      countEach(infoArray, output);

      if (output["red"] > infoArray.size() / 2) newInfo = "red";
      if (output["green"] > infoArray.size() / 2) newInfo = "green";
      if (output["none"] > infoArray.size() / 2) newInfo = "none";

      if (infoArray.size() > 10) {
        infoArray.erase(infoArray.begin(), infoArray.end() - 10);
      }

      if (newInfo != lastInfo) {
        cout << newInfo << endl;
        Detection detection;
        detection.set_light(newInfo);
        stream->Write(detection);
      }
      lastInfo = newInfo;
    }

    auto k = waitKey(1);
    if (k == 27) {
      break;
    }

    outputRed.release();
    outputGreen.release();
  }

  if (mode == "stream") {
    server->stop();
    delete server;
    cout << "server stopped" << endl;
  }
}
