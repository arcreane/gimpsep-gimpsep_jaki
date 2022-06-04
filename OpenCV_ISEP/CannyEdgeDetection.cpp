#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
using namespace std;
using namespace cv;



void CannyEdgeDetection(int, void*)
{

    String image;
    Mat src, src_gray;
    Mat dst, detected_edges;
    int lowThreshold = 0;
    const int max_lowThreshold=100;
    const int ratioThreshold = 3;
    const int kernel_size = 3;

    cout << "Select an image: Van Gogh - Wheat Field (enter 'van_gogh') | Landscape (enter 'landscape')\n" << endl;
    cin >> image;
    if (image == "van_gogh") {
        src = imread("van_gogh.jpg", IMREAD_COLOR);
    }
    else if (image == "landscape") {
        src = imread("landscape.jpg", IMREAD_COLOR);
    }
    else {
        cout << "Veuillez insérer un nom d'image valable" << endl;
    }
    if (src.empty())
    {
        std::cout << "Could not open or find the image!\n" << std::endl;
    }

    cout << "Select the threshold between 0 and 100\n" << endl;
    cin >> lowThreshold;

    dst.create(src.size(), src.type());
    cvtColor(src, src_gray, COLOR_BGR2GRAY);
    namedWindow("Canny Edge Detection", WINDOW_NORMAL);
    //createTrackbar("Min Threshold:", "Canny Edge Detection", &lowThreshold, max_lowThreshold, CannyEdgeDetection);


    //Calling function
    blur(src_gray, detected_edges, Size(3, 3));
    Canny(detected_edges, detected_edges, lowThreshold, lowThreshold * ratioThreshold, kernel_size);
    dst = Scalar::all(0);
    src.copyTo(dst, detected_edges);
    imshow("Canny Edge Detection", dst);
}