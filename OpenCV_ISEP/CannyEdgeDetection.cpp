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

    //Creating matrix of same size as the source image
    dst.create(src.size(), src.type());
    //Converting image to greyscale
    cvtColor(src, src_gray, COLOR_BGR2GRAY);
    namedWindow("Edges Detected image", WINDOW_AUTOSIZE);
    //createTrackbar("Min Threshold:", "Canny Edge Detection", &lowThreshold, max_lowThreshold, CannyEdgeDetection);


    //Blurring the image
    blur(src_gray, detected_edges, Size(3, 3));
    //Canny function: the high threshold is set as three times the lower threshold following Canny's recommendation
    //Kernel size is set to 3 (size of the Sobel kernel to be used internally)
    Canny(detected_edges, detected_edges, lowThreshold, lowThreshold * ratioThreshold, kernel_size);
    //Filling a dst image with zeros (so that it is completely black)
    dst = Scalar::all(0);
    //Mapping the area identified as edges on a black bakground
    //We copy the src image onto dst. It will copy the pixels where there is non-zero values.
    //The final dst image will be black everwhere except the detected edges.
    src.copyTo(dst, detected_edges);
    return dst;
}
