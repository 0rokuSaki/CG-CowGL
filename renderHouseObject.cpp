/*****************************************************************//**
 * \file   renderHouseObject.cpp
 * \brief  Definition of renderHouseObject function.
 * 
 * \author aaron
 * \date   June 2023
 *********************************************************************/

/******************************
*          INCLUDES           *
*******************************/
#include "renderHouseObject.h"
#include "WcPt3D.h"
#include "RGBColor.h"
#include "Utilities.h"
#include "WcVector3D.h"

/******************************
*     FUNCTION DEFINITIONS    *
*******************************/
void renderHouseObject(const WcPt3D& position, const GLfloat rotationAngle)
{
    /* Dimensions */
    static const GLfloat HOUSE_WIDTH = 5.0;
    static const GLfloat HOUSE_LENGTH = 7.0;
    static const GLfloat HOUSE_WALL_HEIGHT = 3.25;
    static const GLfloat HOUSE_ROOF_HEIGHT = 2.0;
    static const GLfloat HOUSE_DOOR_WIDTH = 1.5;
    static const GLfloat HOUSE_DOOR_HEIGHT = 2.25;
    static const GLfloat HOUSE_WINDOW_WIDTH = 0.75;
    static const GLfloat HOUSE_WINDOW_HEIGHT = 1.5;
    static const GLfloat HOUSE_WINDOW_HEIGHT_FROM_GROUND = 1.0;
    static const GLfloat HOUSE_LINE_WIDTH = 1.0;

    /* Lighting */
    static const GLfloat creamColor[] = { RGB_COLOR_CREAM, 1.0 };
    static const GLfloat clayColor[] = { RGB_COLOR_CLAY, 1.0 };
    static const GLfloat brownColor[] = { RGB_COLOR_BROWN, 1.0 };
    static const GLfloat lightBlueColor[] = { RGB_COLOR_LIGHT_BLUE, 1.0 };
    static const GLfloat blackColor[] = { RGB_COLOR_BLACK, 1.0 };
    static const GLfloat whiteColor[] = { RGB_COLOR_WHITE, 1.0 };
    static const GLfloat DOOR_SHININESS = 10.0;
    static const GLfloat WINDOW_SHININESS = 5.0;

    glEnable(GL_LIGHTING);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glTranslatef(position.getX(), position.getY(), position.getZ());
    glRotatef(rotationAngle, 0.0, 0.0, 1.0);

    /* Walls */
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, creamColor);
    glMaterialfv(GL_FRONT, GL_EMISSION, blackColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, blackColor);

    glBegin(GL_POLYGON);
    glNormal3f(0.0, -1.0, 0.0);
    glVertex3f((HOUSE_WIDTH / 2.0), -(HOUSE_LENGTH / 2.0), 0.0);
    glVertex3f(-(HOUSE_WIDTH / 2.0), -(HOUSE_LENGTH / 2.0), 0.0);
    glVertex3f(-(HOUSE_WIDTH / 2.0), -(HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT);
    glVertex3f((HOUSE_WIDTH / 2.0), -(HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(1.0, 0.0, 0.0);
    glVertex3f((HOUSE_WIDTH / 2.0), -(HOUSE_LENGTH / 2.0), 0.0);
    glVertex3f((HOUSE_WIDTH / 2.0), (HOUSE_LENGTH / 2.0), 0.0);
    glVertex3f((HOUSE_WIDTH / 2.0), (HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT);
    glVertex3f((HOUSE_WIDTH / 2.0), -(HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(-1.0, 0.0, 0.0);
    glVertex3f(-(HOUSE_WIDTH / 2.0), -(HOUSE_LENGTH / 2.0), 0.0);
    glVertex3f(-(HOUSE_WIDTH / 2.0), (HOUSE_LENGTH / 2.0), 0.0);
    glVertex3f(-(HOUSE_WIDTH / 2.0), (HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT);
    glVertex3f(-(HOUSE_WIDTH / 2.0), -(HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(0.0, 1.0, 0.0);
    glVertex3f(-(HOUSE_WIDTH / 2.0), (HOUSE_LENGTH / 2.0), 0.0);
    glVertex3f((HOUSE_WIDTH / 2.0), (HOUSE_LENGTH / 2.0), 0.0);
    glVertex3f((HOUSE_WIDTH / 2.0), (HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT);
    glVertex3f(-(HOUSE_WIDTH / 2.0), (HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT);
    glEnd();

    /* Roof */
    static WcVector3D roofNormal1;
    static WcVector3D roofNormal2;
    static bool calculateRoofNormals = true;
    if (calculateRoofNormals)
    {
        WcPt3D v1(-(HOUSE_WIDTH / 2.0), -(HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT);
        WcPt3D v2(0.0, (HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT + HOUSE_ROOF_HEIGHT);
        WcPt3D v3(-(HOUSE_WIDTH / 2.0), (HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT);
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
    glVertex3f(-(HOUSE_WIDTH / 2.0), -(HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT);
    glVertex3f((HOUSE_WIDTH / 2.0), -(HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT);
    glVertex3f(0.0, -(HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT + HOUSE_ROOF_HEIGHT);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(0.0, 1.0, 0.0);
    glVertex3f((HOUSE_WIDTH / 2.0), (HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT);
    glVertex3f(-(HOUSE_WIDTH / 2.0), (HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT);
    glVertex3f(0.0, (HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT + HOUSE_ROOF_HEIGHT);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(roofNormal1.getX(), roofNormal1.getY(), roofNormal1.getZ());
    glVertex3f(-(HOUSE_WIDTH / 2.0), -(HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT);
    glVertex3f(-(HOUSE_WIDTH / 2.0), (HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT);
    glVertex3f(0.0, (HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT + HOUSE_ROOF_HEIGHT);
    glVertex3f(0.0, -(HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT + HOUSE_ROOF_HEIGHT);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(roofNormal2.getX(), roofNormal2.getY(), roofNormal2.getZ());
    glVertex3f((HOUSE_WIDTH / 2.0), -(HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT);
    glVertex3f((HOUSE_WIDTH / 2.0), (HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT);
    glVertex3f(0.0, (HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT + HOUSE_ROOF_HEIGHT);
    glVertex3f(0.0, -(HOUSE_LENGTH / 2.0), HOUSE_WALL_HEIGHT + HOUSE_ROOF_HEIGHT);
    glEnd();

    /* Door */
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, brownColor);
    glMaterialfv(GL_FRONT, GL_EMISSION, blackColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, whiteColor);
    glMaterialf(GL_FRONT, GL_SHININESS, DOOR_SHININESS);

    glBegin(GL_POLYGON);
    glNormal3f(1.0, 0.0, 0.0);
    glVertex3f((HOUSE_WIDTH / 2.0) + 0.01, (HOUSE_DOOR_WIDTH / 2.0), 0.0);
    glVertex3f((HOUSE_WIDTH / 2.0) + 0.01, -(HOUSE_DOOR_WIDTH / 2.0), 0.0);
    glVertex3f((HOUSE_WIDTH / 2.0) + 0.01, -(HOUSE_DOOR_WIDTH / 2.0), HOUSE_DOOR_HEIGHT);
    glVertex3f((HOUSE_WIDTH / 2.0) + 0.01, (HOUSE_DOOR_WIDTH / 2.0), HOUSE_DOOR_HEIGHT);
    glEnd();

    /* Windows */
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, lightBlueColor);
    glMaterialfv(GL_FRONT, GL_EMISSION, blackColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, whiteColor);
    glMaterialf(GL_FRONT, GL_SHININESS, WINDOW_SHININESS);

    glBegin(GL_POLYGON);
    glNormal3f(1.0, 0.0, 0.0);
    glVertex3f((HOUSE_WIDTH / 2.0) + 0.01, (HOUSE_LENGTH / 4.0), HOUSE_WINDOW_HEIGHT_FROM_GROUND);
    glVertex3f((HOUSE_WIDTH / 2.0) + 0.01, (HOUSE_LENGTH / 4.0) + HOUSE_WINDOW_WIDTH, HOUSE_WINDOW_HEIGHT_FROM_GROUND);
    glVertex3f((HOUSE_WIDTH / 2.0) + 0.01, (HOUSE_LENGTH / 4.0) + HOUSE_WINDOW_WIDTH, HOUSE_WINDOW_HEIGHT_FROM_GROUND + HOUSE_WINDOW_HEIGHT);
    glVertex3f((HOUSE_WIDTH / 2.0) + 0.01, (HOUSE_LENGTH / 4.0), HOUSE_WINDOW_HEIGHT_FROM_GROUND + HOUSE_WINDOW_HEIGHT);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(1.0, 0.0, 0.0);
    glVertex3f((HOUSE_WIDTH / 2.0) + 0.01, -(HOUSE_LENGTH / 4.0), HOUSE_WINDOW_HEIGHT_FROM_GROUND);
    glVertex3f((HOUSE_WIDTH / 2.0) + 0.01, -(HOUSE_LENGTH / 4.0) - HOUSE_WINDOW_WIDTH, HOUSE_WINDOW_HEIGHT_FROM_GROUND);
    glVertex3f((HOUSE_WIDTH / 2.0) + 0.01, -(HOUSE_LENGTH / 4.0) - HOUSE_WINDOW_WIDTH, HOUSE_WINDOW_HEIGHT_FROM_GROUND + HOUSE_WINDOW_HEIGHT);
    glVertex3f((HOUSE_WIDTH / 2.0) + 0.01, -(HOUSE_LENGTH / 4.0), HOUSE_WINDOW_HEIGHT_FROM_GROUND + HOUSE_WINDOW_HEIGHT);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(-1.0, 0.0, 0.0);
    glVertex3f(-(HOUSE_WIDTH / 2.0) - 0.01, (HOUSE_LENGTH / 4.0), HOUSE_WINDOW_HEIGHT_FROM_GROUND);
    glVertex3f(-(HOUSE_WIDTH / 2.0) - 0.01, (HOUSE_LENGTH / 4.0) + HOUSE_WINDOW_WIDTH, HOUSE_WINDOW_HEIGHT_FROM_GROUND);
    glVertex3f(-(HOUSE_WIDTH / 2.0) - 0.01, (HOUSE_LENGTH / 4.0) + HOUSE_WINDOW_WIDTH, HOUSE_WINDOW_HEIGHT_FROM_GROUND + HOUSE_WINDOW_HEIGHT);
    glVertex3f(-(HOUSE_WIDTH / 2.0) - 0.01, (HOUSE_LENGTH / 4.0), HOUSE_WINDOW_HEIGHT_FROM_GROUND + HOUSE_WINDOW_HEIGHT);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(-1.0, 0.0, 0.0);
    glVertex3f(-(HOUSE_WIDTH / 2.0) - 0.01, -(HOUSE_LENGTH / 4.0), HOUSE_WINDOW_HEIGHT_FROM_GROUND);
    glVertex3f(-(HOUSE_WIDTH / 2.0) - 0.01, -(HOUSE_LENGTH / 4.0) - HOUSE_WINDOW_WIDTH, HOUSE_WINDOW_HEIGHT_FROM_GROUND);
    glVertex3f(-(HOUSE_WIDTH / 2.0) - 0.01, -(HOUSE_LENGTH / 4.0) - HOUSE_WINDOW_WIDTH, HOUSE_WINDOW_HEIGHT_FROM_GROUND + HOUSE_WINDOW_HEIGHT);
    glVertex3f(-(HOUSE_WIDTH / 2.0) - 0.01, -(HOUSE_LENGTH / 4.0), HOUSE_WINDOW_HEIGHT_FROM_GROUND + HOUSE_WINDOW_HEIGHT);
    glEnd();

    glPopMatrix();
    glDisable(GL_LIGHTING);
}
