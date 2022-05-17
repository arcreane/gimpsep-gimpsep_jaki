#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(void)
{
    Mat source, M, result;

    // Reading the image
    source = imread("van_gogh.jpg", IMREAD_COLOR);

    Point2f center(source.cols / 2, source.rows / 2);
    double rotationAngle = 30;
    double scale = 1;

    // Getting the matrix which will define the rotation
    M = getRotationMatrix2D(center, rotationAngle, scale);
    // Rotating the source and storing in result
    warpAffine(source, result, M, Size());

    // Create windows for display
    namedWindow("Van Gogh - Original", WINDOW_AUTOSIZE);
    namedWindow("Van Gogh - Rotated", WINDOW_AUTOSIZE);

    // Display images
    imshow("Van Gogh - Original", source);
    imshow("Van Gogh - Rotated", result);
    waitKey(0);

}
