#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;



Mat resized_src;

// Scaling factors
double scaleX;
double scaleY;

Mat rezising(Mat src, double scaleX, double scaleY)
{
	//dispaly the dimension of the previous image
	cout << "Current image height: " << src.size().height << endl;
	cout << "Current image width : " << src.size().width << endl;

	// the user chooses the multiplicating factor
	cout << "Choose the multiplicator factor to modify the height of the image: ";
	cin >> scaleX;
	cout << "Choose the multiplicator factor to modify the width of the image: ";
	cin >> scaleY;

	// Scaling the image by dimension
	resize(src, resized_src, Size(), scaleX, scaleY, INTER_LINEAR);
	return resized_src;
}
