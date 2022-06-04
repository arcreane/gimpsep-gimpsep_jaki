#include <opencv2/opencv.hpp>
#include "CannyEdgeDetection.h"

using namespace std;
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
using namespace cv;

int main(int argc, char** argv)
{
    CannyEdgeDetection(0,0);
    waitKey(0);
    return 0;
}
