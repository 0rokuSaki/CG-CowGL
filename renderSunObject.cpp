/*****************************************************************//**
 * \file   renderSunObject.cpp
 * \brief  Definition of renderSunObject function.
 * 
 * \author aaron
 * \date   June 2023
 *********************************************************************/

/******************************
*          DEFINES            *
*******************************/
#define _USE_MATH_DEFINES

/******************************
*          INCLUDES           *
*******************************/
#include <cmath>

#include "renderSunObject.h"
#include "RGBColor.h"
#include "WcPt3D.h"

/******************************
*       GLOBAL VARIABLES      *
*******************************/
GLfloat sunAngle = 225.0;
GLfloat sunConstAttenuation = 0.7;

/******************************
*     FUNCTION DEFINITIONS    *
*******************************/
void renderSunObject(void)
{
    /* Dimensions */
    static const GLfloat SUN_SPHERE_RADIUS = 2.0;
    static const GLint SUN_SPHERE_NUM_SLICES = 20;
    static const GLint SUN_SPHERE_NUM_STACKS = 20;

    /* Lighting */
    static const GLfloat sunYellowColor[] = { RGB_COLOR_SUN_YELLOW , 1.0 };
    static const GLfloat blackColor[] = { RGB_COLOR_BLACK, 1.0 };
    static const GLfloat whiteColor[] = { RGB_COLOR_WHITE, 1.0 };
    static const GLfloat SUN_LINEAR_ATTENUATION = 0.005;
    static const GLfloat SUN_QUADRATIC_ATTENUATION = 0.0;

    glEnable(GL_LIGHTING);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    const WcPt3D sunPosition(0.0, SKY_SPHERE_RADIUS * cos(sunAngle / 180.0 * M_PI), SKY_SPHERE_RADIUS * sin(sunAngle / 180.0 * M_PI));
    const GLfloat sunLightPosType[] = { sunPosition.getX(), sunPosition.getY(), sunPosition.getZ(), 1.0 };

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, whiteColor);
    glMaterialfv(GL_FRONT, GL_EMISSION, sunYellowColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, blackColor);

    glTranslatef(sunPosition.getX(), sunPosition.getY(), sunPosition.getZ());
    glutSolidSphere(SUN_SPHERE_RADIUS, SUN_SPHERE_NUM_SLICES, SUN_SPHERE_NUM_STACKS);

    glLightfv(GL_LIGHT0, GL_POSITION, sunLightPosType);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, whiteColor);
    glLightfv(GL_LIGHT0, GL_SPECULAR, whiteColor);
    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, sunConstAttenuation);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, SUN_LINEAR_ATTENUATION);
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, SUN_QUADRATIC_ATTENUATION);
    glEnable(GL_LIGHT0);

    glPopMatrix();
    glDisable(GL_LIGHTING);
}
