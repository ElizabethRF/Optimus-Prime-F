#include "robot.h"
#include <string>

Robot::Robot(){ // like init

    angleTranslation[HEAD] = 0;
    angleTranslation[RLEG] = 0;
    angleTranslation[RFOREARM] = 0;
    angleTranslation[LARM] = 0;
    angleTranslation[RARM] = 0;
    diegoOEli = true; //true = eli
    showBox = true;
    // POSITION definition
    // position caja
    positions[CAJA][0] = 0;
    positions[CAJA][1] = 141.624f;
    positions[CAJA][2] = 0;

    // position related to neck
    positions[HEAD][0] = -45.798;//214.538f;  //  -45.798;//
    positions[HEAD][1] = 18.076;//134.618f;  //  18.076;//
    positions[HEAD][2] = 1.25;//-2.139f;   //  1.25;//
  
    // position related to chest
    positions[NECK][0] = -21.684;//260.336f;  //  -21.684;//
    positions[NECK][1] = 12.92;//116.542f;  //  12.92;//
    positions[NECK][2] = 0.084;//-3.389f;   //  0.084;//

    // position related to body
    positions[CHEST][0] = 282.02f;
    positions[CHEST][1] = 103.622f;
    positions[CHEST][2] = -3.473f;



    // position related to body
    positions[HIPS][0] = -29.739f  ; //252.281f;
    positions[HIPS][1] = -131.748f ;  //-28.126f;
    positions[HIPS][2] =    0.252f ;  //-3.221f;

    // position related to hips
    positions[RLEG][0] = -62.881f;// 189.4f;
    positions[RLEG][1] = -21.358f;// -49.484f;
    positions[RLEG][2] = 80.15f;// 76.929f;

    positions[LLEG][0] = -442.319f;//-90.038f;
    positions[LLEG][1] = -20.896f;//-49.022f;
    positions[LLEG][2] = -80.119f;//-83.42f;

    // position related to Leg
    positions[RANKLE][0] = -201.594f;//-12.194f;
    positions[RANKLE][1] = -28.101f;//-77.585f;
    positions[RANKLE][2] = 36.488f;//113.417f;

    positions[LANKLE][0] = 180.092f ;//-9.946f;
    positions[LANKLE][1] =  -17.616f;//-66.638f;
    positions[LANKLE][2] =  -27.339f;//-110.759f;

    // position related to ankle
    positions[RFOOT][0] = -159.893f;//-172.087f;
    positions[RFOOT][1] = 3.054f;//-74.531f;
    positions[RFOOT][2] = -4.432f;//108.985f;

    positions[LFOOT][0] = -162.259f ;//-172.205f;
    positions[LFOOT][1] = -6.637 ; //-73.275f;
    positions[LFOOT][2] = -4.188 ;// -114.947f;

    // position related to chest
    positions[RSHOULDER][0] = -10.253f;//271.767f;
    positions[RSHOULDER][1] = 19.474f;//123.096f;
    positions[RSHOULDER][2] = 128.899f;//125.426f;

    positions[LSHOULDER][0] = -10.098f;// 271.922f;
    positions[LSHOULDER][1] = 19.54f;// 123.162f;
    positions[LSHOULDER][2] = -127.975f;// -131.348f;

    // position related to shoulder
    positions[RARM][0] = 75.663f;//206.357f;
    positions[RARM][1] = 94.961f;//8.661f;
    positions[RARM][2] = -150.377f;//146.904f;

    positions[LARM][0] = 74.885f;//207.135f;
    positions[LARM][1] = 99.062f;//4.56f;
    positions[LARM][2] = 156.057f;//-159.53f;

    // position related to arm
    positions[RFOREARM][0] = -33.118f;//248.833f;
    positions[RFOREARM][1] = -87.03f;//16.592f;
    positions[RFOREARM][2] = 141.828f;//138.355f;

    positions[LFOREARM][0] = -34.547f;// 247.473f;
    positions[LFOREARM][1] = -85.338f;// 18.284f;
    positions[LFOREARM][2] = -142.004f;// -145.477f;

    // position relates to forearm
    positions[RHAND][0] = -209.013f;//73.007f;
    positions[RHAND][1] = -106.287f;//-2.665f;
    positions[RHAND][2] = 129.371;//125.898f;

    positions[LHAND][0] = -199.055f;//82.965f;
    positions[LHAND][1] = -105.955f;//-2.333f;
    positions[LHAND][2] = -139.475f;//-42.948f;


    // define initial rotations  // angle x y z
    rotations[CAJA][0] =      0;
    rotations[CAJA][1] =      0;
    rotations[CAJA][2] =      0;
    rotations[CAJA][3] =      0;

    rotations[HIPS][0] =      0;
    rotations[HIPS][1] =      0;
    rotations[HIPS][2] =      0;
    rotations[HIPS][3] =      0;

    rotations[CHEST][0] =     0;
    rotations[CHEST][1] =     0;
    rotations[CHEST][2] =     0;
    rotations[CHEST][3] =     0;

    rotations[NECK][0] =      0;
    rotations[NECK][1] =      0;
    rotations[NECK][2] =      0;
    rotations[NECK][3] =      0;

    rotations[HEAD][0] =      angleTranslation[HEAD];
    rotations[HEAD][1] =      0;
    rotations[HEAD][2] =      0;
    rotations[HEAD][3] =      1;

    rotations[RLEG][0] =      0;
    rotations[RLEG][1] =      0;
    rotations[RLEG][2] =      0;
    rotations[RLEG][3] =      0;
    rotations[LLEG][0] =      0;
    rotations[LLEG][1] =      0;
    rotations[LLEG][2] =      0;
    rotations[LLEG][3] =      0;

    rotations[RANKLE][0] =    0;
    rotations[RANKLE][1] =    0;
    rotations[RANKLE][2] =    0;
    rotations[RANKLE][3] =    0;
    rotations[LANKLE][0] =    0;
    rotations[LANKLE][1] =    0;
    rotations[LANKLE][2] =    0;
    rotations[LANKLE][3] =    0;

    rotations[RFOOT][0] =     0;
    rotations[RFOOT][1] =     0;
    rotations[RFOOT][2] =     0;
    rotations[RFOOT][3] =     0;
    rotations[LFOOT][0] =     0;
    rotations[LFOOT][1] =     0;
    rotations[LFOOT][2] =     0;
    rotations[LFOOT][3] =     0;

    rotations[RSHOULDER][0] = 0;
    rotations[RSHOULDER][1] = 0;
    rotations[RSHOULDER][2] = 0;
    rotations[RSHOULDER][3] = 0;
    rotations[LSHOULDER][0] = 0;
    rotations[LSHOULDER][1] = 0;
    rotations[LSHOULDER][2] = 0;
    rotations[LSHOULDER][3] = 0;

    rotations[RFOREARM][0] =  0;
    rotations[RFOREARM][1] =  0;
    rotations[RFOREARM][2] =  0;
    rotations[RFOREARM][3] =  0;
    rotations[LFOREARM][0] =  0;
    rotations[LFOREARM][1] =  0;
    rotations[LFOREARM][2] =  0;
    rotations[LFOREARM][3] =  0;

    rotations[RARM][0] =      0;
    rotations[RARM][1] =      0;
    rotations[RARM][2] =      0;
    rotations[RARM][3] =      0;
    rotations[LARM][0] =      0;
    rotations[LARM][1] =      0;
    rotations[LARM][2] =      0;
    rotations[LARM][3] =      0;

    rotations[RHAND][0] =     0;
    rotations[RHAND][1] =     0;
    rotations[RHAND][2] =     0;
    rotations[RHAND][3] =     0;
    rotations[LHAND][0] =     0;
    rotations[LHAND][1] =     0;
    rotations[LHAND][2] =     0;
    rotations[LHAND][3] =     0;

    if(!diegoOEli){
    objects[HEAD] = "/home/diegogplata/Desktop/Optimus-Prime-F/assets/Head.obj";
    objects[NECK] ="/home/diegogplata/Desktop/Optimus-Prime-F/assets/Neck.obj";
    objects[HIPS] = "/home/diegogplata/Desktop/Optimus-Prime-F/assets/Hip.obj";
    objects[RLEG] = "/home/diegogplata/Desktop/Optimus-Prime-F/assets/RLeg.obj";
    objects[RANKLE] = "/home/diegogplata/Desktop/Optimus-Prime-F/assets/RAnkle.obj";
    objects[RFOOT] = "/home/diegogplata/Desktop/Optimus-Prime-F/assets/RFoot.obj";
    objects[RSHOULDER] = "/home/diegogplata/Desktop/Optimus-Prime-F/assets/RShoulder.obj";
    objects[RARM] = "/home/diegogplata/Desktop/Optimus-Prime-F/assets/RArm.obj";
    objects[RHAND] = "/home/diegogplata/Desktop/Optimus-Prime-F/assets/RHand.obj";
    objects[LSHOULDER] = "/home/diegogplata/Desktop/Optimus-Prime-F/assets/LShoulder.obj";
    objects[LARM] = "/home/diegogplata/Desktop/Optimus-Prime-F/assets/LArm.obj";
    objects[LHAND] = "/home/diegogplata/Desktop/Optimus-Prime-F/assets/LHand.obj";
    objects[LLEG] = "/home/diegogplata/Desktop/Optimus-Prime-F/assets/LLeg.obj";
    objects[LANKLE] = "/home/diegogplata/Desktop/Optimus-Prime-F/assets/LAnkle.obj";
    objects[LFOOT] = "/home/diegogplata/Desktop/Optimus-Prime-F/assets/LFoot.obj";
    objects[CHEST] = "/home/diegogplata/Desktop/Optimus-Prime-F/assets/Chest.obj";
    objects[RFOREARM] = "/home/diegogplata/Desktop/Optimus-Prime-F/assets/RForearm.obj";
    objects[LFOREARM] = "/home/diegogplata/Desktop/Optimus-Prime-F/assets/LForearm.obj";
    objects[CAJA] = "/home/diegogplata/Desktop/Optimus-Prime-F/assets/Caja.obj";
    }else{
        objects[HEAD] = "/Users/Intern/Desktop/Finalgraficas/Optimus-Prime/Optimus-Prime/assets/Head.obj";
        objects[NECK] ="/Users/Intern/Desktop/Finalgraficas/Optimus-Prime/Optimus-Prime/assets/Neck.obj";
        objects[HIPS] = "/Users/Intern/Desktop/Finalgraficas/Optimus-Prime/Optimus-Prime/assets/Hip.obj";
        objects[RLEG] = "/Users/Intern/Desktop/Finalgraficas/Optimus-Prime/Optimus-Prime/assets/RLeg.obj";
        objects[RANKLE] = "/Users/Intern/Desktop/Finalgraficas/Optimus-Prime/Optimus-Prime/assets/RAnkle.obj";
        objects[RFOOT] = "/Users/Intern/Desktop/Finalgraficas/Optimus-Prime/Optimus-Prime/assets/RFoot.obj";
        objects[RSHOULDER] = "/Users/Intern/Desktop/Finalgraficas/Optimus-Prime/Optimus-Prime/assets/RShoulder.obj";
        objects[RARM] = "/Users/Intern/Desktop/Finalgraficas/Optimus-Prime/Optimus-Prime/assets/RArm.obj";
        objects[RHAND] = "/Users/Intern/Desktop/Finalgraficas/Optimus-Prime/Optimus-Prime/assets/RHand.obj";
        objects[LSHOULDER] = "/Users/Intern/Desktop/Finalgraficas/Optimus-Prime/Optimus-Prime/assets/LShoulder.obj";
        objects[LARM] = "/Users/Intern/Desktop/Finalgraficas/Optimus-Prime/Optimus-Prime/assets/LArm.obj";
        objects[LHAND] = "/Users/Intern/Desktop/Finalgraficas/Optimus-Prime/Optimus-Prime/assets/LHand.obj";
        objects[LLEG] = "/Users/Intern/Desktop/Finalgraficas/Optimus-Prime/Optimus-Prime/assets/LLeg.obj";
        objects[LANKLE] = "/Users/Intern/Desktop/Finalgraficas/Optimus-Prime/Optimus-Prime/assets/LAnkle.obj";
        objects[LFOOT] = "/Users/Intern/Desktop/Finalgraficas/Optimus-Prime/Optimus-Prime/assets/LFoot.obj";
        objects[CHEST] = "/Users/Intern/Desktop/Finalgraficas/Optimus-Prime/Optimus-Prime/assets/Chest.obj";
        objects[RFOREARM] = "/Users/Intern/Desktop/Finalgraficas/Optimus-Prime/Optimus-Prime/assets/RForearm.obj";
        objects[LFOREARM] = "/Users/Intern/Desktop/Finalgraficas/Optimus-Prime/Optimus-Prime/assets/LForearm.obj";
        objects[CAJA] = "/Users/Intern/Desktop/Finalgraficas/Optimus-Prime/Optimus-Prime/assets/Caja.obj";
    }

    parts[HEAD] = new Block(positions[HEAD],rotations[HEAD],objects[HEAD]);
    parts[NECK] = new Block(positions[NECK],rotations[NECK],objects[NECK]);
    parts[HIPS] = new Block(positions[HIPS],rotations[HIPS],objects[HIPS]);
    parts[RLEG] = new Block(positions[RLEG],rotations[RLEG],objects[RLEG]);
    parts[RANKLE] = new Block(positions[RANKLE],rotations[RANKLE],objects[RANKLE]);
    parts[RFOOT] = new Block(positions[RFOOT],rotations[RFOOT],objects[RFOOT]);
    parts[RSHOULDER] = new Block(positions[RSHOULDER],rotations[RSHOULDER],objects[RSHOULDER]);
    parts[RARM] = new Block(positions[RARM],rotations[RARM],objects[RARM]);
    parts[RHAND] = new Block(positions[RHAND],rotations[RHAND],objects[RHAND]);
    parts[LSHOULDER] = new Block(positions[LSHOULDER],rotations[LSHOULDER],objects[LSHOULDER]);
    parts[LARM] = new Block(positions[LARM],rotations[LARM],objects[LARM]);
    parts[LHAND] = new Block(positions[LHAND],rotations[LHAND],objects[LHAND]);
    parts[LLEG] = new Block(positions[LLEG],rotations[LLEG],objects[LLEG]);
    parts[LANKLE] = new Block(positions[LANKLE],rotations[LANKLE],objects[LANKLE]);
    parts[LFOOT] = new Block(positions[LFOOT],rotations[LFOOT],objects[LFOOT]);
    parts[CHEST] = new Block(positions[CHEST],rotations[CHEST],objects[CHEST]);
    parts[RFOREARM] = new Block(positions[RFOREARM],rotations[RFOREARM],objects[RFOREARM]);
    parts[LFOREARM] = new Block(positions[LFOREARM],rotations[LFOREARM],objects[LFOREARM]);
    parts[CAJA] = new Block(positions[CAJA],rotations[CAJA],objects[CAJA]);





}

