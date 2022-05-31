//
//  main.cpp
//
//  Created by Juliette Godinot on 24/05/2022.
//

#include <iostream>
#include "stitching.cpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    
    String img;
    
    cout << "Choose between 'newspaper', 'boat' et 'beach'"; cin >> img;
    
    Stiching(img);
   
    namedWindow("Result", WINDOW_AUTOSIZE);
    imshow("Result", pano);
    
    waitKey();
    
    return 0;
}
