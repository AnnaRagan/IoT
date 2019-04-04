#include <iostream>
#include <vector>
#include <signal.h>
#include <time.h>

#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"

#include "opencv2/highgui.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/xfeatures2d.hpp"

#include "MJPEGWriter.h"

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
Mat humanRed;
Mat humanGreen;

void my_handler (int sig) {
  printf("Caught signal %d\n", sig);
  isLoop = false;
}

double detectLight (Mat &frame, Mat &scene, Light currentLight, Mat &output, int cols, int rows, bool printColor) {
  Mat human, mask;

  if (currentLight == RED) {
    Mat lowerRedHueRange;
    Mat upperRedHueRange;
    inRange(frame, Scalar(0, 200, 200), Scalar(10, 255, 255), lowerRedHueRange);
    inRange(frame, Scalar(160, 200, 200), Scalar(179, 255, 255), upperRedHueRange);
    addWeighted(lowerRedHueRange, 1.0, upperRedHueRange, 1.0, 0.0, mask);
    human = humanRed;
  } else if (currentLight == GREEN) {
    Mat greenHueRange;
    inRange(frame, Scalar(80, 200, 200), Scalar(100, 255, 255), greenHueRange);
    greenHueRange.copyTo(mask);
    human = humanGreen;
  }

  Mat element = getStructuringElement(MORPH_RECT, Size(12, 12), Point(0, 0));
  dilate(mask, mask, element);

  Mat cannyOutput;
  vector<vector<Point>> contours;
  vector<Vec4i> hierarchy;

  Canny(mask, cannyOutput, 100, 200, 3);

  findContours(cannyOutput, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));

  Mat boxes;
  scene.copyTo(boxes);
  vector<Rect> boundRects(contours.size());
  RNG rng(12345);

  Mat bestImageFound;
  double maxValFound = 0;
  double minValFound = 10000;

  for (int i = 0; i < contours.size(); i++) {
    Scalar color = Scalar(255, 255, 255);

    boundRects[i] = boundingRect(Mat(contours[i]));
    auto tl = boundRects[i].tl();
    auto br = boundRects[i].br();

    rectangle(boxes, tl, br, color, 2, 8, 0);
    rectangle(mask, tl, br, color, 2, 8, 0);

    Rect roi(tl.x, tl.y, br.x - tl.x, br.y - tl.y);
    Mat croppedImage = scene(roi);

    Size size(human.cols, human.rows);
    resize(croppedImage, croppedImage, size);

    Mat result;
    result.create(1, 1, CV_32FC1);

    matchTemplate(croppedImage, human, result, TM_CCOEFF_NORMED);

    double minVal;
    double maxVal;
    Point minLoc;
    Point maxLoc;

    minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, Mat());

    if (maxVal > maxValFound) {
      bestImageFound = croppedImage;
      maxValFound = maxVal;
    }
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

  if (bestImageFound.rows > 0 && maxValFound >= 0.5) {
    double totalItems = human.cols * human.rows;
    Mat nonZeroPattern, nonZeroHuman;
    inRange(bestImageFound, Scalar(0, 0, 0), Scalar(179, 255, 255), nonZeroPattern);
    inRange(human, Scalar(0, 0, 0), Scalar(179, 255, 255), nonZeroHuman);
    double nonZeroPatternItems = countNonZero(nonZeroPattern);
    double nonZeroHumanItems = countNonZero(nonZeroHuman);
    cout << "non zero: " << nonZeroPatternItems / totalItems << "\t" << nonZeroHumanItems / totalItems << endl;

    resizeCols(bestImageFound, 100);
    resizeCols(human, 100);
    bestImageFound.copyTo(output(Rect(0, boxes.rows, bestImageFound.cols, bestImageFound.rows)));
    human.copyTo(output(Rect(bestImageFound.cols, boxes.rows, human.cols, human.rows)));

    cvtColor(nonZeroPattern, nonZeroPattern, COLOR_GRAY2BGR);
    resizeCols(nonZeroPattern, 100);
    nonZeroPattern.copyTo(output(Rect(bestImageFound.cols + human.cols, boxes.rows, nonZeroPattern.cols, nonZeroPattern.rows)));

    cvtColor(nonZeroHuman, nonZeroHuman, COLOR_GRAY2BGR);
    resizeCols(nonZeroHuman, 100);
    nonZeroHuman.copyTo(output(Rect(bestImageFound.cols + human.cols + nonZeroPattern.cols, boxes.rows, nonZeroHuman.cols, nonZeroHuman.rows)));

    // putText(
    //   output,
    //   to_string(maxValFound),
    //   Point(bestImageFound.cols + human.cols + 50, boxes.rows + 50),
    //   FONT_HERSHEY_DUPLEX,
    //   0.8,
    //   Scalar(255, 255, 255)
    // );
  };

  return maxValFound;
}

int main(int, char**) {
  signal(SIGINT, my_handler);
  srand (time(NULL));

  int port = rand() % 2000 + 3000;
  MJPEGWriter server(port);
  cout << "Listening on " << port << endl;

  VideoCapture cap(0);
  if (!cap.isOpened()) return -1;

  humanRed = imread("./images/humanRed.png", IMREAD_COLOR);
  humanGreen = imread("./images/humanGreen.png", IMREAD_COLOR);
  Mat scene = imread("./images/scene1.png", IMREAD_COLOR);

  if (!humanRed.data || !humanGreen.data || !scene.data) {
    printf("Error reading images \n");
    return -1;
  }

  Mat frame;
  cap >> frame;
  server.write(frame);
  frame.release();

  server.start();

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

    if (maxValFoundForRed > maxValFoundForGreen) {
      server.write(outputRed);
    } else {
      server.write(outputGreen);
    }

    auto k = waitKey(16);
    if (k == 27) {
      break;
    }

    outputRed.release();
    outputGreen.release();
  }

  server.stop();
  cout << "server stopped" << endl;

  exit(0);
}