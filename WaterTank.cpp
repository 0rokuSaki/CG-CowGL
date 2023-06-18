/*****************************************************************//**
 * \file   WaterTank.cpp
 * \brief  
 * 
 * \author aaron
 * \date   June 2023
 *********************************************************************/

/******************************
*          INCLUDES           *
*******************************/
#include <GL/glut.h>
#include "WaterTank.h"
#include "WcPt3D.h"
#include "RGBColor.h"

/******************************
*     FUNCTION DEFINITIONS    *
*******************************/
void renderWaterTank(WcPt3D position, GLdouble rotationAngle)
{
    static const GLdouble WATER_TANK_WIDTH = 1.0;
    static const GLdouble WATER_TANK_LENGTH = 3.0;
    static const GLdouble WATER_TANK_HEIGHT = 0.5;
    static const GLdouble WATER_TANK_WATER_LEVEL = 0.35;
    static const GLdouble WATER_TANK_LINE_WIDTH = 1.0;

    /* Lighting */
    static const GLfloat darkGrayColor[] = { RGB_COLOR_DARK_GRAY, 1.0 };
    static const GLfloat waterBlueColor[] = { RGB_COLOR_WATER_BLUE, 1.0 };
    static const GLfloat blackColor[] = { RGB_COLOR_BLACK, 1.0 };
    static const GLfloat whiteColor[] = { RGB_COLOR_WHITE, 1.0 };

    glEnable(GL_LIGHTING);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glRotated(rotationAngle, 0.0, 0.0, 1.0);
    glTranslated(position.getX(), position.getY(), position.getZ());

    /* Water tank walls */
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, darkGrayColor);
    glMaterialfv(GL_FRONT, GL_EMISSION, blackColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, whiteColor);
    glMaterialf(GL_FRONT, GL_SHININESS, 15.5);

    glBegin(GL_POLYGON);
    glNormal3f(0.0, -1.0, 0.0);
    glVertex3d((WATER_TANK_WIDTH / 2.0), -(WATER_TANK_LENGTH / 2.0), 0.0);
    glVertex3d(-(WATER_TANK_WIDTH / 2.0), -(WATER_TANK_LENGTH / 2.0), 0.0);
    glVertex3d(-(WATER_TANK_WIDTH / 2.0), -(WATER_TANK_LENGTH / 2.0), WATER_TANK_HEIGHT);
    glVertex3d((WATER_TANK_WIDTH / 2.0), -(WATER_TANK_LENGTH / 2.0), WATER_TANK_HEIGHT);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(1.0, 0.0, 0.0);
    glVertex3d((WATER_TANK_WIDTH / 2.0), -(WATER_TANK_LENGTH / 2.0), 0.0);
    glVertex3d((WATER_TANK_WIDTH / 2.0), (WATER_TANK_LENGTH / 2.0), 0.0);
    glVertex3d((WATER_TANK_WIDTH / 2.0), (WATER_TANK_LENGTH / 2.0), WATER_TANK_HEIGHT);
    glVertex3d((WATER_TANK_WIDTH / 2.0), -(WATER_TANK_LENGTH / 2.0), WATER_TANK_HEIGHT);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(-1.0, 0.0, 0.0);
    glVertex3d(-(WATER_TANK_WIDTH / 2.0), -(WATER_TANK_LENGTH / 2.0), 0.0);
    glVertex3d(-(WATER_TANK_WIDTH / 2.0), (WATER_TANK_LENGTH / 2.0), 0.0);
    glVertex3d(-(WATER_TANK_WIDTH / 2.0), (WATER_TANK_LENGTH / 2.0), WATER_TANK_HEIGHT);
    glVertex3d(-(WATER_TANK_WIDTH / 2.0), -(WATER_TANK_LENGTH / 2.0), WATER_TANK_HEIGHT);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(0.0, 1.0, 0.0);
    glVertex3d(-(WATER_TANK_WIDTH / 2.0), (WATER_TANK_LENGTH / 2.0), 0.0);
    glVertex3d((WATER_TANK_WIDTH / 2.0), (WATER_TANK_LENGTH / 2.0), 0.0);
    glVertex3d((WATER_TANK_WIDTH / 2.0), (WATER_TANK_LENGTH / 2.0), WATER_TANK_HEIGHT);
    glVertex3d(-(WATER_TANK_WIDTH / 2.0), (WATER_TANK_LENGTH / 2.0), WATER_TANK_HEIGHT);
    glEnd();

    /* Water */
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, waterBlueColor);
    glMaterialfv(GL_FRONT, GL_EMISSION, blackColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, whiteColor);
    glMaterialf(GL_FRONT, GL_SHININESS, 15.5);

    glBegin(GL_POLYGON);
    glNormal3f(0.0, 0.0, 1.0);
    glVertex3d(-(WATER_TANK_WIDTH / 2.0), -(WATER_TANK_LENGTH / 2.0), WATER_TANK_WATER_LEVEL);
    glVertex3d((WATER_TANK_WIDTH / 2.0), -(WATER_TANK_LENGTH / 2.0), WATER_TANK_WATER_LEVEL);
    glVertex3d((WATER_TANK_WIDTH / 2.0), (WATER_TANK_LENGTH / 2.0), WATER_TANK_WATER_LEVEL);
    glVertex3d(-(WATER_TANK_WIDTH / 2.0), (WATER_TANK_LENGTH / 2.0), WATER_TANK_WATER_LEVEL);
    glEnd();

    glPopMatrix();
    glDisable(GL_LIGHTING);
}
