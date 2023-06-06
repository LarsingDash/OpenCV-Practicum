#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

vector<vector<int>> drawPoints;

vector<vector<int>> hsvColors{
	// hmin, smin, vmin hmax, smax, vmax
	{65, 85, 95, 90, 160, 255}, // Green
	{94, 108, 75, 160, 206, 255}, // Blue
	{23, 73, 75, 65, 163, 255} // Yellow
};

vector<Scalar> bgrColors{
	{81, 218, 35}, // Green
	{223, 165, 96}, // Blue
	{94, 234, 217} // Yellow
};

vector<Point> getPoints(const Mat& image)
{
	//Declare containers for contour values
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	//Find contours
	findContours(image, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

	//Declare containers for shape / polygon values
	vector<vector<Point>> conPoly(contours.size());
	vector<Rect> boundRect(contours.size());

	//Declare vector to store found points
	vector<Point> foundPoints = vector<Point>();

	//Check for all contours
	for (int i = 0; i < contours.size(); i++)
	{
		//Calculate area of the contour
		const double area = contourArea(contours[i]);

		//Area must be above 1000, to filter small noise
		if (area > 1000)
		{
			//Calculate perimeter to better approximate the polygon
			const double perimeter = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * perimeter, true);

			//Get bounding box of contour to calculate the tip (where the point is drawn)
			boundRect[i] = boundingRect(conPoly[i]);

			//Declare new point. (0, 0) by default, if its still default afterwards it's ignored
			Point foundPoint(0, 0);
			foundPoint.x = boundRect[i].x + boundRect[i].width / 2;
			foundPoint.y = boundRect[i].y;

			foundPoints.push_back(foundPoint);
		}
	}

	//Return the potential point
	return foundPoints;
}

void findColor(const Mat& baseImg)
{
	//Convert to HSV format
	Mat hsvImg;
	cvtColor(baseImg, hsvImg, COLOR_BGR2HSV);

	//Test show HSV
	// imshow("hsv", hsvImg);

	//For each of the hardcoded colors:
	for (int i = 0; i < hsvColors.size(); i++)
	{
		//Create lower and upper bounds
		Scalar lower(hsvColors[i][0], hsvColors[i][1], hsvColors[i][2]);
		Scalar upper(hsvColors[i][3], hsvColors[i][4], hsvColors[i][5]);

		//Create a mask between the upper and lower bounds of the current color
		Mat mask;
		inRange(hsvImg, lower, upper, mask);

		//Test show mask
		// if (i == 2)
			// imshow(to_string(i), mask);

		//Test for a potential points to add to the drawing list
		for (auto point : getPoints(mask))
		{
			if (point.x != 0)
				drawPoints.push_back({point.x, point.y, i});
		}
	}
}

void visualPainter()
{
	Mat cam;
	Mat baseImg;

	VideoCapture cap(0);

	//Trackbars for testing new colors
	// namedWindow("Trackbars", (640, 200));
	// createTrackbar("Hue Min", "Trackbars", &hsvColors[2][0], 255);
	// createTrackbar("Hue Max", "Trackbars", &hsvColors[2][3], 255);
	// createTrackbar("Sat Min", "Trackbars", &hsvColors[2][1], 255);
	// createTrackbar("Sat Max", "Trackbars", &hsvColors[2][4], 255);
	// createTrackbar("Val Min", "Trackbars", &hsvColors[2][2], 255);
	// createTrackbar("Val Max", "Trackbars", &hsvColors[2][5], 255);

	while (true)
	{
		//Read the camera
		cap.read(cam);

		//Flip camera img horizontally
		flip(cam, baseImg, 1);

		//Find new points
		findColor(baseImg);

		//Draw new points
		for (auto& drawPoint : drawPoints)
			circle(baseImg, Point(drawPoint[0], drawPoint[1]), 10, bgrColors[drawPoint[2]], FILLED);

		//Show current image
		imshow("Image", baseImg);

		//Test for space bar, if so: clear points
		const int key = waitKey(1);
		if (key == 32) drawPoints = vector<vector<int>>();
		else if (key != -1) break;
	}
}
