#include "Opdrachten.h"

#include <iostream>

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

void opdracht2_3()
{
	//Base
	const string path = "Resources/Custom/ballstripes.bmp";
	Mat baseImg = imread(path);
	imshow("Base", baseImg);

	Mat invImg;
	bitwise_not(baseImg, invImg);
	imshow("Inverted", invImg);

	const Mat kernel = getStructuringElement(MORPH_RECT, Point(3, 3));
	constexpr int iterations = 2;

	//Erosion
	for (int i = 0; i < iterations; ++i)
	{
		Mat eroImg;
		erode(invImg, eroImg, kernel);
		invImg = eroImg;

		std::ostringstream oss;
		oss << "Erode " << i + 1;
		std::string text = oss.str();
		imshow(text, invImg);
	}

	//Dilation
	for (int i = 0; i < iterations; ++i)
	{
		Mat dilImg;
		dilate(invImg, dilImg, kernel);
		invImg = dilImg;

		std::ostringstream oss;
		oss << "Dilate " << i + 1;
		std::string text = oss.str();
		imshow(text, invImg);
	}

	//Display
	bitwise_not(invImg, baseImg);
	imshow("Final", baseImg);
	
	waitKey(0);
}