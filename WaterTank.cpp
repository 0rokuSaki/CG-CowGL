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

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glRotated(rotationAngle, 0.0, 0.0, 1.0);
    glTranslated(position.getX(), position.getY(), position.getZ());

    /* Water tank walls */
    glColor3d(0.3, 0.3, 0.3);

    glBegin(GL_POLYGON);
    glVertex3d((WATER_TANK_WIDTH / 2.0), -(WATER_TANK_LENGTH / 2.0), 0.0);
    glVertex3d(-(WATER_TANK_WIDTH / 2.0), -(WATER_TANK_LENGTH / 2.0), 0.0);
    glVertex3d(-(WATER_TANK_WIDTH / 2.0), -(WATER_TANK_LENGTH / 2.0), WATER_TANK_HEIGHT);
    glVertex3d((WATER_TANK_WIDTH / 2.0), -(WATER_TANK_LENGTH / 2.0), WATER_TANK_HEIGHT);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3d((WATER_TANK_WIDTH / 2.0), -(WATER_TANK_LENGTH / 2.0), 0.0);
    glVertex3d((WATER_TANK_WIDTH / 2.0), (WATER_TANK_LENGTH / 2.0), 0.0);
    glVertex3d((WATER_TANK_WIDTH / 2.0), (WATER_TANK_LENGTH / 2.0), WATER_TANK_HEIGHT);
    glVertex3d((WATER_TANK_WIDTH / 2.0), -(WATER_TANK_LENGTH / 2.0), WATER_TANK_HEIGHT);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3d(-(WATER_TANK_WIDTH / 2.0), -(WATER_TANK_LENGTH / 2.0), 0.0);
    glVertex3d(-(WATER_TANK_WIDTH / 2.0), (WATER_TANK_LENGTH / 2.0), 0.0);
    glVertex3d(-(WATER_TANK_WIDTH / 2.0), (WATER_TANK_LENGTH / 2.0), WATER_TANK_HEIGHT);
    glVertex3d(-(WATER_TANK_WIDTH / 2.0), -(WATER_TANK_LENGTH / 2.0), WATER_TANK_HEIGHT);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3d(-(WATER_TANK_WIDTH / 2.0), (WATER_TANK_LENGTH / 2.0), 0.0);
    glVertex3d((WATER_TANK_WIDTH / 2.0), (WATER_TANK_LENGTH / 2.0), 0.0);
    glVertex3d((WATER_TANK_WIDTH / 2.0), (WATER_TANK_LENGTH / 2.0), WATER_TANK_HEIGHT);
    glVertex3d(-(WATER_TANK_WIDTH / 2.0), (WATER_TANK_LENGTH / 2.0), WATER_TANK_HEIGHT);
    glEnd();

    /* Water */
    glColor3d(RGB_COLOR_WATER_BLUE);

    glBegin(GL_POLYGON);
    glVertex3d(-(WATER_TANK_WIDTH / 2.0), -(WATER_TANK_LENGTH / 2.0), WATER_TANK_WATER_LEVEL);
    glVertex3d((WATER_TANK_WIDTH / 2.0), -(WATER_TANK_LENGTH / 2.0), WATER_TANK_WATER_LEVEL);
    glVertex3d((WATER_TANK_WIDTH / 2.0), (WATER_TANK_LENGTH / 2.0), WATER_TANK_WATER_LEVEL);
    glVertex3d(-(WATER_TANK_WIDTH / 2.0), (WATER_TANK_LENGTH / 2.0), WATER_TANK_WATER_LEVEL);
    glEnd();

    /* Water tank walls frame */
    glColor3d(RGB_COLOR_BLACK);
    glLineWidth(WATER_TANK_LINE_WIDTH);

    glBegin(GL_LINE_LOOP);
    glVertex3d((WATER_TANK_WIDTH / 2.0), -(WATER_TANK_LENGTH / 2.0), 0.0);
    glVertex3d(-(WATER_TANK_WIDTH / 2.0), -(WATER_TANK_LENGTH / 2.0), 0.0);
    glVertex3d(-(WATER_TANK_WIDTH / 2.0), -(WATER_TANK_LENGTH / 2.0), WATER_TANK_HEIGHT);
    glVertex3d((WATER_TANK_WIDTH / 2.0), -(WATER_TANK_LENGTH / 2.0), WATER_TANK_HEIGHT);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3d((WATER_TANK_WIDTH / 2.0), -(WATER_TANK_LENGTH / 2.0), 0.0);
    glVertex3d((WATER_TANK_WIDTH / 2.0), (WATER_TANK_LENGTH / 2.0), 0.0);
    glVertex3d((WATER_TANK_WIDTH / 2.0), (WATER_TANK_LENGTH / 2.0), WATER_TANK_HEIGHT);
    glVertex3d((WATER_TANK_WIDTH / 2.0), -(WATER_TANK_LENGTH / 2.0), WATER_TANK_HEIGHT);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3d(-(WATER_TANK_WIDTH / 2.0), -(WATER_TANK_LENGTH / 2.0), 0.0);
    glVertex3d(-(WATER_TANK_WIDTH / 2.0), (WATER_TANK_LENGTH / 2.0), 0.0);
    glVertex3d(-(WATER_TANK_WIDTH / 2.0), (WATER_TANK_LENGTH / 2.0), WATER_TANK_HEIGHT);
    glVertex3d(-(WATER_TANK_WIDTH / 2.0), -(WATER_TANK_LENGTH / 2.0), WATER_TANK_HEIGHT);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3d(-(WATER_TANK_WIDTH / 2.0), (WATER_TANK_LENGTH / 2.0), 0.0);
    glVertex3d((WATER_TANK_WIDTH / 2.0), (WATER_TANK_LENGTH / 2.0), 0.0);
    glVertex3d((WATER_TANK_WIDTH / 2.0), (WATER_TANK_LENGTH / 2.0), WATER_TANK_HEIGHT);
    glVertex3d(-(WATER_TANK_WIDTH / 2.0), (WATER_TANK_LENGTH / 2.0), WATER_TANK_HEIGHT);
    glEnd();

    glPopMatrix();
}
