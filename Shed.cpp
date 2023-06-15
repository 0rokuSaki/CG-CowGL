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
#include "WcVector3D.h"
#include "Utilities.h"
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

    /* Lighting */
    static const GLfloat mediumGrayColor[] = { RGB_COLOR_MEDIUM_GRAY, 1.0 };
    static const GLfloat lightGrayColor[] = { RGB_COLOR_LIGHT_GRAY, 1.0 };
    static const GLfloat blackColor[] = { RGB_COLOR_BLACK, 1.0 };
    static const GLfloat whiteColor[] = { RGB_COLOR_WHITE, 1.0 };

    glEnable(GL_LIGHTING);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glTranslated(position.getX(), position.getY(), position.getZ());
    glRotated(rotationAngle, 0.0, 0.0, 1.0);

    /* Walls */
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mediumGrayColor);
    glMaterialfv(GL_FRONT, GL_EMISSION, blackColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, whiteColor);
    glMaterialf(GL_FRONT, GL_SHININESS, 9.5);

    glBegin(GL_POLYGON);
    glNormal3f(0.0, -1.0, 0.0);
    glVertex3d((SHED_WIDTH / 2.0), -(SHED_LENGTH / 2.0), SHED_EPSILON);
    glVertex3d(-(SHED_WIDTH / 2.0), -(SHED_LENGTH / 2.0), SHED_EPSILON);
    glVertex3d(-(SHED_WIDTH / 2.0), -(SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
    glVertex3d((SHED_WIDTH / 2.0), -(SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(1.0, 0.0, 0.0);
    glVertex3d((SHED_WIDTH / 2.0), -(SHED_LENGTH / 2.0), SHED_EPSILON);
    glVertex3d((SHED_WIDTH / 2.0), (SHED_LENGTH / 2.0), SHED_EPSILON);
    glVertex3d((SHED_WIDTH / 2.0), (SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
    glVertex3d((SHED_WIDTH / 2.0), -(SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(-1.0, 0.0, 0.0);
    glVertex3d(-(SHED_WIDTH / 2.0), -(SHED_LENGTH / 2.0), SHED_EPSILON);
    glVertex3d(-(SHED_WIDTH / 2.0), (SHED_LENGTH / 2.0), SHED_EPSILON);
    glVertex3d(-(SHED_WIDTH / 2.0), (SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
    glVertex3d(-(SHED_WIDTH / 2.0), -(SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(0.0, 1.0, 0.0);
    glVertex3d(-(SHED_WIDTH / 2.0), (SHED_LENGTH / 2.0), SHED_EPSILON);
    glVertex3d((SHED_WIDTH / 2.0), (SHED_LENGTH / 2.0), SHED_EPSILON);
    glVertex3d((SHED_WIDTH / 2.0), (SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
    glVertex3d(-(SHED_WIDTH / 2.0), (SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
    glEnd();

    /* Roof */
    static WcVector3D roofNormal1;
    static WcVector3D roofNormal2;
    static bool calculateRoofNormals = true;
    if (calculateRoofNormals)
    {
        WcPt3D v1(0.0, (SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_ROOF_HEIGHT + SHED_EPSILON);
        WcPt3D v2(-(SHED_WIDTH / 2.0), (SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
        WcPt3D v3(-(SHED_WIDTH / 2.0), -(SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
        roofNormal1 = getNormalVector(v1, v2, v3);

        WcPt3D v4((SHED_WIDTH / 2.0), -(SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
        WcPt3D v5((SHED_WIDTH / 2.0), (SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
        WcPt3D v6(0.0, (SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_ROOF_HEIGHT + SHED_EPSILON);
        roofNormal2 = getNormalVector(v4, v5, v6);

        calculateRoofNormals = false;
    }

    glBegin(GL_POLYGON);
    glNormal3f(0.0, -1.0, 0.0);
    glVertex3d(-(SHED_WIDTH / 2.0), -(SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
    glVertex3d((SHED_WIDTH / 2.0), -(SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
    glVertex3d(0.0, -(SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_ROOF_HEIGHT + SHED_EPSILON);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(0.0, 1.0, 0.0);
    glVertex3d((SHED_WIDTH / 2.0), (SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
    glVertex3d(-(SHED_WIDTH / 2.0), (SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
    glVertex3d(0.0, (SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_ROOF_HEIGHT + SHED_EPSILON);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(roofNormal1.getX(), roofNormal1.getY(), roofNormal1.getZ());
    glVertex3d(-(SHED_WIDTH / 2.0), -(SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
    glVertex3d(-(SHED_WIDTH / 2.0), (SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
    glVertex3d(0.0, (SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_ROOF_HEIGHT + SHED_EPSILON);
    glVertex3d(0.0, -(SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_ROOF_HEIGHT + SHED_EPSILON);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(roofNormal2.getX(), roofNormal2.getY(), roofNormal2.getZ());
    glVertex3d((SHED_WIDTH / 2.0), -(SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
    glVertex3d((SHED_WIDTH / 2.0), (SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_EPSILON);
    glVertex3d(0.0, (SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_ROOF_HEIGHT + SHED_EPSILON);
    glVertex3d(0.0, -(SHED_LENGTH / 2.0), SHED_WALL_HEIGHT + SHED_ROOF_HEIGHT + SHED_EPSILON);
    glEnd();

    /* Door */
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, lightGrayColor);
    glMaterialfv(GL_FRONT, GL_EMISSION, blackColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, whiteColor);
    glMaterialf(GL_FRONT, GL_SHININESS, 5.0);

    glBegin(GL_POLYGON);
    glVertex3d(-(SHED_DOOR_WIDTH / 2.0), (SHED_LENGTH / 2.0) + SHED_EPSILON, SHED_EPSILON);
    glVertex3d((SHED_DOOR_WIDTH / 2.0), (SHED_LENGTH / 2.0) + SHED_EPSILON, SHED_EPSILON);
    glVertex3d((SHED_DOOR_WIDTH / 2.0), (SHED_LENGTH / 2.0) + SHED_EPSILON, SHED_DOOR_HEIGHT);
    glVertex3d(-(SHED_DOOR_WIDTH / 2.0), (SHED_LENGTH / 2.0) + SHED_EPSILON, SHED_DOOR_HEIGHT);
    glEnd();

    glPopMatrix();
    glDisable(GL_LIGHTING);
}
