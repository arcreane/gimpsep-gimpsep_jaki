#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;



Mat resized_src;

// Scaling factors
double scaleX;
double scaleY;

Mat rezising(Mat src, double scaleX, double scaleY)
{
	cout << "Current image height: " << src.size().height << endl;
	cout << "Current image width : " << src.size().width << endl;

	cout << "Choose the height\n";
	cin >> scaleX;
	cout << "Choose the width\n";
	cin >> scaleY;

	// Scaling the image by dimension
	resize(src, resized_src, Size(), scaleX, scaleY, INTER_LINEAR);
	return resized_src;
}
