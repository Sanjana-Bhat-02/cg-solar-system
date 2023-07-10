#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>
#include <math.h>
#include <string.h>

// drawstring(str4, -7.5, 4, 0.0);
int y = 4;
void *currentfont;

void setFont(void *font)
{
    currentfont = font;
}
void drawstring(char string[], float x1, float y1, float z1)
{
    int i, j;
    j = strlen(string);
    glRasterPos3f(x1, y1, z1);
    for (i = 0; i < j; i++)
    {
        glutBitmapCharacter(currentfont, string[i]);
    }
}

void displayMenu()
{
    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glDisable(GL_LIGHTING);
    glColor3f(0.651, 0.827, 0.880);
    drawstring("Keys", 6.5, y, 0.0);
    drawstring("R - Mercury", 6.3, y - 0.5, 0.0);
    drawstring("V - Venus", 6.3, y - 1, 0.0);
    drawstring("E - Earth", 6.3, y - 1.5, 0.0);
    drawstring("M - Mars", 6.3, y - 2, 0.0);
    drawstring("J - Jupiter", 6.3, y - 2.5, 0.0);
    drawstring("S - Saturn", 6.3, y - 3, 0.0);
    drawstring("U - Uranus", 6.3, y - 3.5, 0.0);
    drawstring("N - Neptune", 6.3, y - 4, 0.0);

    glEnable(GL_LIGHTING);
}

void displayMercury()
{

    glDisable(GL_LIGHTING);

    drawstring("Mercury", -7.5, y, 0.0);
    drawstring("* Smallest and 1st planet", -7.5, y - 0.5, 0.0);
    drawstring("* Extreme temperature variations", -7.5, y - 1, 0.0);
    drawstring("* Cratered surface, resembling Moon.", -7.5, y - 1.5, 0.0);

    glEnable(GL_LIGHTING);
}

void displayVenus()
{

    glDisable(GL_LIGHTING);

    drawstring("Venus", -7.5, y, 0.0);
    drawstring("* Intense greenhouse effect, extreme heat.", -7.5, y - 0.5, 0.0);
    drawstring("* Average temperature of 462°C (864°F).", -7.5, y - 1, 0.0);
    drawstring("* Dense cloud cover, primarily sulfuric acid.", -7.5, y - 1.5, 0.0);

    glEnable(GL_LIGHTING);
}

void displayEarth()
{

    glDisable(GL_LIGHTING);

    drawstring("Earth", -7.5, y, 0.0);
    drawstring("* Only known planet with life.", -7.5, y - 0.5, 0.0);
    drawstring("* Diverse ecosystems and habitats.", -7.5, y - 1, 0.0);
    drawstring("* Blue planet, abundant water.", -7.5, y - 1.5, 0.0);

    glEnable(GL_LIGHTING);
}

void displayMars()
{

    glDisable(GL_LIGHTING);

    drawstring("Mars", -7.5, y, 0.0);
    drawstring("* Thin atmosphere, mainly carbon dioxide.", -7.5, y - 0.5, 0.0);
    drawstring("* Polar ice caps, potential water.", -7.5, y - 1, 0.0);
    drawstring("* Largest volcano, Olympus Mons.", -7.5, y - 1.5, 0.0);

    glEnable(GL_LIGHTING);
}

void displayJupiter()
{

    glDisable(GL_LIGHTING);

    drawstring("Jupiter", -7.5, y, 0.0);
    drawstring("* Largest planet in solar system.", -7.5, y - 0.5, 0.0);
    drawstring("* Great Red Spot, persistent storm.", -7.5, y - 1, 0.0);
    drawstring("* Numerous moons, including Ganymede.", -7.5, y - 1.5, 0.0);

    glEnable(GL_LIGHTING);
}

void displaySaturn()
{

    glDisable(GL_LIGHTING);

    drawstring("Saturn", -7.5, y, 0.0);
    drawstring("* Distinctive ring system encircling planet.", -7.5, y - 0.5, 0.0);
    drawstring("* Second largest planet in solar system.", -7.5, y - 1, 0.0);
    drawstring("* Gas giant, predominantly hydrogen and helium.", -7.5, y - 1.5, 0.0);

    glEnable(GL_LIGHTING);
}

void displayUranus()
{

    glDisable(GL_LIGHTING);

    drawstring("Uranus", -7.5, y, 0.0);
    drawstring("* Pale blue color, distinct appearance.", -7.5, y - 0.5, 0.0);
    drawstring("* Ice giant, primarily composed of methane.", -7.5, y - 1, 0.0);
    drawstring("* Rings and multiple moons.", -7.5, y - 1.5, 0.0);

    glEnable(GL_LIGHTING);
}

void displayNeptune()
{

    glDisable(GL_LIGHTING);

    drawstring("Neptune", -7.5, y, 0.0);
    drawstring("* Blue planet, deep blue color.", -7.5, y - 0.5, 0.0);
    drawstring("* Farthest known planet from the Sun.", -7.5, y - 1, 0.0);
    drawstring("* Active weather patterns, fast winds.", -7.5, y - 1.5, 0.0);

    glEnable(GL_LIGHTING);
}

