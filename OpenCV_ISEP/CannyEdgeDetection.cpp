//#include <opencv2/opencv.hpp>
//#include "CannyEdgeDetection.h"
//
//using namespace std;
//using namespace cv;
//
//Mat src, src_gray;
//Mat dst, detected_edges;
//int lowThreshold = 0;
//const int max_lowThreshold = 100;
//const int ration = 3;
//const int kernel_size = 3;
//const char* window_name = "Edge Map";
//
//static void CannyThreshold(int, void*)
//{
//    blur(src_gray, detected_edges, Size(3, 3));
//    Canny(detected_edges, detected_edges, lowThreshold, lowThreshold * ration, kernel_size);
//    dst = Scalar::all(0);
//    src.copyTo(dst, detected_edges);
//    imshow(window_name, dst);
//}
//int main(int argc, char** argv) {
//    //CommandLineParser parser(argc, argv, "{@input | fruits.jpg | input image}");
//    src = imread("van_gogh.jpg", IMREAD_COLOR); // Load an image
//    if (src.empty())
//    {
//        std::cout << "Could not open or find the image!\n" << std::endl;
//        std::cout << "Usage: " << argv[0] << " <Input image>" << std::endl;
//        return -1;
//    }
//    dst.create(src.size(), src.type());
//    cvtColor(src, src_gray, COLOR_BGR2GRAY);
//    namedWindow(window_name, WINDOW_AUTOSIZE);
//    createTrackbar("Min Threshold:", window_name, &lowThreshold, max_lowThreshold, CannyThreshold);
//    CannyThreshold(0, 0);
//    waitKey(0);
//    return 0;
//
//}