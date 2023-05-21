#include "Opdrachten.h"

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

void opdracht1_2()
{
	//Base
	const string path = "Resources/Custom/ProfilePicture.JPG";
	const Mat baseImg = imread(path);

	//Resized
	Mat sizedImg;
	resize(baseImg, sizedImg, Size(), 0.75, 0.25);

	//Cropped
	const Rect roi(250, 665, 280, 90);
	const Mat croppedImg = baseImg(roi);

	//Display
	imshow("Image", baseImg);
	imshow("Sized Image", sizedImg);
	imshow("Cropped Image", croppedImg);
	waitKey(0);
}
