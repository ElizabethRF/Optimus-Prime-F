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
#include <string>
#define PARTS 16

#ifndef __BLOCK
#define __BLOCK

#include "glm.h"

class Block{
public:
    Block(float positions[3],  float rotation[4], std::string objectName);
    ~Block(); // this free the memory when im done with the class

    void draw(float rotation[4]);
    void update();
    float position[3];
    float rotation[4];
    std::string objectName;
    

    
};

#endif
