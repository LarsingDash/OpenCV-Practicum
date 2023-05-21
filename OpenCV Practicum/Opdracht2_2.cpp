#include "Opdrachten.h"

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

void opdracht2_2()
{
	//Base
	const string path = "Resources/Custom/Boxes.jpg";
	const Mat img = imread(path);

	Mat baseImg, blurImg, cannyImg, dilImg, eroImg;
	resize(img, baseImg, Size(), 0.5, 0.5);

	GaussianBlur(baseImg, blurImg, Size(7, 7), 0, 0);

	Canny(blurImg, cannyImg, 5, 100);

	//Display
	imshow("Image", baseImg);
	imshow("Blur", blurImg);
	imshow("Canny", cannyImg);
	waitKey(0);
}