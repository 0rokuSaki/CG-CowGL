/*****************************************************************//**
 * \file   Background.cpp
 * \brief  
 * 
 * \author aaron
 * \date   June 2023
 *********************************************************************/

/******************************
*          INCLUDES           *
*******************************/
#include <GL/glut.h>
#include "RGBColor.h"
#include "WcPt3D.h"

/******************************
*     FUNCTION DEFINITIONS    *
*******************************/
void renderBackground(void)
{
    static const WcPt3D BORDER_PT1(100.0, 100.0, 0.0);
    static const WcPt3D BORDER_PT2(-100.0, 100.0, 0.0);
    static const WcPt3D BORDER_PT3(-100.0, -100.0, 0.0);
    static const WcPt3D BORDER_PT4(100.0, -100.0, 0.0);

    static const GLdouble SKY_SPHERE_RADIUS = 125.0;
    static const GLint SKY_SPHERE_NUM_SLICES = 50;
    static const GLint SKY_SPHERE_NUM_STACKS = 50;

    static const GLdouble SUN_SPHERE_RADIUS = 2.0;
    static const GLint SUN_SPHERE_NUM_SLICES = 20;
    static const GLint SUN_SPHERE_NUM_STACKS = 20;
    static const WcPt3D SUN_POSITION(50.0, 50.0, 50.0);
    
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    /* Render plane */
    glColor3d(RGB_COLOR_GRASS_GREEN);
    glBegin(GL_POLYGON);
    glVertex3d(BORDER_PT1.getX(), BORDER_PT1.getY(), BORDER_PT1.getZ());
    glVertex3d(BORDER_PT2.getX(), BORDER_PT2.getY(), BORDER_PT2.getZ());
    glVertex3d(BORDER_PT3.getX(), BORDER_PT3.getY(), BORDER_PT3.getZ());
    glVertex3d(BORDER_PT4.getX(), BORDER_PT4.getY(), BORDER_PT4.getZ());
    glEnd();

    /* Render sky */
    glColor3d(RGB_COLOR_SKY_BLUE);
    glutSolidSphere(SKY_SPHERE_RADIUS, SKY_SPHERE_NUM_SLICES, SKY_SPHERE_NUM_STACKS);

    /* Render sun */
    glTranslated(SUN_POSITION.getX(), SUN_POSITION.getY(), SUN_POSITION.getZ());
    glColor3d(RGB_COLOR_SUN_YELLOW);
    glutSolidSphere(SUN_SPHERE_RADIUS, SUN_SPHERE_NUM_SLICES, SUN_SPHERE_NUM_STACKS);

    glPopMatrix();
}
