#include <opencv2/opencv.hpp>
#include "opencv2/imgproc.hpp"
#include <opencv2/highgui.hpp>
#include "dilationErosion.h"
#include <iostream>


using namespace std;
using namespace cv;

int numberToChose;

int main(void)
{
	Mat src;
	src = imread("van_gogh.jpg", IMREAD_COLOR); // Load image
    if (src.empty())
    {
        cout << "Could not open or find the image!\n" << endl;
        return -1;
    }

    cout << "Tap 1 for erosion or 2 for dilation" << endl;
    cin >> numberToChose;

    if (numberToChose == 1)
    {
        Erosion(src, erosion_size);
    }
    
    else if (numberToChose==2)
    {
        Dilation(src, dilation_size);
    }
    
    waitKey(0);
    return 0;
}



	

	