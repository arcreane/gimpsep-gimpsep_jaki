//#include <opencv2/opencv.hpp>
//
//using namespace std;
//using namespace cv;
//
//int main() {
//
//	Mat source;
//
//	source = imread( "van_gogh.jpg", 1);
//	if( !source.data )
//	{
//		printf( " No image data \n " );
//		return -1;
//	}
//
//	// Scaling factors
//	double scaleX = 0.6;
//	double scaleY = 0.6;
//	Mat resized_down;
//
//	// Scaling down the image 0.6 times
//	cv::resize(source, resized_down, Size(), scaleX, scaleY, INTER_LINEAR);
//
//	// Scaling up the image 1.8 times
//	double scaleA = 1.8;
//	double scaleB = 1.8;
//	Mat resized_up;
//
//	resize(source, resized_up, Size(), scaleA, scaleB, INTER_LINEAR);
//
//	imshow("Image", source);
//	imshow("Resized Down image", resized_down);
//	imshow("Resized Up image", resized_up);
//
//	waitKey();
//
//	return 0;
//}