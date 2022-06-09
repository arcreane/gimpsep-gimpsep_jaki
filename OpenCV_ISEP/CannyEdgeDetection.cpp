#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
using namespace std;
using namespace cv;



Mat CannyEdgeDetection(int, void*, Mat src)
{

    Mat src_gray;
    Mat dst, detected_edges;
    int lowThreshold = 0;
    const int max_lowThreshold = 100;
    const int ratioThreshold = 3;
    const int kernel_size = 3;

    cout << "Select the threshold between 0 and 100\n" << endl;
    cin >> lowThreshold;

    dst.create(src.size(), src.type());
    cvtColor(src, src_gray, COLOR_BGR2GRAY);
    namedWindow("Edges Detected image", WINDOW_AUTOSIZE);
    //createTrackbar("Min Threshold:", "Canny Edge Detection", &lowThreshold, max_lowThreshold, CannyEdgeDetection);


    //Calling function
    blur(src_gray, detected_edges, Size(3, 3));
    Canny(detected_edges, detected_edges, lowThreshold, lowThreshold * ratioThreshold, kernel_size);
    dst = Scalar::all(0);
    src.copyTo(dst, detected_edges);
    return dst;
}