#include <time.h>
#include <GL/glut.h>
#include <math.h>

#include "planets.hpp"
#include "info.hpp"

void display();

int stars[400][2];
int activePlanet = 0;

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

void update(int value)
{
        angle_mercury -= speed_mercury;
        if (angle_mercury > 360.0f)
                angle_mercury -= 360.0f;

        angle_venus -= speed_venus;
        if (angle_venus > 360.0f)
                angle_venus -= 360.0f;

        angle_earth -= speed_earth;
        if (angle_earth > 360.0f)
                angle_earth -= 360.0f;

        angle_mars -= speed_mars;
        if (angle_mars > 360.0f)
                angle_mars -= 360.0f;

        angle_jupiter -= speed_jupiter;
        if (angle_jupiter > 360.0f)
                angle_jupiter -= 360.0f;

        angle_saturn -= speed_saturn;
        if (angle_saturn > 360.0f)
                angle_saturn -= 360.0f;

        angle_uranus -= speed_uranus;
        if (angle_uranus > 360.0f)
                angle_uranus -= 360.0f;

        angle_neptune -= speed_neptune;
        if (angle_neptune > 360.0f)
                speed_neptune -= 360.0f;
        angle_asteroid += 0.002;
        if (angle_asteroid > 360)
        {
                angle_asteroid -= 360;
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
        glRotatef(30, 1.0f, 0, 0);

        displayMenu();

        switch (activePlanet)
        {
        case 1:
                displayMercury();
                break;

        case 2:
                displayVenus();
                break;

        case 3:
                displayEarth();
                break;

        case 4:
                displayMars();
                break;

        case 5:
                displayJupiter();
                break;

        case 6:
                displaySaturn();
                break;

        case 7:
                displayUranus();
                break;

        case 8:
                displayNeptune();
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
        case 'r':
                activePlanet = 1;
                break;

        case 'v':
                activePlanet = 2;
                break;

        case 'e':
                activePlanet = 3;
                break;

        case 'm':
                activePlanet = 4;
                break;

        case 'j':
                activePlanet = 5;
                break;

        case 's':
                activePlanet = 6;
                break;

        case 'u':
                activePlanet = 7;
                break;

        case 'n':
                activePlanet = 8;
                break;

        default:
                break;
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
