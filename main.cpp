#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
#include<opencv2/aruco.hpp>
#include<opencv2/highgui.hpp>
using namespace cv;
int main()
{
    VideoCapture input;
    input.open(0);
    Ptr<aruco::Dictionary> dictionary= aruco::getPredefinedDictionary(aruco::DICT_6X6_250);
    while (input.grab())
    {
        Mat image,copy;
        input.retrieve(image);
        image.copyTo(copy);
        vector<int> ids;
        vector<vector<Point2f>> corners;
        aruco::detectMarkers(image,dictionary,corners,ids);
        if(ids.size()>0)
        {
            aruco::drawDetectedMarkers(copy,corners,ids);
            for(int i=0;i<corners.size();i++)
            {Mat sum=Mat(corners.at(i).at(0))+Mat(corners.at(i).at(1))+Mat(corners.at(i).at(2))+Mat(corners.at(i).at(3));
            sum=sum/4;
            cout<<sum<<endl<<endl;}
            
        }
        imshow("out",copy);
        
        char key=(char)waitKey();
        if(key==27)
        break;     
    }   
}