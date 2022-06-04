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
	Mat src;
    int numberToChose = 0;
    String image, confirm;

    cout << "Select an image: Van Gogh - Wheat Field (enter 'van_gogh') | Some objects (enter 'objects')\n" << endl;
    cin >> image;
    if (image == "van_gogh") {
        src = imread("van_gogh.jpg", IMREAD_COLOR);
    }
    else if (image == "objects") {
        src = imread("objects.jpg", IMREAD_COLOR);
    }
    else {
        cout << "Veuillez insérer un nom d'image valable" << endl;
    }
    if (src.empty())
    {
        cout << "Could not open or find the image!\n" << endl;
        return -1;
    }
    
    do{
        Mat newImg;
        cout << "Home menu \n 1 - Erosion \n 2 - Dilation \n 3 - Lighten or darken \n 4 - Rezising \n 5 - Canny Edge Detecting \n 6 - Stiching another image \n 0 - Quit" << endl;
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
        cout << "Do you want to continue using this image (yes) or start from scratch (no) ?" << endl;
        cin >> confirm;
        if (confirm == "yes") {
            src = newImg;
        }
        waitKey(0);
    } while (numberToChose != 0);

    return 0;
}

