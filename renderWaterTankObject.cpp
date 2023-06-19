/*****************************************************************//**
 * \file   renderWaterTankObject.cpp
 * \brief  Definition of renderWaterTankObject function.
 * 
 * \author aaron
 * \date   June 2023
 *********************************************************************/

/******************************
*          INCLUDES           *
*******************************/
#include "renderWaterTankObject.h"
#include "WcPt3D.h"
#include "RGBColor.h"

/******************************
*     FUNCTION DEFINITIONS    *
*******************************/
void renderWaterTank(const WcPt3D& position, const GLfloat rotationAngle)
{
    static const GLfloat WATER_TANK_WIDTH = 1.0;
    static const GLfloat WATER_TANK_LENGTH = 3.0;
    static const GLfloat WATER_TANK_HEIGHT = 0.5;
    static const GLfloat WATER_TANK_WATER_LEVEL = 0.35;
    static const GLfloat WATER_TANK_LINE_WIDTH = 1.0;

    /* Lighting */
    static const GLfloat darkGrayColor[] = { RGB_COLOR_DARK_GRAY, 1.0 };
    static const GLfloat waterBlueColor[] = { RGB_COLOR_WATER_BLUE, 1.0 };
    static const GLfloat blackColor[] = { RGB_COLOR_BLACK, 1.0 };
    static const GLfloat whiteColor[] = { RGB_COLOR_WHITE, 1.0 };
    static const GLfloat WALL_SHININESS = 15;
    static const GLfloat WATER_SHININESS = 20;

    glEnable(GL_LIGHTING);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glRotatef(rotationAngle, 0.0, 0.0, 1.0);
    glTranslatef(position.getX(), position.getY(), position.getZ());

    /* Water tank walls */
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, darkGrayColor);
    glMaterialfv(GL_FRONT, GL_EMISSION, blackColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, whiteColor);
    glMaterialf(GL_FRONT, GL_SHININESS, WALL_SHININESS);

    glBegin(GL_POLYGON);
    glNormal3f(0.0, -1.0, 0.0);
    glVertex3f((WATER_TANK_WIDTH / 2.0), -(WATER_TANK_LENGTH / 2.0), 0.0);
    glVertex3f(-(WATER_TANK_WIDTH / 2.0), -(WATER_TANK_LENGTH / 2.0), 0.0);
    glVertex3f(-(WATER_TANK_WIDTH / 2.0), -(WATER_TANK_LENGTH / 2.0), WATER_TANK_HEIGHT);
    glVertex3f((WATER_TANK_WIDTH / 2.0), -(WATER_TANK_LENGTH / 2.0), WATER_TANK_HEIGHT);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(1.0, 0.0, 0.0);
    glVertex3f((WATER_TANK_WIDTH / 2.0), -(WATER_TANK_LENGTH / 2.0), 0.0);
    glVertex3f((WATER_TANK_WIDTH / 2.0), (WATER_TANK_LENGTH / 2.0), 0.0);
    glVertex3f((WATER_TANK_WIDTH / 2.0), (WATER_TANK_LENGTH / 2.0), WATER_TANK_HEIGHT);
    glVertex3f((WATER_TANK_WIDTH / 2.0), -(WATER_TANK_LENGTH / 2.0), WATER_TANK_HEIGHT);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(-1.0, 0.0, 0.0);
    glVertex3f(-(WATER_TANK_WIDTH / 2.0), -(WATER_TANK_LENGTH / 2.0), 0.0);
    glVertex3f(-(WATER_TANK_WIDTH / 2.0), (WATER_TANK_LENGTH / 2.0), 0.0);
    glVertex3f(-(WATER_TANK_WIDTH / 2.0), (WATER_TANK_LENGTH / 2.0), WATER_TANK_HEIGHT);
    glVertex3f(-(WATER_TANK_WIDTH / 2.0), -(WATER_TANK_LENGTH / 2.0), WATER_TANK_HEIGHT);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(0.0, 1.0, 0.0);
    glVertex3f(-(WATER_TANK_WIDTH / 2.0), (WATER_TANK_LENGTH / 2.0), 0.0);
    glVertex3f((WATER_TANK_WIDTH / 2.0), (WATER_TANK_LENGTH / 2.0), 0.0);
    glVertex3f((WATER_TANK_WIDTH / 2.0), (WATER_TANK_LENGTH / 2.0), WATER_TANK_HEIGHT);
    glVertex3f(-(WATER_TANK_WIDTH / 2.0), (WATER_TANK_LENGTH / 2.0), WATER_TANK_HEIGHT);
    glEnd();

    /* Water */
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, waterBlueColor);
    glMaterialfv(GL_FRONT, GL_EMISSION, blackColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, whiteColor);
    glMaterialf(GL_FRONT, GL_SHININESS, WATER_SHININESS);

    glBegin(GL_POLYGON);
    glNormal3f(0.0, 0.0, 1.0);
    glVertex3f(-(WATER_TANK_WIDTH / 2.0), -(WATER_TANK_LENGTH / 2.0), WATER_TANK_WATER_LEVEL);
    glVertex3f((WATER_TANK_WIDTH / 2.0), -(WATER_TANK_LENGTH / 2.0), WATER_TANK_WATER_LEVEL);
    glVertex3f((WATER_TANK_WIDTH / 2.0), (WATER_TANK_LENGTH / 2.0), WATER_TANK_WATER_LEVEL);
    glVertex3f(-(WATER_TANK_WIDTH / 2.0), (WATER_TANK_LENGTH / 2.0), WATER_TANK_WATER_LEVEL);
    glEnd();

    glPopMatrix();
    glDisable(GL_LIGHTING);
}
