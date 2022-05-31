#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "Lighten_darken.h"
#include "Rezising.h"
#include <iostream>


using namespace std;
using namespace cv;


int main(void)
{
	Mat src;
	src = imread("van_gogh.jpg", IMREAD_COLOR);
	if (src.empty())
	{
		cout << "Pas d'image" << endl;
		return -1;
	}

	cout << "enter a number for the contrast";
	cin >> contrast;
	cout << "enter a number for the scaleX";
	cin >> scaleX;
	cout << "enter a number for the scaleY";
	cin >> scaleY;

	light_dark(src, contrast);
	rezising(src, scaleX, scaleY);
	waitKey(0);
	return 0;
}