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
#include "WcVector3D.h"

/******************************
*     FUNCTION DEFINITIONS    *
*******************************/
void renderBackground(void)
{
    /* Plane */
    static const WcPt3D BORDER_PT1(100.0, 100.0, 0.0);
    static const WcPt3D BORDER_PT2(-100.0, 100.0, 0.0);
    static const WcPt3D BORDER_PT3(-100.0, -100.0, 0.0);
    static const WcPt3D BORDER_PT4(100.0, -100.0, 0.0);
    static const WcVector3D PLANE_NORMAL(0.0, 0.0, 1.0);

    /* Sky */
    static const GLdouble SKY_SPHERE_RADIUS = 70.0;
    static const GLint SKY_SPHERE_NUM_SLICES = 50;
    static const GLint SKY_SPHERE_NUM_STACKS = 50;

    /* Sun */
    static const GLdouble SUN_SPHERE_RADIUS = 2.0;
    static const GLint SUN_SPHERE_NUM_SLICES = 20;
    static const GLint SUN_SPHERE_NUM_STACKS = 20;
    static const WcPt3D SUN_POSITION(40.0, 40.0, 40.0);

    /* Lighting */
    static const GLfloat sunLightPosType[] = { SUN_POSITION.getX(), SUN_POSITION.getY(), SUN_POSITION.getZ(), 1.0 };
    static const GLfloat grassGreenColor[] = { RGB_COLOR_GRASS_GREEN, 1.0 };
    static const GLfloat skyBlueColor[] = { RGB_COLOR_SKY_BLUE, 1.0 };
    static const GLfloat sunYellowColor[] = { RGB_COLOR_SUN_YELLOW , 1.0 };
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
    glNormal3f(PLANE_NORMAL.getX(), PLANE_NORMAL.getY(), PLANE_NORMAL.getZ());
    glVertex3d(BORDER_PT1.getX(), BORDER_PT1.getY(), BORDER_PT1.getZ());
    glVertex3d(BORDER_PT2.getX(), BORDER_PT2.getY(), BORDER_PT2.getZ());
    glVertex3d(BORDER_PT3.getX(), BORDER_PT3.getY(), BORDER_PT3.getZ());
    glVertex3d(BORDER_PT4.getX(), BORDER_PT4.getY(), BORDER_PT4.getZ());
    glEnd();

    /* Render sky */
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, skyBlueColor);
    glMaterialfv(GL_FRONT, GL_EMISSION, blackColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, blackColor);
    
    glutSolidSphere(SKY_SPHERE_RADIUS, SKY_SPHERE_NUM_SLICES, SKY_SPHERE_NUM_STACKS);

    /* Render sun */
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, whiteColor);
    glMaterialfv(GL_FRONT, GL_EMISSION, sunYellowColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, blackColor);

    glTranslated(SUN_POSITION.getX(), SUN_POSITION.getY(), SUN_POSITION.getZ());
    glutSolidSphere(SUN_SPHERE_RADIUS, SUN_SPHERE_NUM_SLICES, SUN_SPHERE_NUM_STACKS);

    glLightfv(GL_LIGHT0, GL_POSITION, sunLightPosType);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, whiteColor);
    glLightfv(GL_LIGHT0, GL_SPECULAR, whiteColor);
    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1.0);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.005);
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.0);
    glEnable(GL_LIGHT0);

    glPopMatrix();
    glDisable(GL_LIGHTING);
}
