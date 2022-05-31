//
//  stitching.cpp
//
//  Created by Juliette Godinot on 24/05/2022.
//

#include <stdio.h>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

Mat pano;

static void Stiching(String img){
    Stitcher::Mode mode = Stitcher::PANORAMA;
    vector<Mat> imgs;
    
    if (img == "newspaper") {
        // Load images
        Mat img1 = imread("newspaper1.jpg");
        Mat img2 = imread("newspaper2.jpg");
        Mat img3 = imread("newspaper3.jpg");
        Mat img4 = imread("newspaper4.jpg");
        
        imgs.push_back(img1);
        imgs.push_back(img2);
        imgs.push_back(img3);
        imgs.push_back(img4);
        
    } else if (img == "hill") {
        // Load images
        Mat img1 = imread("boat1.jpg");
        Mat img2 = imread("boat2.jpg");
        Mat img3 = imread("boat3.jpg");
        Mat img4 = imread("boat4.jpg");
        Mat img5 = imread("boat5.jpg");
        Mat img6 = imread("boat6.jpg");
        
        imgs.push_back(img1);
        imgs.push_back(img2);
        imgs.push_back(img3);
        imgs.push_back(img4);
        imgs.push_back(img5);
        imgs.push_back(img6);
        
    } else if (img == "beach") {
        // Load images
        Mat img1 = imread("beach1.jpg");
        Mat img2 = imread("beach2.jpg");
        
        imgs.push_back(img1);
        imgs.push_back(img2);
    } else {
        std::cout << "Pas d'image";
    }
    
    // Create a Stitcher class object with mode panoroma
    Ptr<Stitcher> stitcher = Stitcher::create(mode);
    // Stiching all the images that are in the image array
    stitcher->stitch(imgs, pano);
    
    /*
    if (status != Stitcher::OK)
        {
            // Check if images could not be stitched
            // status is OK if images are stitched successfully
            cout << "Can't stitch images\n";
            return -1;
        }
    */
    //imshow("Result", pano);

}


