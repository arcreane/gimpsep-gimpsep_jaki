//#include "opencv2/imgproc.hpp"
//#include "opencv2/highgui.hpp"
//#include <iostream>
//using namespace std;
//using namespace cv;
//
//Mat src, src_gray;
//Mat dst, detected_edges;
//
//
//
//static void CannyThreshold(int, void*){
//
//    Mat src;
//    int lowThreshold = 0;
//    int max_lowThreshold = 100;
//    const int ratio = 3;
//    const int kernel_size = 3;
//
//
//    
//
//    cout << "Select the minimum threshold (default value is 0)\n" << endl;
//    cin >> lowThreshold;
//    cout << "Select the maximum threshold (default value is 100)\n" << endl;
//    cin >> max_lowThreshold;
//    cout << "Select the kernel size (default value is 3)\n" << endl;
//    cin >> max_lowThreshold;
//
//    if (src.empty())
//    {
//        cout << "Could not open or find the image!\n" << endl;
//    }
//
//    dst.create(src.size(), src.type());
//    cvtColor(src, src_gray, COLOR_BGR2GRAY);
//    
//
//    blur(src_gray, detected_edges, Size(3, 3));
//    Canny(detected_edges, detected_edges, lowThreshold, lowThreshold * ratio, kernel_size);
//    dst = Scalar::all(0);
//    src.copyTo(dst, detected_edges);
//
//    imshow("Canny Edge Detection", dst);
//
//}
//int main(int argc, char** argv)
//{
//    String image;
//    int lowThreshold = 0;
//    int max_lowThreshold = 100;
//
//    cout << "Select an image: Van Gogh - La nuit Etoilée (tapez 'van_gogh')| Mark Zuckerberg (tapez 'mark')\n" << endl;
//    cin >> image;
//    if (image == "van_gogh") {
//        src = imread("van_gogh.jpg", IMREAD_COLOR);
//    }
//    else if (image == "mark") {
//        src = imread("mark.jpg", IMREAD_COLOR);
//    }
//    else {
//        cout << "Veuillez insérer un nom d'image valable" << endl;
//    }
//
//    if (src.empty())
//    {
//        std::cout << "Could not open or find the image!\n" << std::endl;
//
//    }
//    dst.create(src.size(), src.type());
//    cvtColor(src, src_gray, COLOR_BGR2GRAY);
//    namedWindow("Canny Edge Detection", WINDOW_AUTOSIZE);
//    createTrackbar("Min Threshold:", "Canny Edge Detection", &lowThreshold, max_lowThreshold, CannyThreshold);
//    CannyThreshold(0, 0);
//    waitKey(0);
//}