#pragma once

#ifdef __APPLE__
// For XCode only: New C++ terminal project. Build phases->Compile with libraries: add OpenGL and GLUT
// Import this whole code into a new C++ file (main.cpp, for example). Then run.
// Reference: https://en.wikibooks.org/wiki/OpenGL_Programming/Installation/Mac
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#endif
#ifdef _WIN32
// For VS on Windows only: Download CG_Demo.zip. UNZIP FIRST. Double click on CG_Demo/CG_Demo.sln
// Run
#include "freeglut.h"
#endif
#ifdef __unix__
// For Linux users only: g++ CG_Demo.cpp -lglut -lGL -o CG_Demo
// ./CG_Demo
// Reference: https://www.linuxjournal.com/content/introduction-opengl-programming
#include "GL/freeglut.h"
#include "GL/gl.h"
#endif

#include <stdio.h>
#include <math.h>
#include "block.h"
#include <string>
#define PARTS 19

#ifndef __ROBOT
#define __ROBOT

class Robot{
public:
    Robot();
    ~Robot(); // this free the memory when im done with the class


    void draw();
    void update();
    void startAnimation();
    void returnAnimation();

    enum ROBOT_PARTS{
      HEAD, NECK, CAJA, CHEST, HIPS, RLEG, RANKLE, RFOOT,LLEG, LANKLE, LFOOT,LSHOULDER, LARM,  LFOREARM,LHAND, RSHOULDER, RARM, RHAND,RFOREARM
    };

    Block* parts[PARTS];
    float rotations[PARTS][4];
    float positions[PARTS][3];
    //GLMmodel* objects[PARTS];
   char* objects[PARTS];
    bool diegoOEli;
    bool showBox; 
    float angleTranslation[PARTS]; 

};

#endif
