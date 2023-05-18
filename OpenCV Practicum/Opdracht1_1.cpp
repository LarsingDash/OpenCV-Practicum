#include "Opdrachten.h"

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;


/////////////////  Images  //////////////////////

void opdracht1_1() {

	string path = "Resources/test.png";
	Mat img = imread(path);
	imshow("Image", img);
	waitKey(0);
}


///////////////  Video  //////////////////////

// void Opdracht1_1() {
//
// 	string path = "Resources/test_video.mp4";
// 	VideoCapture cap(path);
// 	Mat img;
//
// 	while (true) {
//
// 		cap.read(img);
// 		imshow("Image", img);
// 		
// 		if (waitKey(20) == 32) break;
// 	}
// }


/////////////////  Webcam  //////////////////////

// void Opdracht1_1() {
//
// 	VideoCapture cap(0);
// 	Mat img;
//
// 	while (true) {
//
// 		cap.read(img);
// 		imshow("Image", img);
// 		if (waitKey(1) == 32) break;
// 	}
// }