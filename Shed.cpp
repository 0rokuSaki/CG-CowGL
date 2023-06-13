/*****************************************************************//**
 * \file   Shed.cpp
 * \brief  
 * 
 * \author aaron
 * \date   June 2023
 *********************************************************************/

/******************************
*          INCLUDES           *
*******************************/
#include <GL/glut.h>
#include "SHED.h"
#include "WcPt3D.h"
#include "RGBColor.h"

/******************************
*     FUNCTION DEFINITIONS    *
*******************************/
void renderShed(WcPt3D position, GLdouble rotationAngle)
{
    static const GLdouble SHED_WIDTH = 3.0;
    static const GLdouble SHED_LENGTH = 4.0;
    static const GLdouble SHED_WALL_HEIGHT = 2.5;
    static const GLdouble SHED_ROOF_HEIGHT = 1.0;
    static const GLdouble SHED_DOOR_WIDTH = 1.5;
    static const GLdouble SHED_DOOR_HEIGHT = 2.5;
    static const GLdouble SHED_EPSILON = 0.025;
    static const GLdouble SHED_LINE_WIDTH = 1.0;

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glTranslated(position.getX(), position.getY(), position.getZ());
    glRotated(rotationAngle, 0.0, 0.0, 1.0);

    /* Walls */
    glColor3d(RGB_COLOR_MEDIUM_GRAY);

    glBegin(GL_POLYGON);
    glVertex3d((SHED_WIDTH / 2.0), -(SHED_LENGTH / 2.0), SHED_EPSILON);
    glVertex3d(-(SHED_WIDTH / 2.0), -(SHED_LENGTH / 2.0), SHED_EPSILON);
    glVertex3d(-(SHED_WIDTH / 2.0), -(SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
    glVertex3d((SHED_WIDTH / 2.0), -(SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3d((SHED_WIDTH / 2.0), -(SHED_LENGTH / 2.0), SHED_EPSILON);
    glVertex3d((SHED_WIDTH / 2.0), (SHED_LENGTH / 2.0), SHED_EPSILON);
    glVertex3d((SHED_WIDTH / 2.0), (SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
    glVertex3d((SHED_WIDTH / 2.0), -(SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3d(-(SHED_WIDTH / 2.0), -(SHED_LENGTH / 2.0), SHED_EPSILON);
    glVertex3d(-(SHED_WIDTH / 2.0), (SHED_LENGTH / 2.0), SHED_EPSILON);
    glVertex3d(-(SHED_WIDTH / 2.0), (SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
    glVertex3d(-(SHED_WIDTH / 2.0), -(SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3d(-(SHED_WIDTH / 2.0), (SHED_LENGTH / 2.0), SHED_EPSILON);
    glVertex3d((SHED_WIDTH / 2.0), (SHED_LENGTH / 2.0), SHED_EPSILON);
    glVertex3d((SHED_WIDTH / 2.0), (SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
    glVertex3d(-(SHED_WIDTH / 2.0), (SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
    glEnd();

    /* Roof */
    glBegin(GL_POLYGON);
    glVertex3d(-(SHED_WIDTH / 2.0), -(SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
    glVertex3d((SHED_WIDTH / 2.0), -(SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
    glVertex3d(0.0, -(SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_ROOF_HEIGHT + SHED_EPSILON);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3d((SHED_WIDTH / 2.0), (SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
    glVertex3d(-(SHED_WIDTH / 2.0), (SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
    glVertex3d(0.0, (SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_ROOF_HEIGHT + SHED_EPSILON);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3d(-(SHED_WIDTH / 2.0), -(SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
    glVertex3d(-(SHED_WIDTH / 2.0), (SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
    glVertex3d(0.0, (SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_ROOF_HEIGHT + SHED_EPSILON);
    glVertex3d(0.0, -(SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_ROOF_HEIGHT + SHED_EPSILON);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3d((SHED_WIDTH / 2.0), -(SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
    glVertex3d((SHED_WIDTH / 2.0), (SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
    glVertex3d(0.0, (SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_ROOF_HEIGHT + SHED_EPSILON);
    glVertex3d(0.0, -(SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_ROOF_HEIGHT + SHED_EPSILON);
    glEnd();

    /* Door */
    glColor3d(RGB_COLOR_LIGHT_GRAY);

    glBegin(GL_POLYGON);
    glVertex3d(-(SHED_DOOR_WIDTH / 2.0), (SHED_LENGTH / 2.0) + SHED_EPSILON, SHED_EPSILON);
    glVertex3d((SHED_DOOR_WIDTH / 2.0), (SHED_LENGTH / 2.0) + SHED_EPSILON, SHED_EPSILON);
    glVertex3d((SHED_DOOR_WIDTH / 2.0), (SHED_LENGTH / 2.0) + SHED_EPSILON, SHED_DOOR_HEIGHT);
    glVertex3d(-(SHED_DOOR_WIDTH / 2.0), (SHED_LENGTH / 2.0) + SHED_EPSILON, SHED_DOOR_HEIGHT);
    glEnd();

    /* Walls frame */
    glColor3d(RGB_COLOR_BLACK);
    glLineWidth(SHED_LINE_WIDTH);

    glBegin(GL_LINE_LOOP);
    glVertex3d((SHED_WIDTH / 2.0), -(SHED_LENGTH / 2.0), SHED_EPSILON);
    glVertex3d(-(SHED_WIDTH / 2.0), -(SHED_LENGTH / 2.0), SHED_EPSILON);
    glVertex3d(-(SHED_WIDTH / 2.0), -(SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
    glVertex3d((SHED_WIDTH / 2.0), -(SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3d((SHED_WIDTH / 2.0), -(SHED_LENGTH / 2.0), SHED_EPSILON);
    glVertex3d((SHED_WIDTH / 2.0), (SHED_LENGTH / 2.0), SHED_EPSILON);
    glVertex3d((SHED_WIDTH / 2.0), (SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
    glVertex3d((SHED_WIDTH / 2.0), -(SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3d(-(SHED_WIDTH / 2.0), -(SHED_LENGTH / 2.0), SHED_EPSILON);
    glVertex3d(-(SHED_WIDTH / 2.0), (SHED_LENGTH / 2.0), SHED_EPSILON);
    glVertex3d(-(SHED_WIDTH / 2.0), (SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
    glVertex3d(-(SHED_WIDTH / 2.0), -(SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3d(-(SHED_WIDTH / 2.0), (SHED_LENGTH / 2.0), SHED_EPSILON);
    glVertex3d((SHED_WIDTH / 2.0), (SHED_LENGTH / 2.0), SHED_EPSILON);
    glVertex3d((SHED_WIDTH / 2.0), (SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
    glVertex3d(-(SHED_WIDTH / 2.0), (SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
    glEnd();

    /* Roof frame */
    glBegin(GL_LINE_LOOP);
    glVertex3d(-(SHED_WIDTH / 2.0), -(SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
    glVertex3d((SHED_WIDTH / 2.0), -(SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
    glVertex3d(0.0, -(SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_ROOF_HEIGHT + SHED_EPSILON);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3d((SHED_WIDTH / 2.0), (SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
    glVertex3d(-(SHED_WIDTH / 2.0), (SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
    glVertex3d(0.0, (SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_ROOF_HEIGHT + SHED_EPSILON);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3d(-(SHED_WIDTH / 2.0), -(SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
    glVertex3d(-(SHED_WIDTH / 2.0), (SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
    glVertex3d(0.0, (SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_ROOF_HEIGHT + SHED_EPSILON);
    glVertex3d(0.0, -(SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_ROOF_HEIGHT + SHED_EPSILON);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3d((SHED_WIDTH / 2.0), -(SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
    glVertex3d((SHED_WIDTH / 2.0), (SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
    glVertex3d(0.0, (SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_ROOF_HEIGHT + SHED_EPSILON);
    glVertex3d(0.0, -(SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_ROOF_HEIGHT + SHED_EPSILON);
    glEnd();

    /* Door frame */
    glBegin(GL_LINE_LOOP);
    glVertex3d(-(SHED_DOOR_WIDTH / 2.0), (SHED_LENGTH / 2.0) + SHED_EPSILON, SHED_EPSILON);
    glVertex3d((SHED_DOOR_WIDTH / 2.0), (SHED_LENGTH / 2.0) + SHED_EPSILON, SHED_EPSILON);
    glVertex3d((SHED_DOOR_WIDTH / 2.0), (SHED_LENGTH / 2.0) + SHED_EPSILON, SHED_DOOR_HEIGHT);
    glVertex3d(-(SHED_DOOR_WIDTH / 2.0), (SHED_LENGTH / 2.0) + SHED_EPSILON, SHED_DOOR_HEIGHT);
    glEnd();

    glPopMatrix();
}
