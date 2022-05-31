#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

Mat src, erosion_dst, dilation_dst;
int erosion_elem = 0;
int erosion_size;
int dilation_elem = 0;
int dilation_size;
//int const max_elem = 2;
//int const max_kernel_size = 21;

Mat Erosion(Mat src,int erosion_size)
{
    int erosion_type = MORPH_ELLIPSE; 
    //int erosion_type = MORPH_CROSS;
    //erosion_type = MORPH_RECT;
    cout << "enter a number for erosion";
    cin >> erosion_size;
    Mat element = getStructuringElement(erosion_type,
        Size(2 * erosion_size + 1, 2 * erosion_size + 1),
        Point(erosion_size, erosion_size));
    namedWindow("Erosion", WINDOW_AUTOSIZE);
    erode(src, erosion_dst, element);
    imshow("Erosion", erosion_dst);
    return erosion_dst;
}

Mat Dilation(Mat src,int dilation_size)
{
    int dilation_type = MORPH_ELLIPSE; 
    //int dilation_type = MORPH_CROSS;
    //int dilation_type =MORPH_RECT;
    cout << "enter a number for dilation";
    cin >> dilation_size;
    Mat element = getStructuringElement(dilation_type,
        Size(2 * dilation_size + 1, 2 * dilation_size + 1),
        Point(dilation_size, dilation_size));
    namedWindow("Dilation", WINDOW_AUTOSIZE);
    moveWindow("Dilation", src.cols, 0);
    dilate(src, dilation_dst, element);
    imshow("Dilation", dilation_dst);
    return dilation_dst;
}