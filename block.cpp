#include "block.h"

Block::Block(float positions[3],  float rotations[4], GLMmodel objects){ // like init
    position[0] = positions[0];
    position[1] = positions[1];
    position[2] = positions[2]; // x y z
    rotation[0] = rotations[0]; //angle
    rotation[1] = rotations[1]; //x
    rotation[2] = rotations[2]; // y
    rotation[3] = rotations[3]; // z
    object = objects;
    
    
}

Block::~Block(){
    
}

void Block::draw(float rotations[4]){ // display()
    
    glPushMatrix();
        glRotatef(rotation[0], rotation[1], rotation[2], rotation[3]);
        glTranslatef(position[0], position[1], position[2]);
        //glmDraw(object, GLM_MATERIAL);
    glPopMatrix();
    
}

void Block::update(){ // update
    
}
