#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;
Mat src, erosion_dst;
int erosion_elem = 0;
int erosion_size = 0;
int const max_elem = 2;
int const max_kernel_size = 21;
void Erosion(int, void*);
int main(int argc, char** argv)
{
    CommandLineParser parser(argc, argv, "{@input | LinuxLogo.jpg | input image}");
    src = imread("van_gogh.jpg", IMREAD_COLOR);
    if (src.empty())
    {
        cout << "Could not open or find the image!\n" << endl;
        cout << "Usage: " << argv[0] << " <Input image>" << endl;
        return -1;
    }
    namedWindow("Erosion Demo", WINDOW_AUTOSIZE);
    createTrackbar("Element:\n 0: Rect \n 1: Cross \n 2: Ellipse", "Erosion Demo",
        &erosion_elem, max_elem,
        Erosion);
    createTrackbar("Kernel size:\n 2n +1", "Erosion Demo",
        &erosion_size, max_kernel_size,
        Erosion);
    Erosion(0, 0);
    waitKey(0);
    return 0;
}
void Erosion(int, void*)
{
    int erosion_type = 0;
    if (erosion_elem == 0) { erosion_type = MORPH_RECT; }
    else if (erosion_elem == 1) { erosion_type = MORPH_CROSS; }
    else if (erosion_elem == 2) { erosion_type = MORPH_ELLIPSE; }
    Mat element = getStructuringElement(erosion_type,
        Size(2 * erosion_size + 1, 2 * erosion_size + 1),
        Point(erosion_size, erosion_size));
    erode(src, erosion_dst, element);
    imshow("Erosion Demo", erosion_dst);
}