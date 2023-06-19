/*****************************************************************//**
 * \file   renderBackground.cpp
 * \brief  Definition of renderBackground function.
 * 
 * \author aaron
 * \date   June 2023
 *********************************************************************/

/******************************
*          INCLUDES           *
*******************************/
#include "RGBColor.h"
#include "WcPt3D.h"
#include "WcVector3D.h"

/******************************
*       GLOBAL VARIABLES      *
*******************************/
const GLfloat WORLD_MIN_COORD = -100.0;
const GLfloat WORLD_MAX_COORD = 100.0;
const GLfloat SKY_SPHERE_RADIUS = 70.0;

/******************************
*     FUNCTION DEFINITIONS    *
*******************************/
void renderBackground(void)
{
    /* Sky */
    static const GLint SKY_SPHERE_NUM_SLICES = 50;
    static const GLint SKY_SPHERE_NUM_STACKS = 50;

    /* Lighting */
    static const GLfloat grassGreenColor[] = { RGB_COLOR_GRASS_GREEN, 1.0 };
    static const GLfloat skyBlueColor[] = { RGB_COLOR_SKY_BLUE, 1.0 };
    static const GLfloat blackColor[] = { RGB_COLOR_BLACK, 1.0 };
    static const GLfloat whiteColor[] = { RGB_COLOR_WHITE, 1.0 };

    glEnable(GL_LIGHTING);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    /* Render plane */
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, grassGreenColor);
    glMaterialfv(GL_FRONT, GL_EMISSION, blackColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, blackColor);

    glBegin(GL_POLYGON);
    glNormal3f(0.0, 0.0, 1.0);
    glVertex3f(WORLD_MIN_COORD, WORLD_MIN_COORD, 0.0);
    glVertex3f(WORLD_MAX_COORD, WORLD_MIN_COORD, 0.0);
    glVertex3f(WORLD_MAX_COORD, WORLD_MAX_COORD, 0.0);
    glVertex3f(WORLD_MIN_COORD, WORLD_MAX_COORD, 0.0);
    glEnd();

    /* Render sky */
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, skyBlueColor);
    glMaterialfv(GL_FRONT, GL_EMISSION, blackColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, blackColor);
    
    glutSolidSphere(SKY_SPHERE_RADIUS, SKY_SPHERE_NUM_SLICES, SKY_SPHERE_NUM_STACKS);

    glPopMatrix();
    glDisable(GL_LIGHTING);
}
