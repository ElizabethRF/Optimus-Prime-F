/* Ray Casters
* Samantha González Estrada  A01335690 || Jafet Cuevas Iturbide A01336131
* Elizabeth Rodríguez Fallas A01334353 || Diego González Plata  A01333129
* TC3022. Computer Graphics Course.
* Final project
*/

// Please don't change lines 9-31 (It helps me to grade)
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
#include <iostream>

#include "robot.h"
#include "background.h"
#include "cParticle.h"


Robot* robot;
Background* background;
int NUM_P = 10;
Particle** particles;
float cameraX, cameraY, cameraZ;

int type;
GLfloat*	light0_position;	//<-------------------------------Light 0    - location array
GLfloat*	light0_ambient;		//<-------------------------------Light 0    - ambient array
GLfloat*	light0_specular;	//<-------------------------------Light 0    - diffuse array
GLfloat*	light0_diffuse;		//<-------------------------------Light 0    - specular array
//GLfloat*	global_ambient;

float randBetween(float min, float max){
    return min + (max-min) * (float)rand() / RAND_MAX;
}

void init() // FOR GLUT LOOP
{
    cameraX = 00.0f;
    cameraY = 0.0f;
    cameraZ = 600.0f;
    type = 10;
    robot = new Robot();
    background = new Background();
    //Instatiate particles
    particles = new Particle*[NUM_P](); //Instantiate
    for (int p = 0; p < NUM_P; p++) {
        particles[p] = new Particle();
				//particles starting point
        particles[p]->pos[0] = randBetween(0, 100.0f);
        particles[p]->pos[1] = randBetween(0, 100.0f);
        particles[p]->pos[2] = randBetween(0, 100.0f);

        particles[p] -> oldPos[0] = particles[p] -> pos[0];
        particles[p] -> oldPos[1] = particles[p] -> pos[1];
        particles[p] -> oldPos[2] = particles[p] -> pos[2];

        particles[p] -> mass = randBetween(100,200);
        particles[p] -> radius = particles[p] -> mass / 20.0f;
        particles[p] -> area = 4.0f * M_PI * particles[p] -> radius * particles[p] -> radius;

        particles[p] -> diffuse[0] = randBetween(0, 1);
        particles[p] -> diffuse[1] = randBetween(0, 1);
        particles[p] -> diffuse[2] = randBetween(0, 1);

        particles[p] -> oDiffuse[0] = particles[p] -> diffuse[0];
        particles[p] -> oDiffuse[1] = particles[p] -> diffuse[1];
        particles[p] -> oDiffuse[2] = particles[p] -> diffuse[2];

        float gForce[3] = {9.81f * particles[p]->mass, 0, 0};
        particles[p] -> addForce(gForce);
    }
    
    light0_position = new GLfloat[4]; //<-------------------------Reserve memory
    light0_position[0] = 1.0f; //<--------------------------------L0x
    light0_position[1] = 1.0f; //<--------------------------------L0y
    light0_position[2] = 1.0f; //<--------------------------------L0z
    light0_position[3] = 0.0f; //<--------------------------------L0w

     light0_ambient = new GLfloat[4]; //<--------------------------Reserve memory
        light0_ambient[0] = 0.3f; //<---------------------------------Ia0r
        light0_ambient[1] = 0.3f; //<---------------------------------Ia0g
        light0_ambient[2] = 0.3f; //<---------------------------------Ia0b
        light0_ambient[3] = 1.0f; //<---------------------------------Ia0a

        light0_diffuse = new GLfloat[4]; //<--------------------------Reserve memory
        light0_diffuse[0] = 1.0f; //<---------------------------------Id0r
        light0_diffuse[1] = 1.0f; //<---------------------------------Id0g
        light0_diffuse[2] = 1.0f; //<---------------------------------Id0b
        light0_diffuse[3] = 1.0f; //<---------------------------------Id0a

        light0_specular = new GLfloat[4]; //<-------------------------Reserve memory
        light0_specular[0] = 1.0f; //<--------------------------------Is0r
        light0_specular[1] = 1.0f; //<--------------------------------Is0g
        light0_specular[2] = 1.0f; //<--------------------------------Is0b
        light0_specular[3] = 1.0f; //<--------------------------------Is0a



      glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);


	glEnable(GL_LIGHTING);