Robot::~Robot(){

}

void Robot::draw(){ // display()
    glPushMatrix();
   parts[CHEST]->draw(rotations[CHEST]);
    glPushMatrix();
    {
        glRotatef(angleTranslation[HEAD], 0, 0, 1);
        
        parts[NECK]->draw(rotations[NECK]);
        parts[HEAD]->draw(rotations[HEAD]);
    }
    glPopMatrix();
    
    glPushMatrix();
    {
        parts[HIPS]->draw(rotations[HIPS]);
        glPushMatrix();
            glRotatef(angleTranslation[RLEG], 0, 0, 1);
            parts[RLEG]->draw(rotations[RLEG]);
            parts[RANKLE]->draw(rotations[RANKLE]);
            parts[RFOOT]->draw(rotations[RFOOT]);
        glPopMatrix();
        
        glPushMatrix();
            glRotatef(angleTranslation[RLEG], 0, 0, 1);
            parts[LLEG]->draw(rotations[LLEG]);
            parts[LANKLE]->draw(rotations[LANKLE]);
            parts[LFOOT]->draw(rotations[LFOOT]);
        glPopMatrix();
    }
    glPopMatrix();
    
    glPushMatrix();
    {
        glPushMatrix();
        {
            parts[RSHOULDER]->draw(rotations[RSHOULDER]);
            parts[RARM]->draw(rotations[RARM]);
            glRotatef(angleTranslation[RFOREARM], 0, 0, 1);
            parts[RFOREARM]->draw(rotations[RFOREARM]);
            parts[RHAND]->draw(rotations[RHAND]);
        }
        glPopMatrix();
        
        glPushMatrix();
        {
            parts[LSHOULDER]->draw(rotations[LSHOULDER]);
            parts[LARM]->draw(rotations[LARM]);
            glRotatef(angleTranslation[RFOREARM], 0, 0, 1);
            parts[LFOREARM]->draw(rotations[LFOREARM]);
            parts[LHAND]->draw(rotations[LHAND]);
        }
        glPopMatrix();
    }
    glPopMatrix();
    glPopMatrix();
    if(showBox){
        parts[CAJA]->draw(rotations[CAJA]);
    }
}

void Robot::update(){ // update
    
}

void Robot::startAnimation(){
    showBox = false;
    if(angleTranslation[HEAD] > -90){
        angleTranslation[HEAD] = angleTranslation[HEAD] -1;
    }
    
    if(angleTranslation[RLEG] < 90){
        angleTranslation[RLEG] = angleTranslation[RLEG] +1;
    }
    
    if( angleTranslation[RFOREARM] < 90){
           angleTranslation[RFOREARM] = angleTranslation[RFOREARM] +1;
       }
    
}

void Robot::returnAnimation(){
    
    showBox = true;
    if(angleTranslation[HEAD] < 0){
        angleTranslation[HEAD] = angleTranslation[HEAD] +1;
    }
    
    if(angleTranslation[RLEG] > 0){
        angleTranslation[RLEG] = angleTranslation[RLEG] -1;
    }
    
    if( angleTranslation[RFOREARM] > 0){
        angleTranslation[RFOREARM] = angleTranslation[RFOREARM] -1;
    }
    
    


}
