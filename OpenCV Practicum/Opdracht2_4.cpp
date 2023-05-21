#include "Opdrachten.h"

#include <iostream>

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

void opdracht2_4()
{
	string path = "Resources/Custom/kerstballen.bmp";
	Mat img = imread(path);
	Mat imgHSV, mask;
	int hmin = 275, smin = 100, vmin = 0;
	int hmax = 360, smax = 255, vmax = 255;

	cvtColor(img, imgHSV, COLOR_BGR2HSV);

	namedWindow("Trackbars", (640, 200));
	createTrackbar("Hue Min", "Trackbars", &hmin, 360);
	createTrackbar("Hue Max", "Trackbars", &hmax, 360);
	createTrackbar("Sat Min", "Trackbars", &smin, 255);
	createTrackbar("Sat Max", "Trackbars", &smax, 255);
	createTrackbar("Val Min", "Trackbars", &vmin, 255);
	createTrackbar("Val Max", "Trackbars", &vmax, 255);

	while (true) {
		Scalar lower(hmin / 2, smin, vmin);
		Scalar upper(hmax / 2, smax, vmax);
		inRange(imgHSV, lower, upper, mask);

		imshow("Image", img);
		imshow("Image HSV", imgHSV);
		imshow("Image Mask", mask);
		if (waitKey(20) != -1) break;
	}
}