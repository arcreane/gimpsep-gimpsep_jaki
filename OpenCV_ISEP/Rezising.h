#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;



Mat resized_src;

// Scaling factors
double scaleX;
double scaleY;

Mat rezising(Mat src, double scaleX, double scaleY)
{

	cout << "Tape a dimension";
	cin >> scaleX;
	cout << "Tape another dimension";
	cin >> scaleY;

	// Scaling the image by dimension
	cv::resize(src, resized_src, Size(), scaleX, scaleY, INTER_LINEAR);

	imshow("Rezised image", resized_src);

	waitKey();
	return resized_src;
}
