#include "robot.h"
#include <string>

Robot::Robot(){ // like init
    
    
    // POSITION definition
    // position related to neck
    positions[HEAD][0] = 331.145f;
    positions[HEAD][1] = 47.64f;
    positions[HEAD][2] = -7.354f;
    
    // position related to chest
    positions[NECK][0] = 424.206f;
    positions[NECK][1] = -14.441f;
    positions[NECK][2] = -8.946f;
    
    // position related to body
    positions[CHEST][0] = 188.073f;
    positions[CHEST][1] = 82.91f;
    positions[CHEST][2] = -9.728f;
    
    //core of robot
    positions[BODY][0] =  188.073f;
    positions[BODY][1] =  82.91f;
    positions[BODY][2] =  -9.728f;
   
    // position related to body
    positions[HIPS][0] =  33.889f;
    positions[HIPS][1] =  85.204f;
    positions[HIPS][2] =  19.123f;
   
    // position related to hips
    positions[RLEG][0] =  -378.681f;
    positions[RLEG][1] =  -55.798f;
    positions[RLEG][2] =  -135.853f;
    
    positions[LLEG][0] = -376.661f;
    positions[LLEG][1] = -54.027f;
    positions[LLEG][2] = 133.391f;
    
    // position related to Leg
    positions[RANKLE][0] = 4.006f;
    positions[RANKLE][1] = -31.464f;
    positions[RANKLE][2] = 30.687f;
    
    positions[LANKLE][0] =  -4.153f;
    positions[LANKLE][1] =  -34.278f;
    positions[LANKLE][2] =  -56.371f;
    
    // position related to ankle
    positions[RFOOT][0] = 207.783f;
    positions[RFOOT][1] = -3.06f;
    positions[RFOOT][2] = -88.958f;
    
    positions[LFOOT][0] =  165.043f;
    positions[LFOOT][1] =  -46.64f;
    positions[LFOOT][2] =  60.232f;
    
    // position related to chest
    positions[RSHOULDER][0] = -64.203f;
    positions[RSHOULDER][1] = -50.497f;
    positions[RSHOULDER][2] = 113.584f;
    
    positions[LSHOULDER][0] =  -63.934f;
    positions[LSHOULDER][1] =  -46.321f;
    positions[LSHOULDER][2] =  -118.689f;
    
    // position related to shoulder
    positions[RARM][0] = 375.432f;
    positions[RARM][1] = -91.858f;
    positions[RARM][2] = 49.787f;
    
    positions[LARM][0] = 369.307f;
    positions[LARM][1] = -81.868f;
    positions[LARM][2] = -57.382f;
    
    // position related to arm
    positions[RFOREARM][0] = 275.748f;
    positions[RFOREARM][1] = 17.144f;
    positions[RFOREARM][2] = 37.581f;
    
    positions[LFOREARM][0] = 283.834f;
    positions[LFOREARM][1] =  25.377f;
    positions[LFOREARM][2] =  -70.291f;

    // position relates to forearm
    positions[RHAND][0] = 357.254f;
    positions[RHAND][1] = 2.17f;
    positions[RHAND][2] = -66.176f;
    
    positions[LHAND][0] = 339.352f;
    positions[LHAND][1] = -4.886f;
    positions[LHAND][2] = 49.138f;
    
    
    // define initial rotations  // angle x y z
    rotations[HIPS][0] =      0;
    rotations[HIPS][1] =      1;
    rotations[HIPS][2] =      0;
    rotations[HIPS][3] =      0;
    
    rotations[BODY][0] =      0;
    rotations[BODY][1] =      1;
    rotations[BODY][2] =      0;
    rotations[BODY][3] =      0;
    
    rotations[CHEST][0] =     0;
    rotations[CHEST][1] =     1;
    rotations[CHEST][2] =     0;
    rotations[CHEST][3] =     0;
    
    rotations[NECK][0] =      0;
    rotations[NECK][1] =      1;
    rotations[NECK][2] =      0;
    rotations[NECK][3] =      0;
    
    rotations[HEAD][0] =      0;
    rotations[HEAD][1] =      1;
    rotations[HEAD][2] =      0;
    rotations[HEAD][3] =      0;
    
    rotations[RLEG][0] =      0;
    rotations[RLEG][1] =      1;
    rotations[RLEG][2] =      0;
    rotations[RLEG][3] =      0;
    rotations[LLEG][0] =      0;
    rotations[LLEG][1] =      1;
    rotations[LLEG][2] =      0;
    rotations[LLEG][3] =      0;
    
    rotations[RANKLE][0] =    0;
    rotations[RANKLE][1] =    1;
    rotations[RANKLE][2] =    0;
    rotations[RANKLE][3] =    0;
    rotations[LANKLE][0] =    0;
    rotations[LANKLE][1] =    1;
    rotations[LANKLE][2] =    0;
    rotations[LANKLE][3] =    0;
    
    rotations[RFOOT][0] =     0;
    rotations[RFOOT][1] =     1;
    rotations[RFOOT][2] =     0;
    rotations[RFOOT][3] =     0;
    rotations[LFOOT][0] =     0;
    rotations[LFOOT][1] =     1;
    rotations[LFOOT][2] =     0;
    rotations[LFOOT][3] =     0;
    
    rotations[RSHOULDER][0] = 0;
    rotations[RSHOULDER][1] = 1;
    rotations[RSHOULDER][2] = 0;
    rotations[RSHOULDER][3] = 0;
    rotations[LSHOULDER][0] = 0;
    rotations[LSHOULDER][1] = 1;
    rotations[LSHOULDER][2] = 0;
    rotations[LSHOULDER][3] = 0;
    
    rotations[RFOREARM][0] =  0;
    rotations[RFOREARM][1] =  1;
    rotations[RFOREARM][2] =  0;
    rotations[RFOREARM][3] =  0;
    rotations[LFOREARM][0] =  0;
    rotations[LFOREARM][1] =  1;
    rotations[LFOREARM][2] =  0;
    rotations[LFOREARM][3] =  0;
    
    rotations[RARM][0] =      0;
    rotations[RARM][1] =      1;
    rotations[RARM][2] =      0;
    rotations[RARM][3] =      0;
    rotations[LARM][0] =      0;
    rotations[LARM][1] =      1;
    rotations[LARM][2] =      0;
    rotations[LARM][3] =      0;
    
    rotations[RHAND][0] =     0;
    rotations[RHAND][1] =     1;
    rotations[RHAND][2] =     0;
    rotations[RHAND][3] =     0;
    rotations[LHAND][0] =     0;
    rotations[LHAND][1] =     1;
    rotations[LHAND][2] =     0;
    rotations[LHAND][3] =     0;
    
    objectName = "/Users/Intern/Desktop/Finalgraficas/Optimus-Prime/Optimus-Prime/assets/Head.obj";
    /*objects[NECK] = glmReadOBJ("/Users/Intern/Desktop/Finalgraficas/Optimus-Prime/Optimus-Prime/assets/Neck.obj");
    objects[HIPS] = glmReadOBJ("/Users/Intern/Desktop/Finalgraficas/Optimus-Prime/Optimus-Prime/assets/Hips.obj");
    objects[RLEG] = glmReadOBJ("/Users/Intern/Desktop/Finalgraficas/Optimus-Prime/Optimus-Prime/assets/RLeg.obj");
    objects[RANKLE] = glmReadOBJ("/Users/Intern/Desktop/Finalgraficas/Optimus-Prime/Optimus-Prime/assets/RAnkle.obj");
    objects[RFOOT] = glmReadOBJ("/Users/Intern/Desktop/Finalgraficas/Optimus-Prime/Optimus-Prime/assets/RFoot.obj");
    objects[RSHOULDER] = glmReadOBJ("/Users/Intern/Desktop/Finalgraficas/Optimus-Prime/Optimus-Prime/assets/RShoulder.obj");
    objects[RARM] = glmReadOBJ("/Users/Intern/Desktop/Finalgraficas/Optimus-Prime/Optimus-Prime/assets/RArm.obj");
    objects[RHAND] = glmReadOBJ("/Users/Intern/Desktop/Finalgraficas/Optimus-Prime/Optimus-Prime/assets/RHand.obj");
    objects[LSHOULDER] = glmReadOBJ("/Users/Intern/Desktop/Finalgraficas/Optimus-Prime/Optimus-Prime/assets/LShoulder.obj");
    objects[LARM] = glmReadOBJ("/Users/Intern/Desktop/Finalgraficas/Optimus-Prime/Optimus-Prime/assets/LArm.obj");
    objects[LHAND] = glmReadOBJ("/Users/Intern/Desktop/Finalgraficas/Optimus-Prime/Optimus-Prime/assets/LHand.obj");
    objects[LLEG] = glmReadOBJ("/Users/Intern/Desktop/Finalgraficas/Optimus-Prime/Optimus-Prime/assets/LLeg.obj");
    objects[LANKLE] = glmReadOBJ("/Users/Intern/Desktop/Finalgraficas/Optimus-Prime/Optimus-Prime/assets/LAnkle.obj");
    objects[LFOOT] = glmReadOBJ("/Users/Intern/Desktop/Finalgraficas/Optimus-Prime/Optimus-Prime/assets/LFoot.obj");
    objects[CHEST] = glmReadOBJ("/Users/Intern/Desktop/Finalgraficas/Optimus-Prime/Optimus-Prime/assets/Chest.obj");
    objects[RFOREARM] = glmReadOBJ("/Users/Intern/Desktop/Finalgraficas/Optimus-Prime/Optimus-Prime/assets/RForearm.obj");
    objects[LFOREARM] = glmReadOBJ("/Users/Intern/Desktop/Finalgraficas/Optimus-Prime/Optimus-Prime/assets/LForearm.obj");*/
   
    parts[HEAD] = new Block(positions[HEAD],rotations[HEAD],objectName);
    /*parts[NECK] = new Block(positions[NECK],rotations[NECK],objects[NECK]);
    parts[HIPS] = new Block(positions[HIPS],rotations[HIPS],objects[HIPS]);
    parts[BODY] = new Block(positions[BODY],rotations[BODY],objects[BODY]);
    parts[RLEG] = new Block(positions[RLEG],rotations[RLEG],objects[RLEG]);
    parts[RANKLE] = new Block(positions[RANKLE],rotations[RANKLE],objects[RANKLE]);
    parts[RFOOT] = new Block(positions[RFOOT],rotations[RFOOT],objects[RFOOT]);
    parts[RSHOULDER] = new Block(positions[RSHOULDER],rotations[RSHOULDER]);
    parts[RARM] = new Block(positions[RARM],rotations[RARM]);
    parts[RHAND] = new Block(positions[RHAND],rotations[RHAND]);
    parts[LSHOULDER] = new Block(positions[LSHOULDER],rotations[LSHOULDER]);
    parts[LARM] = new Block(positions[LARM],rotations[LARM]);
    parts[LHAND] = new Block(positions[LHAND],rotations[LHAND]);
    parts[LLEG] = new Block(positions[LLEG],rotations[LLEG]);
    parts[LANKLE] = new Block(positions[LANKLE],rotations[LANKLE]);
    parts[LFOOT] = new Block(positions[LFOOT],rotations[LFOOT]);
    parts[CHEST] = new Block(positions[CHEST],rotations[CHEST]);
    parts[RFOREARM] = new Block(positions[RFOREARM],rotations[RFOREARM]);
    parts[LFOREARM] = new Block(positions[LFOREARM],rotations[LFOREARM]);*/
    
    
    
    
    
}

