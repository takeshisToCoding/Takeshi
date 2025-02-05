#include "ros/ros.h"
#include "takeshi_tools/TakeshiHardware.h"
#include "takeshi_tools/TakeshiHRI.h"
#include "takeshi_tools/TakeshiManip.h"
#include "takeshi_tools/TakeshiNavigation.h"
#include "takeshi_tools/TakeshiTools.h"
#include "takeshi_tools/TakeshiVision.h"
#include "takeshi_tools/TakeshiTasks.h"
#include "takeshi_tools/TakeshiRepresentation.h"
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
using namespace cv;
bool success=false;
enum state {
        SM_START,
        SM_TRAIN,
        SM_HANDS_DOWN,
        SM_RECOG,
        SM_FIND_PERSON

};

void printState(std::string st);

int main(int argc, char** argv){
        cout << "--------------Test------------" << endl;

        ros::init(argc, argv,"test");
        ros::NodeHandle n;
        ros::Rate loop(30);
        int nextState=SM_START;
        TakeshiVision::setNodeHandle(&n);
         std::string lastRecoSpeech;
    std::string train_name;
    std::vector<vision_msgs::VisionFaceObject> lastRecognizedFaces;
    train_name="train_";
        vision_msgs::VisionFaceObjects vfo;
    std::vector<std::string> validCommandsNames;
    std::vector<std::string> validCommandsDrinks;
    std::vector<std::string> AvailableDrinks;
    std::vector<std::string> aux_drinks;
    std::vector<std::string>::iterator it;
    std::vector<float> obj_position;
    std::vector<vision_msgs::GestureSkeleton> gestures;
    vision_msgs::GestureSkeleton gesture;
    vision_msgs::Skeleton skeletonZero;

    bool findBagLeftSide=false;
    bool findBagRightSide=false; 
    int closestSkl;               
    vision_msgs::Skeletons skl;
    std::vector<std::string> specificGestures;
   
    
    ros::Rate rate(10);





    //names
   

    //OPENPOSES
     specificGestures.push_back("right_hand_rised");
     specificGestures.push_back("left_hand_rised");
     specificGestures.push_back("hand_right_extended");
     specificGestures.push_back("hand_left_extended");
     specificGestures.push_back("drinking_right");
     specificGestures.push_back("drinking_left");
     specificGestures.push_back("both_hands_down");









        int train_count =0;
        int i;
        string  training_name="train_";
        string name="oscar";
        
        while(ros::ok() && !success) {
                switch(nextState)
                {
                case SM_START:


                          cout<<"TRAINING"<< std::endl;  
                          vfo = TakeshiVision::facenetRecognize(train_name + name);
                          ros::Duration(.52).sleep();
                          vfo = TakeshiVision::facenetRecognize(train_name + name);
                          ros::Duration(.52).sleep();
                          vfo = TakeshiVision::facenetRecognize(train_name + name);
                          ros::Duration(.52).sleep();

                        training_name="train_";

                        nextState=SM_RECOG;
                                               
                        break;


                
           


                case SM_RECOG:
                        std::cout << "SM RECOG"<< std::endl;
                        
                        vfo = TakeshiVision::facenetRecognize();
                        if(vfo.recog_faces.size()>0)
                        {  

                            for (i=0;i<vfo.recog_faces.size();i++)
                                {
                            std::cout << "there are "<<vfo.recog_faces.size()<<" faces in view"<<std::endl;
                            std::cout << vfo.recog_faces[i].id << '\n';
                            std::cout << vfo.recog_faces[i].face_centroid << '\n';
                                }
                        }
                        
                        break;







                }

                ros::spinOnce();
                loop.sleep();

        }

}