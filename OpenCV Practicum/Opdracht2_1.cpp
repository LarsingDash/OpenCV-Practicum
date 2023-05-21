#include "Opdrachten.h"

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

void opdracht2_1()
{
	//Base
	const string path = "Resources/Custom/ProfilePicture.JPG";
	const Mat img = imread(path);

	Mat baseImg;
	resize(img, baseImg, Size(), 0.5, 0.5);

	Mat blur1Img;
	GaussianBlur(baseImg, blur1Img, Size(5, 5), 1, 5);

	Mat blur2Img;
	GaussianBlur(baseImg, blur2Img, Size(5, 5), 5, 1);

	//Display
	imshow("Image", baseImg);
	imshow("Blur1", blur1Img);
	imshow("Blur2", blur2Img);
	waitKey(0);
}