Robot::~Robot(){
    
}

void Robot::draw(){ // display()

    /*parts[BODY]->draw(rotations[BODY]);
    parts[HIPS]->draw(rotations[HIPS]);
    parts[RLEG]->draw(rotations[RLEG]);
    parts[RANKLE]->draw(rotations[RANKLE]);
    parts[RFOOT]->draw(rotations[RFOOT]);
    parts[LLEG]->draw(rotations[LLEG]);
    parts[LANKLE]->draw(rotations[LANKLE]);
    parts[LFOOT]->draw(rotations[LFOOT]);
    parts[CHEST]->draw(rotations[CHEST]);
    parts[RSHOULDER]->draw(rotations[RSHOULDER]);
    parts[RARM]->draw(rotations[RARM]);
    parts[RFOREARM]->draw(rotations[RFOREARM]);
    parts[RHAND]->draw(rotations[RHAND]);
    parts[LSHOULDER]->draw(rotations[LSHOULDER]);
    parts[LARM]->draw(rotations[LARM]);
    parts[LFOREARM]->draw(rotations[LFOREARM]);
    parts[LHAND]->draw(rotations[LHAND]);
    parts[NECK]->draw(rotations[NECK]);*/
    parts[HEAD]->draw(rotations[HEAD]);

}

void Robot::update(){ // update
    
}

