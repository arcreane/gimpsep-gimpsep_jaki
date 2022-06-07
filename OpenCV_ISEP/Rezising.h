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

	cout << "Choose the multiplicator factor to modify the height of the image: ";
	cin >> scaleX;
	cout << "Choose the multiplicator factor to modify the width of the image: ";
	cin >> scaleY;

	//imshow("Image not modified", src);

	// Scaling the image by dimension
	resize(src, resized_src, Size(), scaleX, scaleY, INTER_LINEAR);
	return resized_src;
}
