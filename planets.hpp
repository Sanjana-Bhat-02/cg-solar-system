#include <GL/glut.h>
#include <math.h>
#include <iostream>
#define PI 3.14
double ang = 2 * PI / 290;
double angular = 2 * PI / 50;
float angle_asteroid = 0.0;

void drawSun()
{

    glColor4f(1.00, 0.78, 0.01, 1.0);
    glutSolidSphere(0.6, 200, 200);
}

float angle_mercury, speed_mercury = 2.0f;
void drawMercury()
{
    // mercury
    glColor3f(1, 1, 1);
    glutWireTorus(.8, 0, 100, 1);

    glPushMatrix();
    glRotatef(angle_mercury, 0.0f, 1.0f, 0.0f);
    // glTranslatef(.4,.1,0.0);
    glTranslatef(0.8, 0.1, 0.0);

    glColor3f(0.510, 0.378, 0.0153);
    glutSolidSphere(0.07, 100, 100);
    glPopMatrix();
}

float angle_venus, speed_venus = 4.5f;
void drawVenus()
{
    glColor3f(1, 1, 1);
    glutWireTorus(1.35, .0, 100, 1);

    glPushMatrix();
    glRotatef(angle_venus, 0.0f, 1.0f, 0.0f);
    glTranslatef(1.3, 0.1, 0.0);

    glColor3f(0.880, 0.751, 0.396);
    glutSolidSphere(.15, 100, 100);
    glPopMatrix();
}

float angle_earth, speed_earth = 2.1f;
void drawEarth()
{
    // Orbit
    glColor3f(1, 1, 1);
    glutWireTorus(1.85, 0, 100, 1);

    glPushMatrix();
    glRotatef(angle_earth, 0.0f, 1.0f, 0.0f);
    glTranslatef(1.8, 0.1, 0.0);

    glColor3f(.27, .68, .93);
    glutSolidSphere(.15, 100, 100);
    glPopMatrix();
}

float angle_mars, speed_mars = 3.0f;
void drawMars()
{

    glColor3f(1, 1, 1);
    glutWireTorus(2.3, 0, 100, 1);

    glPushMatrix();
    glRotatef(angle_mars, 0.0f, 1.0f, 0.0f);
    glTranslatef(2.3, 0.1, 0.0);

    glColor3f(.99, .33, .3);
    glutSolidSphere(.11, 100, 100);
    glPopMatrix();
}

float angle_jupiter, speed_jupiter = 2.5f;
void drawJupiter()
{
    glColor3f(1, 1, 1);
    glutWireTorus(2.8, 0, 100, 1);

    glPushMatrix();
    glRotatef(angle_jupiter, 0.0f, 1.0f, 0.0f);
    glTranslatef(2.8, 0.1, 0.0);

    glColor3f(.67, .59, .53);
    glutSolidSphere(.3, 100, 100);
    glPopMatrix();
}

float angle_saturn, speed_saturn = 1.5f;
void drawSaturn()
{
    glColor3f(1, 1, 1);
    glutWireTorus(3.35, 0, 100, 1);

    glPushMatrix();
    glRotatef(angle_saturn, 0.0f, 1.0f, 0.0f);
    glTranslatef(3.3, 0.1, 0.0);

    glColor3f(.75, .62, .43);
    glutSolidSphere(.2, 100, 100);

    //rings
    glColor3f(1, 1, 1);
    glRotatef(20, 0, 0, 1);
    glutWireTorus(0.2, 0, 100, 1);
    glutWireTorus(0.25, 0, 100, 1);
    glutWireTorus(0.26, 0, 100, 1);
    glutWireTorus(0.28, 0, 100, 1);
    glutWireTorus(0.3, 0, 100, 1);
    glutWireTorus(0.35, 0, 100, 1);
    glutWireTorus(0.4, 0, 100, 1);
    glPopMatrix();
}

float angle_uranus, speed_uranus = 2.0f;
void drawUranus()
{
    // Orbit
    glColor3f(1, 1, 1);
    glutWireTorus(3.85, 0, 100, 1);

    glPushMatrix();
    glRotatef(angle_uranus, 0.0f, 1.0f, 0.0f);
    glTranslatef(3.8, 0.1, 0.0);

    // glColor3f(.22,.32,.82);
    // glutSolidSphere(.11,100,100);
    // glPopMatrix();
    glColor3f(0.696, 0.883, 0.940);
    glutSolidSphere(.17, 100, 100);

     glColor3f(1, 1, 1);
    glRotatef(-45, 0, 0, 1);
    glutWireTorus(0.2, 0, 100, 1);
    
    
    
    glutWireTorus(0.3, 0, 100, 1);
    
   

    glPopMatrix();
}

float angle_neptune, speed_neptune = 1.0f;
void drawNeptune()
{
    
    glColor3f(1, 1, 1);
    glutWireTorus(4.5, 0, 100, 1);

    glPushMatrix();
    glRotatef(angle_neptune, 0.0f, 1.0f, 0.0f);
    glTranslatef(4.5, 0.1, 0.0);

    glDisable(GL_LIGHT7);
    glColor3f(.22, .32, .82);
    glutSolidSphere(.17, 100, 100);

    glColor3f(1, 1, 1);
    glRotatef(80, 0, 0, 1);
    glutWireTorus(0.2, 0, 100, 1);
    
    
    
    glutWireTorus(0.3, 0, 100, 1);
    glEnable(GL_LIGHT7);
    glPopMatrix();

}
void asteroid()
{
    glPushMatrix();
    glColor3f(3.30, 3.30, 3.30);
    glRotatef(30, 1.0, 0.0, 0.0);
    glScalef(0.75, 0.75, 0.75);
    int j = 0, i = 0, div = 90;
    float siz = 2;
    float scl[4] = {3.3, 3.4, 3.35, 3.2};
    for (j = 0; j < 4; j++)
    {
        glPushMatrix();
        siz -= 0.3;
        glPointSize(siz);
        glScalef(scl[j], scl[j], scl[j]);
        glBegin(GL_POINTS);
        double ang1 = 0.0 - angle_asteroid, a = (2 * PI) / div;
        for (i = 0; i < div; i++)
        {
            glVertex2d(cos(ang1), sin(ang1));
            ang1 += a;
        }
        div += 50;
        glEnd();
        glPopMatrix();
    }
    glPopMatrix();
}
