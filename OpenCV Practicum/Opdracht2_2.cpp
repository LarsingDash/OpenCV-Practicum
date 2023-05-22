#include "Opdrachten.h"

#include <iostream>

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

void opdracht2_2()
{
	//Base
	const string path = "Resources/cards.jpg";
	const Mat img = imread(path);

	Mat baseImg, blurImg, cannyImg, dilImg, eroImg;
	resize(img, baseImg, Size(), 0.5, 0.5);

	GaussianBlur(baseImg, blurImg, Size(7, 7), 0, 0);

	//Display
	imshow("Image", baseImg);
	// imshow("Blur", blurImg);

	int minThreshold = 0;
	int maxThreshold = 100;

	namedWindow("Thresholds");
	createTrackbar("min", "Thresholds", &minThreshold, 100);
	createTrackbar("max", "Thresholds", &maxThreshold, 100);

	while (true)
	{
		Canny(blurImg, cannyImg, minThreshold, maxThreshold);
		imshow("Canny", cannyImg);

		if (waitKey(20) != -1) break;
	}
}