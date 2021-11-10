#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main( int argc, char** argv )
{
    Mat3b img(100,100, CV_32FC3);
    cv::imshow("image",img);
    for(int i = 0; i < img.cols; i++){
        for(int j = 0; j < img.rows; j++){
            if((rand()%3) != 0){
                img.at<cv::Vec3b>(j,i) = {0,0,0};
            }
            else{
                img.at<cv::Vec3b>(j,i) = {255,255,255};
            }
        }
    }
    while(1){
        bool lines[img.cols][img.rows];
        for(int i = 0; i < img.rows; i++){
            for(int j = 0; j < img.cols; j++){
                bool alive = (img.at<cv::Vec3b>(i,j)[0] == 255);
                bool alive_next = false;
                int life = 0;
                if(i != 0){
                    if(img.at<cv::Vec3b>(i-1,j)[0] == 255){
                        life++;
                    }
                    if(j != 0){
                        if(img.at<cv::Vec3b>(i-1,j-1)[0] == 255){
                            life++;
                        }
                    }
                    if(j != 1080){
                        if(img.at<cv::Vec3b>(i-1,j+1)[0] == 255){
                            life++;
                        }
                    }
                }
                if(i != 1080){
                    if(img.at<cv::Vec3b>(i+1,j)[0] == 255){
                        life++;
                    }
                    if(j != 0){
                        if(img.at<cv::Vec3b>(i+1,j-1)[0] == 255){
                            life++;
                        }
                    }
                    if(j != 1080){
                        if(img.at<cv::Vec3b>(i+1,j+1)[0] == 255){
                            life++;
                        }
                    }
                }
                if(j != 0){
                    if(img.at<cv::Vec3b>(i,j-1)[0] == 255){
                        life++;
                    }
                }
                if(j != 1080){
                    if(img.at<cv::Vec3b>(i,j+1)[0] == 255){
                        life++;
                    }
                }
                if(alive && ((life == 2) || (life == 3))){
                    alive_next = true;
                }
                else if(!alive && (life == 3)){
                    alive_next = true;
                }
                lines[i][j] = alive_next;
                printf("%d::%d -- %d\n",i,j,alive_next);
            }
        }
        for(int i = 0; i < img.rows; i++){
            for(int j = 0; j < img.cols; j++){
                if(lines[i][j]){
                    img.at<cv::Vec3b>(i,j) = {255,255,255};
                }
                else{
                    img.at<cv::Vec3b>(i,j) = {0,0,0};
                }
            }
        }
        cv::imshow("image",img);
        int x = cv::waitKey(42) & 0xFF;
        if(x == 32){
            return 0;
        }
    }
    return EXIT_SUCCESS;
}
