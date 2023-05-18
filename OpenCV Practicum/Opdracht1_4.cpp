#include "Opdrachten.h"

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

void opdracht1_4()
{
	//Source
	const string path = "Resources/Custom/Boxes.jpg";
	const Mat img = imread(path);

	//Vars for GPU
	Mat gpuImg;
	float gpuW = 600, gpuH = 400;

	const Point2f gpuSrc[4] = {
		{188, 602},
		{950, 671},
		{120, 1009},
		{1114, 1002}
	};
	const Point2f gpuDst[4] = {
		{0, 0},
		{gpuW, 0},
		{0, gpuH},
		{gpuW, gpuH}
	};

	//Vars for Motherboard
	Mat motherImg;
	float motherW = 550, motherH = 400;

	const Point2f motherSrc[4] = {
		{963, 649},
		{1430, 703},
		{1143, 967},
		{1696, 984}
	};
	const Point2f motherDst[4] = {
		{0, 0},
		{motherW, 0},
		{0, motherH},
		{motherW, motherH}
	};

	//Warp GPU
	const Mat gpuMatrix = getPerspectiveTransform(gpuSrc, gpuDst);
	warpPerspective(img, gpuImg, gpuMatrix, Point(gpuW, gpuH));

	//Warp Motherboard
	const Mat motherMatrix = getPerspectiveTransform(motherSrc, motherDst);
	warpPerspective(img, motherImg, motherMatrix, Point(motherW, motherH));

	//Add dots to source
	for (auto i : gpuSrc)
	{
		circle(img, i, 10, Scalar(0, 0, 255), FILLED);
	}

	for (auto i : motherSrc)
	{
		circle(img, i, 10, Scalar(0, 255, 0), FILLED);
	}

	//Resize source
	Mat sizedImg;
	resize(img, sizedImg, Size(), 0.5, 0.5);

	//Display
	imshow("Source Image", sizedImg);
	imshow("GPU", gpuImg);
	imshow("Motherboard", motherImg);
	waitKey(0);
}
