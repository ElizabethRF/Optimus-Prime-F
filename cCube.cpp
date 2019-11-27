#include "headers/cCube.h"

Cube::Cube( float side, bool use_mipmaps )
{
    this->side = side;
    hside = (side / 2.0f);
    
    for (int t = 0;t < 6; t++)
    {
        glGenTextures(1, &targas[t].texID);
        glBindTexture(GL_TEXTURE_2D, targas[t].texID);
        glTexEnvi( GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);
        if (use_mipmaps)
        {
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
        }
        else
        {
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

        }
        
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        
        switch (t) {
            case 0: LoadTGA(&targas[t],"/Users/Intern/Documents/Tec/graficas/TGA/TGA/assets/cube_bottom.tga");  break;
            case 1: LoadTGA(&targas[t],"/Users/Intern/Documents/Tec/graficas/OptimusPrime/OptimusPrime/assets/cube_right.tga");  break;

        }
        
        
        if(use_mipmaps){
            gluBuild2DMipmaps(GL_TEXTURE_2D,
                              3,
                              targas[t].width,
                              targas[t].height,
                              GL_RGB,
                              GL_UNSIGNED_BYTE,
                              targas[t].imageData);
            
        }
        else{
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, targas[t].width, targas[t].height, 0, GL_RGB, GL_UNSIGNED_BYTE, targas[t].imageData);
        }
        glBindTexture(GL_TEXTURE_2D, 0); // unbind
    }
        

}

Cube::~Cube( void )
{
    glDeleteTextures( 1, &targas[0].texID );
    glDeleteTextures( 1, &targas[1].texID );
    glDeleteTextures( 1, &targas[2].texID );
    glDeleteTextures( 1, &targas[3].texID );
    glDeleteTextures( 1, &targas[4].texID );
    glDeleteTextures( 1, &targas[5].texID );
}

void Cube::draw( void )
{
    glPushMatrix();
    glRotatef(-60, 0, 100, 0);
    glBindTexture(GL_TEXTURE_2D, targas[0].texID);

    glBegin(GL_QUADS); // BACK
    {
        glNormal3f(0.0f, 0.0f, 1.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(hside, -hside, -hside);

        glNormal3f(0.0f, 0.0f, 1.0f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-hside, -hside, -hside);

        glNormal3f(0.0f, 0.0f, 1.0f);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(-hside, 2*hside, -hside);

        glNormal3f(0.0f, 0.0f, 1.0f);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(hside, 2*hside, -hside);

    }
     glEnd();
    glBindTexture(GL_TEXTURE_2D, NULL); // unbind
    
    glBindTexture(GL_TEXTURE_2D, targas[1].texID);
    glBegin(GL_QUADS); // BOTTOM
    {
        glNormal3f(0.0f, 0.0f, 1.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-hside, -hside, hside);
        glNormal3f(0.0f, 0.0f, 1.0f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(hside, -hside, hside);

        glNormal3f(0.0f, 0.0f, 1.0f);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(hside, -hside, -hside);

        glNormal3f(0.0f, 0.0f, 1.0f);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-hside, -hside, -hside);



    }
    glEnd();
    glBindTexture(GL_TEXTURE_2D, NULL); // unbind
    
    
    glBindTexture(GL_TEXTURE_2D, targas[0].texID);
    
        glBegin(GL_QUADS); // LEFT
        {
            glNormal3f(0.0f, 0.0f, 1.0f);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(-hside, -hside, -hside);

            glNormal3f(0.0f, 0.0f, 1.0f);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(-hside, -hside, hside);

            glNormal3f(0.0f, 0.0f, 1.0f);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(-hside, 2*hside, hside);

            glNormal3f(0.0f, 0.0f, 1.0f);
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(-hside, 2*hside, -hside);
        }
        glEnd();
    
        glBindTexture(GL_TEXTURE_2D, NULL);
    glPopMatrix();
   
}
