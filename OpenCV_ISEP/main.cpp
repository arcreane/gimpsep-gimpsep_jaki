#include <opencv2/opencv.hpp>
#include "opencv2/imgproc.hpp"
#include <opencv2/highgui.hpp>
#include <iostream>

#include "dilationErosion.h"
#include "Lighten_darken.h"
#include "Rezising.h"
#include "CannyEdgeDetection.h"
#include "stitching.h"

; using namespace std;
using namespace cv;

int main(void){
	Mat srcO, src;
    int numberToChose = 0;
    String image, confirm;

    /*cout << "Select an image: Van Gogh - Wheat Field (enter 'van_gogh') | Some objects (enter 'objects') | Happy Fish (enter 'fish') \n" << endl;*/
    cout << "_-_ Select an image:  _-_-_-_-_-_-_-_-_-_-_-_-_-_" << endl;
    cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_" << endl;
    cout << "_-  1 : Van Gogh - Wheat Field                 -_" << endl;
    cout << "_-  2 : 0bjects                                -_" << endl;
    cout << "_-  3 : Happy Fish                             -_" << endl;
    cout << "_-_ Type your choice : -_-_-_-_-_-_-_-_-_-_-_-_-_" << endl;
    cin >> image;
    if (image == "1") {
        srcO = imread("van_gogh.jpg", IMREAD_COLOR);
    }
    else if (image == "2") {
        srcO = imread("objects.jpg", IMREAD_COLOR);
    }
    else if (image == "3") {
        srcO = imread("HappyFish.jpg", IMREAD_COLOR);
    }
    else {
        cout << "Please enter a valid name for your image" << endl;
    }
    if (srcO.empty())
    {
        cout << "Could not open or find the image!\n" << endl;
        return -1;
    }
    src = srcO;
    do{
        Mat newImg;
        /*cout << "Home menu \n 1 - Erosion \n 2 - Dilation \n 3 - Lighten or darken \n 4 - Rezising \n 5 - Canny Edge Detecting \n 6 - Stiching another image \n 0 - Quit" << endl;*/
        cout << "\n_-_ Home Menu  -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_" << endl;
        cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_" << endl;
        cout << "_-  1 : Erosion                                -_" << endl;
        cout << "_-  2 : Dilatation                             -_" << endl;
        cout << "_-  3 : Lighten or darken                      -_" << endl;
        cout << "_-  4 : Resizing                               -_" << endl;
        cout << "_-  5 : Canny Edge Detecting                   -_" << endl;
        cout << "_-  6 : Stiching another image                 -_" << endl;
        cout << "_-  0 : Exit                                   -_" << endl;
        cout << "_-_ Type your choice : -_-_-_-_-_-_-_-_-_-_-_-_-_" << endl;
        cin >> numberToChose;

        if (numberToChose == 1)
        {
            newImg = Erosion(src, erosion_size);
            waitKey(0);
        }

        else if (numberToChose == 2)
        {
            newImg = Dilation(src, dilation_size);
            waitKey(0);
            }

        else if (numberToChose == 3)
        {
            newImg = light_dark(src, contrast);
            waitKey(0);

        }

        else if (numberToChose == 4)
        {
            newImg = rezising(src, scaleX, scaleY);
            imshow("Rezised image", newImg);
            waitKey(0);
        }

        else if (numberToChose == 5)
        {
            newImg = CannyEdgeDetection(0,0, src);
            imshow("Edges Detected image", newImg);            
            waitKey(0);
        }

        /*else if (numberToChose == 6)
        {
            String img;

            cout << "Choose between 'newspaper', 'boat' et 'beach'"; cin >> img;

            Stiching(img);

            
        }*/
        if (numberToChose != 0) {
            cout << "Do you want to continue using this image (yes) or start from scratch (no) ?" << endl;
            cin >> confirm;
            if (confirm == "yes") {
                src = newImg;
            }
            else if(confirm == "no") {
                src = srcO;
            }
            waitKey(0);
        }

    } while (numberToChose != 0);

    return 0;
}

