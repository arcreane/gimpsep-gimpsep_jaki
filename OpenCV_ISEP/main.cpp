#include <opencv2/opencv.hpp>
#include "opencv2/imgproc.hpp"
#include <opencv2/highgui.hpp>
#include "dilationErosion.h"
#include "Lighten_darken.h"
#include "Rezising.h"
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

    cout << "Home menu \n 1 - Erosion \n 2 - Dilation \n 3 - Lighten or darken \n 4 - Rezising \n 5 - Quit" << endl;
    cin >> numberToChose;

    if (numberToChose == 1)
    {
        Erosion(src, erosion_size);
        waitKey(0);
        cout << " 1 - Go back to the menu \n 2 - Quit" << endl;
        cin >> numberToChose;
        if (numberToChose==1)
        {
            cout << "Home menu \n 1 - Erosion \n 2 - Dilation \n 3 - Lighten or darken \n 4 - Rezising \n 5 - Quit" << endl;
            cin >> numberToChose;
        }

        else if (numberToChose == 2)
        {
            return 0;
        }
    }

    else if (numberToChose == 2)
    {
        Dilation(src, dilation_size);
        waitKey(0);
        cout << " 1 - Go back to the menu \n 2 - Quit" << endl;
        cin >> numberToChose;
        if (numberToChose == 1)
        {
            cout << "Home menu \n 1 - Erosion \n 2 - Dilation \n 3 - Lighten or darken \n 4 - Rezising \n 5 - Quit" << endl;
            cin >> numberToChose;
        }

        else if (numberToChose == 2)
        {
            return 0;
        }
    }

    else if (numberToChose == 3)
    {
        light_dark(src, contrast);
        waitKey(0);
        cout << " 1 - Go back to the menu \n 2 - Quit" << endl;
        cin >> numberToChose;
        if (numberToChose == 1)
        {
            cout << "Home menu \n 1 - Erosion \n 2 - Dilation \n 3 - Lighten or darken \n 4 - Rezising \n 5 - Quit" << endl;
            cin >> numberToChose;
        }

        else if (numberToChose == 2)
        {
            return 0;
        }
    }

    else if (numberToChose == 4)
    {
        rezising(src, scaleX, scaleY);
        waitKey(0);
        cout << " 1 - Go back to the menu \n 2 - Quit" << endl;
        cin >> numberToChose;
        if (numberToChose == 1)
        {
            cout << "Home menu \n 1 - Erosion \n 2 - Dilation \n 3 - Lighten or darken \n 4 - Rezising \n 5 - Quit" << endl;
            cin >> numberToChose;
        }

        else if (numberToChose == 2)
        {
            return 0;
        }
    }

    waitKey(0);
    return 0;
}

