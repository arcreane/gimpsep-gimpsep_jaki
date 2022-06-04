#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

float contrast;

Mat light_dark(Mat src, float contrast)
{
	Mat newimage;

	cout << "Choose a number (superior to 1 if you want to ligthen the image, between 0 and 1 if you want to darken it)\n";
	cin >> contrast;

	src.convertTo(newimage, -1, contrast, 0);
	imshow("Light_dark", newimage);
	return newimage;
}