#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main( int argc, char** argv )
{
    Mat3b img(1080,1080, CV_32FC3);
    cv::imshow("image",img);
    cv::Vec3b lines[img.cols][img.rows];
    for(int i = 0; i < img.cols; i++){
        for(int j = 0; j < img.rows; j++){
            if((rand()%2) == 1){
                img.at<cv::Vec3b>(j,i) = {0,0,0};
            }
            else{
                img.at<cv::Vec3b>(j,i) = {255,255,255};
            }
        }
    }
    while(1){
        for(int i = 0; i < img.rows; i++){
            for(int j = 0; j < img.cols; j++){
                if(i > 0){
                    
                }
            }
            cv::imshow("image",img);
            int x = cv::waitKey(42) & 0xFF;
            if(x == 32){
                return 0;
            }
        }
    }
    return EXIT_SUCCESS;
}
