#include "Opdrachten.h"

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

void opdracht1_3()
{
	Mat img(512, 512, CV_8UC3, Scalar(25, 25, 25));
	const Scalar orange(0, 75, 255);
	constexpr int horMid = 256;

	//Head
	circle(img, Point(horMid, 150), 50, orange, FILLED);

	//Neck
	line(img, Point(horMid, 200), Point(horMid, 225), orange, 10);

	//Body
	rectangle(img, Point(horMid - 50, 225), Point(horMid + 50, 350), orange, FILLED);

	//Legs
	line(img, Point(horMid - 25, 350), Point(horMid - 25, 450), orange, 10);
	line(img, Point(horMid + 25, 350), Point(horMid + 25, 450), orange, 10);

	//Arms
	line(img, Point(horMid - 50, 250), Point(horMid - 75, 325), orange, 10);
	line(img, Point(horMid + 50, 250), Point(horMid + 75, 325), orange, 10);

	//Text
	putText(img, "Stick Figure", Point(100, 65), FONT_HERSHEY_DUPLEX, 1.5, orange, 2);

	//Show image
	imshow("Image", img);
	waitKey(0);
}