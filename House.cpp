/*****************************************************************//**
 * \file   House.cpp
 * \brief  
 * 
 * \author aaron
 * \date   May 2023
 *********************************************************************/

/******************************
*          INCLUDES           *
*******************************/
#include <GL/glut.h>
#include "House.h"
#include "WcPt3D.h"
#include "RGBColor.h"
#include "Utilities.h"
#include "WcVector3D.h"

/******************************
*     FUNCTION DEFINITIONS    *
*******************************/
void renderHouse(WcPt3D position, GLdouble rotationAngle)
{
    static const GLdouble HOUSE_WIDTH = 5.0;
    static const GLdouble HOUSE_LENGTH = 7.0;
    static const GLdouble HOUSE_WALL_HEIGHT = 3.25;
    static const GLdouble HOUSE_ROOF_HEIGHT = 2.0;
    static const GLdouble HOUSE_DOOR_WIDTH = 1.5;
    static const GLdouble HOUSE_DOOR_HEIGHT = 2.25;
    static const GLdouble HOUSE_WINDOW_WIDTH = 0.75;
    static const GLdouble HOUSE_WINDOW_HEIGHT = 1.5;
    static const GLdouble HOUSE_WINDOW_HEIGHT_FROM_GROUND = 1.0;
    static const GLdouble HOUSE_LINE_WIDTH = 1.0;

    /* Lighting */
    static const GLfloat creamColor[] = { RGB_COLOR_CREAM, 1.0 };
    static const GLfloat clayColor[] = { RGB_COLOR_CLAY, 1.0 };
    static const GLfloat brownColor[] = { RGB_COLOR_BROWN, 1.0 };
    static const GLfloat lightBlueColor[] = { RGB_COLOR_LIGHT_BLUE, 1.0 };
    static const GLfloat blackColor[] = { RGB_COLOR_BLACK, 1.0 };
    static const GLfloat whiteColor[] = { RGB_COLOR_WHITE, 1.0 };

    glEnable(GL_LIGHTING);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glTranslated(position.getX(), position.getY(), position.getZ());
    glRotated(rotationAngle, 0.0, 0.0, 1.0);

    /* Walls */
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, creamColor);
    glMaterialfv(GL_FRONT, GL_EMISSION, blackColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, blackColor);

    glBegin(GL_POLYGON);
    glNormal3f(0.0, -1.0, 0.0);
    glVertex3d((HOUSE_WIDTH / 2.0), -(HOUSE_LENGTH / 2.0), 0.0);
    glVertex3d(-(HOUSE_WIDTH / 2.0), -(HOUSE_LENGTH / 2.0), 0.0);
    glVertex3d(-(HOUSE_WIDTH / 2.0), -(HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT);
    glVertex3d((HOUSE_WIDTH / 2.0), -(HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(1.0, 0.0, 0.0);
    glVertex3d((HOUSE_WIDTH / 2.0), -(HOUSE_LENGTH / 2.0), 0.0);
    glVertex3d((HOUSE_WIDTH / 2.0), (HOUSE_LENGTH / 2.0), 0.0);
    glVertex3d((HOUSE_WIDTH / 2.0), (HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT);
    glVertex3d((HOUSE_WIDTH / 2.0), -(HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(-1.0, 0.0, 0.0);
    glVertex3d(-(HOUSE_WIDTH / 2.0), -(HOUSE_LENGTH / 2.0), 0.0);
    glVertex3d(-(HOUSE_WIDTH / 2.0), (HOUSE_LENGTH / 2.0), 0.0);
    glVertex3d(-(HOUSE_WIDTH / 2.0), (HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT);
    glVertex3d(-(HOUSE_WIDTH / 2.0), -(HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(0.0, 1.0, 0.0);
    glVertex3d(-(HOUSE_WIDTH / 2.0), (HOUSE_LENGTH / 2.0), 0.0);
    glVertex3d((HOUSE_WIDTH / 2.0), (HOUSE_LENGTH / 2.0), 0.0);
    glVertex3d((HOUSE_WIDTH / 2.0), (HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT);
    glVertex3d(-(HOUSE_WIDTH / 2.0), (HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT);
    glEnd();

    /* Roof */
    static WcVector3D roofNormal1;
    static WcVector3D roofNormal2;
    static bool calculateRoofNormals = true;
    if (calculateRoofNormals)
    {
        WcPt3D v1(-(HOUSE_WIDTH / 2.0), -(HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT);
        WcPt3D v2(-(HOUSE_WIDTH / 2.0), (HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT);
        WcPt3D v3(0.0, (HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT + HOUSE_ROOF_HEIGHT);
        roofNormal1 = getNormalVector(v1, v2, v3);

        WcPt3D v4((HOUSE_WIDTH / 2.0), -(HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT);
        WcPt3D v5((HOUSE_WIDTH / 2.0), (HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT);
        WcPt3D v6(0.0, -(HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT + HOUSE_ROOF_HEIGHT);
        roofNormal2 = getNormalVector(v4, v5, v6);

        calculateRoofNormals = false;
    }

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, clayColor);
    glMaterialfv(GL_FRONT, GL_EMISSION, blackColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, blackColor);

    glBegin(GL_POLYGON);
    glNormal3f(0.0, -1.0, 0.0);
    glVertex3d(-(HOUSE_WIDTH / 2.0), -(HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT);
    glVertex3d((HOUSE_WIDTH / 2.0), -(HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT);
    glVertex3d(0.0, -(HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT + HOUSE_ROOF_HEIGHT);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(0.0, 1.0, 0.0);
    glVertex3d((HOUSE_WIDTH / 2.0), (HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT);
    glVertex3d(-(HOUSE_WIDTH / 2.0), (HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT);
    glVertex3d(0.0, (HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT + HOUSE_ROOF_HEIGHT);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(roofNormal1.getX(), roofNormal1.getY(), roofNormal1.getZ());
    glVertex3d(-(HOUSE_WIDTH / 2.0), -(HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT);
    glVertex3d(-(HOUSE_WIDTH / 2.0), (HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT);
    glVertex3d(0.0, (HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT + HOUSE_ROOF_HEIGHT);
    glVertex3d(0.0, -(HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT + HOUSE_ROOF_HEIGHT);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(roofNormal2.getX(), roofNormal2.getY(), roofNormal2.getZ());
    glVertex3d((HOUSE_WIDTH / 2.0), -(HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT);
    glVertex3d((HOUSE_WIDTH / 2.0), (HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT);
    glVertex3d(0.0, (HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT + HOUSE_ROOF_HEIGHT);
    glVertex3d(0.0, -(HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT + HOUSE_ROOF_HEIGHT);
    glEnd();

    /* Door */
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, brownColor);
    glMaterialfv(GL_FRONT, GL_EMISSION, blackColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, whiteColor);
    glMaterialf(GL_FRONT, GL_SHININESS, 5.0);

    glBegin(GL_POLYGON);
    glNormal3f(1.0, 0.0, 0.0);
    glVertex3d((HOUSE_WIDTH / 2.0) + 0.01, (HOUSE_DOOR_WIDTH / 2.0), 0.0);
    glVertex3d((HOUSE_WIDTH / 2.0) + 0.01, -(HOUSE_DOOR_WIDTH / 2.0), 0.0);
    glVertex3d((HOUSE_WIDTH / 2.0) + 0.01, -(HOUSE_DOOR_WIDTH / 2.0), HOUSE_DOOR_HEIGHT);
    glVertex3d((HOUSE_WIDTH / 2.0) + 0.01, (HOUSE_DOOR_WIDTH / 2.0), HOUSE_DOOR_HEIGHT);
    glEnd();

    /* Windows */
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, lightBlueColor);
    glMaterialfv(GL_FRONT, GL_EMISSION, blackColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, whiteColor);
    glMaterialf(GL_FRONT, GL_SHININESS, 10.0);

    glBegin(GL_POLYGON);
    glNormal3f(1.0, 0.0, 0.0);
    glVertex3d((HOUSE_WIDTH / 2.0) + 0.01, (HOUSE_LENGTH / 4.0), HOUSE_WINDOW_HEIGHT_FROM_GROUND);
    glVertex3d((HOUSE_WIDTH / 2.0) + 0.01, (HOUSE_LENGTH / 4.0) + HOUSE_WINDOW_WIDTH, HOUSE_WINDOW_HEIGHT_FROM_GROUND);
    glVertex3d((HOUSE_WIDTH / 2.0) + 0.01, (HOUSE_LENGTH / 4.0) + HOUSE_WINDOW_WIDTH, HOUSE_WINDOW_HEIGHT_FROM_GROUND + HOUSE_WINDOW_HEIGHT);
    glVertex3d((HOUSE_WIDTH / 2.0) + 0.01, (HOUSE_LENGTH / 4.0), HOUSE_WINDOW_HEIGHT_FROM_GROUND + HOUSE_WINDOW_HEIGHT);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(1.0, 0.0, 0.0);
    glVertex3d((HOUSE_WIDTH / 2.0) + 0.01, -(HOUSE_LENGTH / 4.0), HOUSE_WINDOW_HEIGHT_FROM_GROUND);
    glVertex3d((HOUSE_WIDTH / 2.0) + 0.01, -(HOUSE_LENGTH / 4.0) - HOUSE_WINDOW_WIDTH, HOUSE_WINDOW_HEIGHT_FROM_GROUND);
    glVertex3d((HOUSE_WIDTH / 2.0) + 0.01, -(HOUSE_LENGTH / 4.0) - HOUSE_WINDOW_WIDTH, HOUSE_WINDOW_HEIGHT_FROM_GROUND + HOUSE_WINDOW_HEIGHT);
    glVertex3d((HOUSE_WIDTH / 2.0) + 0.01, -(HOUSE_LENGTH / 4.0), HOUSE_WINDOW_HEIGHT_FROM_GROUND + HOUSE_WINDOW_HEIGHT);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(-1.0, 0.0, 0.0);
    glVertex3d(-(HOUSE_WIDTH / 2.0) - 0.01, (HOUSE_LENGTH / 4.0), HOUSE_WINDOW_HEIGHT_FROM_GROUND);
    glVertex3d(-(HOUSE_WIDTH / 2.0) - 0.01, (HOUSE_LENGTH / 4.0) + HOUSE_WINDOW_WIDTH, HOUSE_WINDOW_HEIGHT_FROM_GROUND);
    glVertex3d(-(HOUSE_WIDTH / 2.0) - 0.01, (HOUSE_LENGTH / 4.0) + HOUSE_WINDOW_WIDTH, HOUSE_WINDOW_HEIGHT_FROM_GROUND + HOUSE_WINDOW_HEIGHT);
    glVertex3d(-(HOUSE_WIDTH / 2.0) - 0.01, (HOUSE_LENGTH / 4.0), HOUSE_WINDOW_HEIGHT_FROM_GROUND + HOUSE_WINDOW_HEIGHT);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(-1.0, 0.0, 0.0);
    glVertex3d(-(HOUSE_WIDTH / 2.0) - 0.01, -(HOUSE_LENGTH / 4.0), HOUSE_WINDOW_HEIGHT_FROM_GROUND);
    glVertex3d(-(HOUSE_WIDTH / 2.0) - 0.01, -(HOUSE_LENGTH / 4.0) - HOUSE_WINDOW_WIDTH, HOUSE_WINDOW_HEIGHT_FROM_GROUND);
    glVertex3d(-(HOUSE_WIDTH / 2.0) - 0.01, -(HOUSE_LENGTH / 4.0) - HOUSE_WINDOW_WIDTH, HOUSE_WINDOW_HEIGHT_FROM_GROUND + HOUSE_WINDOW_HEIGHT);
    glVertex3d(-(HOUSE_WIDTH / 2.0) - 0.01, -(HOUSE_LENGTH / 4.0), HOUSE_WINDOW_HEIGHT_FROM_GROUND + HOUSE_WINDOW_HEIGHT);
    glEnd();

    glPopMatrix();
    glDisable(GL_LIGHTING);
}
