#include "background.h"


Cube*        cube0;
GLfloat*    mat0_specular;
GLfloat*    mat0_diffuse;
GLfloat*    mat0_shininess;
GLfloat*    light10_position;

Background::Background(){
    
    cube0 = new Cube( 800.0f, true );
    
    glEnable( GL_TEXTURE_2D );

    mat0_specular        = new GLfloat[4];
    mat0_specular[0]    = 1.0f; //<----------------------------------S0r
    mat0_specular[1]    = 1.0f; //<----------------------------------S0g
    mat0_specular[2]    = 1.0f; //<----------------------------------S0b
    mat0_specular[3]    = 1.0f; //<----------------------------------S0a

    mat0_diffuse        = new GLfloat[4];
    mat0_diffuse[0]        = 1.0f; //<----------------------------------D0r
    mat0_diffuse[1]        = 0.0f; //<----------------------------------D0g
    mat0_diffuse[2]        = 0.0f; //<----------------------------------D0b
    mat0_diffuse[3]        = 1.0f; //<----------------------------------D0a

    mat0_shininess        = new GLfloat[1];
    mat0_shininess[0]    = 60.0f;

    light10_position        = new GLfloat[4];
    light10_position[0]    = 1.0f; //<----------------------------------L0x
    light10_position[1]    = 1.0f; //<----------------------------------L0y
    light10_position[2]    = 1.0f; //<----------------------------------L0z
    light10_position[3]    = 0.0f; //<----------------------------------L0w

    glLightfv( GL_LIGHT0, GL_POSITION,  light10_position );
    //glEnable( GL_LIGHTING );
    //glEnable( GL_LIGHT0 );
    //glEnable( GL_DEPTH_TEST );
    
    


    
    
}

Background::~Background(){
    
    
}

void Background::draw(){
    
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glMaterialfv( GL_FRONT,   GL_DIFFUSE,   mat0_diffuse        );
    glMaterialfv( GL_FRONT,  GL_SPECULAR,  mat0_specular    );
    glMaterialfv( GL_FRONT,  GL_SHININESS, mat0_shininess    );
    
    
    glPushMatrix();
        cube0->draw();
    glPopMatrix();
}
