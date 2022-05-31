#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


float contrast;

Mat light_dark(Mat src, float contrast)
{
	Mat newimage;

	cout << "Tap a number";
	cin >> contrast;

	src.convertTo(newimage, -1, contrast, 0);
	imshow("Light_dark", newimage);
	return newimage;
}