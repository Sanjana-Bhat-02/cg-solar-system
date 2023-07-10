#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.14
#include "planets.hpp"
#include "info.hpp"
void display();
int stars[400][2];
int activePlanet = 0;

#define PI 3.14159265

// Shooting Star Structure
struct ShootingStar {
    float startX;
    float startY;
    float endX;
    float endY;
};

// Array to store shooting stars
ShootingStar shootingStars[100];
int numShootingStars = 100;

void generateStars()
{
    for (int i = 0; i < 400; i++)
    {
        stars[i][0] = rand() % glutGet(GLUT_WINDOW_WIDTH);
        stars[i][1] = rand() % glutGet(GLUT_WINDOW_HEIGHT);
    }
}

void draw_stars()
{
    glDisable(GL_LIGHTING);
    glColor3f(1.0, 1.0, 1.0);

    glPointSize(2.0);
    glBegin(GL_POINTS);
    for (int i = 0; i < 400; i++)
    {
        glVertex2f(stars[i][0], stars[i][1]);
    }
    glEnd();
    glEnable(GL_LIGHTING);
}








void update(int value) {
	MercuryAngle -= MercurySpeed;
	if(MercuryAngle>360.0f)
        MercuryAngle -= 360.0f;

	VenusAngle -= VenusSpeed;
	if(VenusAngle>360.0f)
        VenusAngle -= 360.0f;

	EarthAngle -= EarthSpeed;
	if(EarthAngle>360.0f)
        EarthAngle -= 360.0f;

	MarsAngle -= MarsSpeed;
	if(MarsAngle>360.0f)
        MarsAngle -= 360.0f;

	JupiterAngle -= JupiterSpeed;
	if(JupiterAngle>360.0f)
        JupiterAngle -= 360.0f;

	SaturnAngle -= SaturnSpeed;
	if(SaturnAngle>360.0f)
        SaturnAngle -= 360.0f;

	UranusAngle -= UranusSpeed;
	if(UranusAngle>360.0f)
        UranusAngle -= 360.0f;

	NeptuneAngle -= NeptuneSpeed;
	if(NeptuneAngle>360.0f)
        NeptuneSpeed -= 360.0f;
    angleAstroid += 0.002;
    if (angleAstroid > 360)
    {
        angleAstroid -= 360;
    }
   
	
	glutTimerFunc(45, update, 0);
    glutPostRedisplay();
    
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, glutGet(GLUT_WINDOW_WIDTH), 0.0, glutGet(GLUT_WINDOW_HEIGHT));

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    draw_stars();
    gluLookAt(3, 3, 5, 0, 0, 0, 0, 1, 0);
   
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    double aspect_ratio = (double)glutGet(GLUT_WINDOW_WIDTH) / (double)glutGet(GLUT_WINDOW_HEIGHT);
    glOrtho(-aspect_ratio, aspect_ratio, -1.0, 1.0, -20.0, 20.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    
    glScalef(0.25, 0.25, 0.25);
glRotatef(30,1.0f,0,0);


   
    displayMenu();
    
    switch (activePlanet)
    {
    case 1: displayMercury();
            break;

    case 2: displayVenus();
            break;

    case 3: displayEarth();
            break;
    
    case 4: displayMars();
            break;

    case 5: displayJupiter();
            break;
    
    case 6: displaySaturn();
            break;
    
    case 7: displayUranus();
            break;
    
    case 8: displayNeptune();
            break;

    
    default:
        break;
    }

    
    
    

    


    drawSun();
    drawMercury();
    drawVenus();
    drawEarth();
    asteroid();
    drawMars();
    drawJupiter();
    drawSaturn();
    drawUranus();
    drawNeptune();

    
    //glPopMatrix();
    glutSwapBuffers(); 
}


void init()
{
   
    srand(time(NULL));
    glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING); 
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1); 
	glEnable(GL_NORMALIZE); 
	glShadeModel(GL_SMOOTH);
}


void keyboardInfoDisplay(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'r':   activePlanet = 1;
                    break;
        
        case 'v':   activePlanet = 2;
                    break;
        
        case 'e':   activePlanet = 3;
                    break;
        
        case 'm':   activePlanet = 4;
                    break;

        case 'j':   activePlanet = 5;
                    break;
        
        case 's':   activePlanet = 6;
                    break;
        
        case 'u':   activePlanet = 7;
                    break;

        case 'n':   activePlanet = 8;
                    break;

        default:    break;
    }
   
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_STENCIL); // or GLUT_SINGLE

    int screenWidth = glutGet(GLUT_SCREEN_WIDTH);
    int screenHeight = glutGet(GLUT_SCREEN_HEIGHT);

    glutInitWindowSize(screenWidth, screenHeight);
    glutCreateWindow("Solar System");
    
    init();
    generateStars();
   

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboardInfoDisplay);
    glutTimerFunc(1, update, 0);

    glutMainLoop();

    return 0;
}