// Enable LIGHT 0:
	glEnable(GL_LIGHT0);


    glEnable(GL_DEPTH_TEST);            // Enable check for close and far objects.
    glEnable( GL_TEXTURE_2D );
    glClearColor(0.0, 0.0, 0.0, 0.0);    // Clear the color state.
    glMatrixMode(GL_MODELVIEW);            // Go to 3D mode.
    glLoadIdentity();                    // Reset 3D view matrix.
}

void display()                            // Called for each frame (about 60 times per second).
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);                // Clear color and depth buffers.
    glLoadIdentity();                                                // Reset 3D view matrix.
    gluLookAt(cameraX, cameraY, cameraZ,                                        // Where the camera is.
              0.0, 0.0, 0.0,                                        // To where the camera points at.
              0.0, 1.0, 0.0);                                        // "UP" vector.
    background->draw();
    glPushMatrix();
    glScalef(0.5, 0.5, 0.5);
      
        
    glPopMatrix();
    
    
    
    switch (type) {
           case 1:
            if(cameraY < 100){
                cameraY = cameraY +1;
            }
               break;
           case 2:
            if(cameraY > -100){
                cameraY = cameraY -1;
            }
               break;
           case 3:
               //move camera right
            if(cameraX < 400){
                cameraX = cameraX +1;
            }
               break;
           case 4:
               // move camera left
            if(cameraX > -100){
                cameraX = cameraX - 1;
            }
               break;
        case 5: // particle system
            for (int p = 0; p < NUM_P; p++) {
                particles[p] -> draw();
            }
            break;
        case 6: // animation
            robot -> startAnimation();
            break;
        case 7:
            robot -> returnAnimation();
            break;
       }
         robot->draw();
    
    

    
    glutSwapBuffers();                                                // Swap the hidden and visible buffers.
}

void idle()                                                            // Called when drawing is finished.
{
    
    glutPostRedisplay();
    for (int p = 0; p < NUM_P; p++) {
        //float gForce[3] = {9.81f * particles[p]->mass, 0, 0};
        //particles[p] -> addForce(gForce);
        particles[p] -> stepSimulation(1/60.0f);
    }                                           // Display again.
    
    switch (type) {
        case 2:
            // animation
         robot -> update();
            break;
    }
}

void reshape(int x, int y)                                            // Called when the window geometry changes.
{
    glMatrixMode(GL_PROJECTION);                                    // Go to 2D mode.
    glLoadIdentity();                                                // Reset the 2D matrix.
    gluPerspective(60.0, (GLdouble)x / (GLdouble)y, 0.01, 1024.0);        // Configure the camera lens aperture.
    glMatrixMode(GL_MODELVIEW);                                        // Go to 3D mode.
    glViewport(0, 0, x, y);                                            // Configure the camera frame dimensions.
    gluLookAt(0.0, 1.0, 4.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
    display();
}

void keyboard(unsigned char key, int x, int y){
    
    switch (key) {
        case 'w':
            type = 1; // particle system
            break;
        case 'a':
            type = 2; // start animation
            break;
        case 's':
            type = 3; //move left
            break;
        case 'd':
            type = 4; // move right 
            break;
        case '1':
            type = 5; // move right
            break;
        case '2':
            type = 6; // move right
            break;
        case '3':
            type = 7;
            break;
    }
    
}


int main(int argc, char* argv[])
{
    
    glutInit(&argc, argv);                                            // Init GLUT with command line parameters.
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);        // Use 2 buffers (hidden and visible). Use the depth buffer. Use 3 color channels.
    glutInitWindowSize(1300, 800);
    glutInitWindowPosition(100, 10);
    
    glutCreateWindow("Optimus prime");
    
    glutReshapeFunc(reshape);                                        // Reshape CALLBACK function.
    init();
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);                                        // Display CALLBACK function.
    glutIdleFunc(idle);                                                // Idle CALLBACK function.
    glutMainLoop();                                                    // Begin graphics program.
    return 0;                                                        // ANSI C requires a return value.
}


