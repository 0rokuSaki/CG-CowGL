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

/******************************
*     FUNCTION DEFINITIONS    *
*******************************/

/**
 * Render a simple grey house with red roof tiles.
 *
 * \param center Coordinates of the centroid of the bottom rectangle ("Floor") of the house.
 */
void renderHouse(WcPt3D center)
{
    /* Walls */
    glColor3d(RGB_COLOR_LIGHT_GRAY);
    glBegin(GL_POLYGON);
    glVertex3d(center.getX() + (HOUSE_WIDTH / 2.0), center.getY() - (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_EPSILON);
    glVertex3d(center.getX() - (HOUSE_WIDTH / 2.0), center.getY() - (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_EPSILON);
    glVertex3d(center.getX() - (HOUSE_WIDTH / 2.0), center.getY() - (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_WALL_HEIGHT + HOUSE_EPSILON);
    glVertex3d(center.getX() + (HOUSE_WIDTH / 2.0), center.getY() - (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_WALL_HEIGHT + HOUSE_EPSILON);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3d(center.getX() + (HOUSE_WIDTH / 2.0), center.getY() - (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_EPSILON);
    glVertex3d(center.getX() + (HOUSE_WIDTH / 2.0), center.getY() + (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_EPSILON);
    glVertex3d(center.getX() + (HOUSE_WIDTH / 2.0), center.getY() + (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_WALL_HEIGHT + HOUSE_EPSILON);
    glVertex3d(center.getX() + (HOUSE_WIDTH / 2.0), center.getY() - (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_WALL_HEIGHT + HOUSE_EPSILON);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3d(center.getX() - (HOUSE_WIDTH / 2.0), center.getY() - (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_EPSILON);
    glVertex3d(center.getX() - (HOUSE_WIDTH / 2.0), center.getY() + (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_EPSILON);
    glVertex3d(center.getX() - (HOUSE_WIDTH / 2.0), center.getY() + (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_WALL_HEIGHT + HOUSE_EPSILON);
    glVertex3d(center.getX() - (HOUSE_WIDTH / 2.0), center.getY() - (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_WALL_HEIGHT + HOUSE_EPSILON);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3d(center.getX() - (HOUSE_WIDTH / 2.0), center.getY() + (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_EPSILON);
    glVertex3d(center.getX() + (HOUSE_WIDTH / 2.0), center.getY() + (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_EPSILON);
    glVertex3d(center.getX() + (HOUSE_WIDTH / 2.0), center.getY() + (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_WALL_HEIGHT + HOUSE_EPSILON);
    glVertex3d(center.getX() - (HOUSE_WIDTH / 2.0), center.getY() + (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_WALL_HEIGHT + HOUSE_EPSILON);
    glEnd();

    /* Roof */
    glColor3d(RGB_COLOR_RED);
    glBegin(GL_POLYGON);
    glVertex3d(center.getX() - (HOUSE_WIDTH / 2.0), center.getY() - (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_WALL_HEIGHT + HOUSE_EPSILON);
    glVertex3d(center.getX() + (HOUSE_WIDTH / 2.0), center.getY() - (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_WALL_HEIGHT + HOUSE_EPSILON);
    glVertex3d(center.getX(), center.getY() - (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_WALL_HEIGHT + HOUSE_ROOF_HEIGHT + HOUSE_EPSILON);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3d(center.getX() + (HOUSE_WIDTH / 2.0), center.getY() + (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_WALL_HEIGHT + HOUSE_EPSILON);
    glVertex3d(center.getX() - (HOUSE_WIDTH / 2.0), center.getY() + (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_WALL_HEIGHT + HOUSE_EPSILON);
    glVertex3d(center.getX(), center.getY() + (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_WALL_HEIGHT + HOUSE_ROOF_HEIGHT + HOUSE_EPSILON);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3d(center.getX() - (HOUSE_WIDTH / 2.0), center.getY() - (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_WALL_HEIGHT + HOUSE_EPSILON);
    glVertex3d(center.getX() - (HOUSE_WIDTH / 2.0), center.getY() + (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_WALL_HEIGHT + HOUSE_EPSILON);
    glVertex3d(center.getX(), center.getY() + (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_WALL_HEIGHT + HOUSE_ROOF_HEIGHT + HOUSE_EPSILON);
    glVertex3d(center.getX(), center.getY() - (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_WALL_HEIGHT + HOUSE_ROOF_HEIGHT + HOUSE_EPSILON);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3d(center.getX() + (HOUSE_WIDTH / 2.0), center.getY() - (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_WALL_HEIGHT + HOUSE_EPSILON);
    glVertex3d(center.getX() + (HOUSE_WIDTH / 2.0), center.getY() + (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_WALL_HEIGHT + HOUSE_EPSILON);
    glVertex3d(center.getX(), center.getY() + (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_WALL_HEIGHT + HOUSE_ROOF_HEIGHT + HOUSE_EPSILON);
    glVertex3d(center.getX(), center.getY() - (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_WALL_HEIGHT + HOUSE_ROOF_HEIGHT + HOUSE_EPSILON);
    glEnd();

    /* Door */
    glColor3d(RGB_COLOR_LIGHT_BROWN);
    glBegin(GL_POLYGON);
    glVertex3d(center.getX() + (HOUSE_WIDTH / 2.0) + HOUSE_EPSILON, center.getY() + (HOUSE_DOOR_WIDTH / 2.0), center.getZ() + HOUSE_EPSILON);
    glVertex3d(center.getX() + (HOUSE_WIDTH / 2.0) + HOUSE_EPSILON, center.getY() - (HOUSE_DOOR_WIDTH / 2.0), center.getZ() + HOUSE_EPSILON);
    glVertex3d(center.getX() + (HOUSE_WIDTH / 2.0) + HOUSE_EPSILON, center.getY() - (HOUSE_DOOR_WIDTH / 2.0), center.getZ() + HOUSE_DOOR_HEIGHT);
    glVertex3d(center.getX() + (HOUSE_WIDTH / 2.0) + HOUSE_EPSILON, center.getY() + (HOUSE_DOOR_WIDTH / 2.0), center.getZ() + HOUSE_DOOR_HEIGHT);
    glEnd();

    /* Windows */
    glColor3d(RGB_COLOR_LIGHT_BLUE);
    glBegin(GL_POLYGON);
    glVertex3d(center.getX() + (HOUSE_WIDTH / 2.0) + HOUSE_EPSILON, center.getY() + (HOUSE_LENGTH / 4.0), center.getZ() + HOUSE_WINDOW_HEIGHT_FROM_GROUND);
    glVertex3d(center.getX() + (HOUSE_WIDTH / 2.0) + HOUSE_EPSILON, center.getY() + (HOUSE_LENGTH / 4.0) + HOUSE_WINDOW_WIDTH, center.getZ() + HOUSE_WINDOW_HEIGHT_FROM_GROUND);
    glVertex3d(center.getX() + (HOUSE_WIDTH / 2.0) + HOUSE_EPSILON, center.getY() + (HOUSE_LENGTH / 4.0) + HOUSE_WINDOW_WIDTH, center.getZ() + HOUSE_WINDOW_HEIGHT_FROM_GROUND + HOUSE_WINDOW_HEIGHT);
    glVertex3d(center.getX() + (HOUSE_WIDTH / 2.0) + HOUSE_EPSILON, center.getY() + (HOUSE_LENGTH / 4.0), center.getZ() + HOUSE_WINDOW_HEIGHT_FROM_GROUND + HOUSE_WINDOW_HEIGHT);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3d(center.getX() + (HOUSE_WIDTH / 2.0) + HOUSE_EPSILON, center.getY() - (HOUSE_LENGTH / 4.0), center.getZ() + HOUSE_WINDOW_HEIGHT_FROM_GROUND);
    glVertex3d(center.getX() + (HOUSE_WIDTH / 2.0) + HOUSE_EPSILON, center.getY() - (HOUSE_LENGTH / 4.0) - HOUSE_WINDOW_WIDTH, center.getZ() + HOUSE_WINDOW_HEIGHT_FROM_GROUND);
    glVertex3d(center.getX() + (HOUSE_WIDTH / 2.0) + HOUSE_EPSILON, center.getY() - (HOUSE_LENGTH / 4.0) - HOUSE_WINDOW_WIDTH, center.getZ() + HOUSE_WINDOW_HEIGHT_FROM_GROUND + HOUSE_WINDOW_HEIGHT);
    glVertex3d(center.getX() + (HOUSE_WIDTH / 2.0) + HOUSE_EPSILON, center.getY() - (HOUSE_LENGTH / 4.0), center.getZ() + HOUSE_WINDOW_HEIGHT_FROM_GROUND + HOUSE_WINDOW_HEIGHT);
    glEnd();

    glColor3d(RGB_COLOR_LIGHT_BLUE);
    glBegin(GL_POLYGON);
    glVertex3d(center.getX() - (HOUSE_WIDTH / 2.0) - HOUSE_EPSILON, center.getY() + (HOUSE_LENGTH / 4.0), center.getZ() + HOUSE_WINDOW_HEIGHT_FROM_GROUND);
    glVertex3d(center.getX() - (HOUSE_WIDTH / 2.0) - HOUSE_EPSILON, center.getY() + (HOUSE_LENGTH / 4.0) + HOUSE_WINDOW_WIDTH, center.getZ() + HOUSE_WINDOW_HEIGHT_FROM_GROUND);
    glVertex3d(center.getX() - (HOUSE_WIDTH / 2.0) - HOUSE_EPSILON, center.getY() + (HOUSE_LENGTH / 4.0) + HOUSE_WINDOW_WIDTH, center.getZ() + HOUSE_WINDOW_HEIGHT_FROM_GROUND + HOUSE_WINDOW_HEIGHT);
    glVertex3d(center.getX() - (HOUSE_WIDTH / 2.0) - HOUSE_EPSILON, center.getY() + (HOUSE_LENGTH / 4.0), center.getZ() + HOUSE_WINDOW_HEIGHT_FROM_GROUND + HOUSE_WINDOW_HEIGHT);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3d(center.getX() - (HOUSE_WIDTH / 2.0) - HOUSE_EPSILON, center.getY() - (HOUSE_LENGTH / 4.0), center.getZ() + HOUSE_WINDOW_HEIGHT_FROM_GROUND);
    glVertex3d(center.getX() - (HOUSE_WIDTH / 2.0) - HOUSE_EPSILON, center.getY() - (HOUSE_LENGTH / 4.0) - HOUSE_WINDOW_WIDTH, center.getZ() + HOUSE_WINDOW_HEIGHT_FROM_GROUND);
    glVertex3d(center.getX() - (HOUSE_WIDTH / 2.0) - HOUSE_EPSILON, center.getY() - (HOUSE_LENGTH / 4.0) - HOUSE_WINDOW_WIDTH, center.getZ() + HOUSE_WINDOW_HEIGHT_FROM_GROUND + HOUSE_WINDOW_HEIGHT);
    glVertex3d(center.getX() - (HOUSE_WIDTH / 2.0) - HOUSE_EPSILON, center.getY() - (HOUSE_LENGTH / 4.0), center.getZ() + HOUSE_WINDOW_HEIGHT_FROM_GROUND + HOUSE_WINDOW_HEIGHT);
    glEnd();

    /* Walls frame */
    glColor3d(RGB_COLOR_BLACK);
    glBegin(GL_LINE_LOOP);
    glVertex3d(center.getX() + (HOUSE_WIDTH / 2.0), center.getY() - (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_EPSILON);
    glVertex3d(center.getX() - (HOUSE_WIDTH / 2.0), center.getY() - (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_EPSILON);
    glVertex3d(center.getX() - (HOUSE_WIDTH / 2.0), center.getY() - (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_WALL_HEIGHT + HOUSE_EPSILON);
    glVertex3d(center.getX() + (HOUSE_WIDTH / 2.0), center.getY() - (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_WALL_HEIGHT + HOUSE_EPSILON);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3d(center.getX() + (HOUSE_WIDTH / 2.0), center.getY() - (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_EPSILON);
    glVertex3d(center.getX() + (HOUSE_WIDTH / 2.0), center.getY() + (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_EPSILON);
    glVertex3d(center.getX() + (HOUSE_WIDTH / 2.0), center.getY() + (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_WALL_HEIGHT + HOUSE_EPSILON);
    glVertex3d(center.getX() + (HOUSE_WIDTH / 2.0), center.getY() - (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_WALL_HEIGHT + HOUSE_EPSILON);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3d(center.getX() - (HOUSE_WIDTH / 2.0), center.getY() - (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_EPSILON);
    glVertex3d(center.getX() - (HOUSE_WIDTH / 2.0), center.getY() + (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_EPSILON);
    glVertex3d(center.getX() - (HOUSE_WIDTH / 2.0), center.getY() + (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_WALL_HEIGHT + HOUSE_EPSILON);
    glVertex3d(center.getX() - (HOUSE_WIDTH / 2.0), center.getY() - (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_WALL_HEIGHT + HOUSE_EPSILON);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3d(center.getX() - (HOUSE_WIDTH / 2.0), center.getY() + (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_EPSILON);
    glVertex3d(center.getX() + (HOUSE_WIDTH / 2.0), center.getY() + (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_EPSILON);
    glVertex3d(center.getX() + (HOUSE_WIDTH / 2.0), center.getY() + (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_WALL_HEIGHT + HOUSE_EPSILON);
    glVertex3d(center.getX() - (HOUSE_WIDTH / 2.0), center.getY() + (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_WALL_HEIGHT + HOUSE_EPSILON);
    glEnd();

    /* Roof frame */
    glColor3d(RGB_COLOR_BLACK);
    glBegin(GL_LINE_LOOP);
    glVertex3d(center.getX() - (HOUSE_WIDTH / 2.0), center.getY() - (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_WALL_HEIGHT + HOUSE_EPSILON);
    glVertex3d(center.getX() + (HOUSE_WIDTH / 2.0), center.getY() - (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_WALL_HEIGHT + HOUSE_EPSILON);
    glVertex3d(center.getX(), center.getY() - (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_WALL_HEIGHT + HOUSE_ROOF_HEIGHT + HOUSE_EPSILON);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3d(center.getX() + (HOUSE_WIDTH / 2.0), center.getY() + (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_WALL_HEIGHT + HOUSE_EPSILON);
    glVertex3d(center.getX() - (HOUSE_WIDTH / 2.0), center.getY() + (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_WALL_HEIGHT + HOUSE_EPSILON);
    glVertex3d(center.getX(), center.getY() + (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_WALL_HEIGHT + HOUSE_ROOF_HEIGHT + HOUSE_EPSILON);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3d(center.getX() - (HOUSE_WIDTH / 2.0), center.getY() - (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_WALL_HEIGHT + HOUSE_EPSILON);
    glVertex3d(center.getX() - (HOUSE_WIDTH / 2.0), center.getY() + (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_WALL_HEIGHT + HOUSE_EPSILON);
    glVertex3d(center.getX(), center.getY() + (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_WALL_HEIGHT + HOUSE_ROOF_HEIGHT + HOUSE_EPSILON);
    glVertex3d(center.getX(), center.getY() - (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_WALL_HEIGHT + HOUSE_ROOF_HEIGHT + HOUSE_EPSILON);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3d(center.getX() + (HOUSE_WIDTH / 2.0), center.getY() - (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_WALL_HEIGHT + HOUSE_EPSILON);
    glVertex3d(center.getX() + (HOUSE_WIDTH / 2.0), center.getY() + (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_WALL_HEIGHT + HOUSE_EPSILON);
    glVertex3d(center.getX(), center.getY() + (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_WALL_HEIGHT + HOUSE_ROOF_HEIGHT + HOUSE_EPSILON);
    glVertex3d(center.getX(), center.getY() - (HOUSE_LENGTH / 2.0), center.getZ() + HOUSE_WALL_HEIGHT + HOUSE_ROOF_HEIGHT + HOUSE_EPSILON);
    glEnd();

    /* Door frame */
    glBegin(GL_LINE_LOOP);
    glVertex3d(center.getX() + (HOUSE_WIDTH / 2.0) + HOUSE_EPSILON, center.getY() + (HOUSE_DOOR_WIDTH / 2.0), center.getZ() + HOUSE_EPSILON);
    glVertex3d(center.getX() + (HOUSE_WIDTH / 2.0) + HOUSE_EPSILON, center.getY() - (HOUSE_DOOR_WIDTH / 2.0), center.getZ() + HOUSE_EPSILON);
    glVertex3d(center.getX() + (HOUSE_WIDTH / 2.0) + HOUSE_EPSILON, center.getY() - (HOUSE_DOOR_WIDTH / 2.0), center.getZ() + HOUSE_DOOR_HEIGHT);
    glVertex3d(center.getX() + (HOUSE_WIDTH / 2.0) + HOUSE_EPSILON, center.getY() + (HOUSE_DOOR_WIDTH / 2.0), center.getZ() + HOUSE_DOOR_HEIGHT);
    glEnd();

    /* Window frames */
    glColor3d(RGB_COLOR_BLACK);
    glBegin(GL_LINE_LOOP);
    glVertex3d(center.getX() + (HOUSE_WIDTH / 2.0) + HOUSE_EPSILON, center.getY() + (HOUSE_LENGTH / 4.0), center.getZ() + HOUSE_WINDOW_HEIGHT_FROM_GROUND);
    glVertex3d(center.getX() + (HOUSE_WIDTH / 2.0) + HOUSE_EPSILON, center.getY() + (HOUSE_LENGTH / 4.0) + HOUSE_WINDOW_WIDTH, center.getZ() + HOUSE_WINDOW_HEIGHT_FROM_GROUND);
    glVertex3d(center.getX() + (HOUSE_WIDTH / 2.0) + HOUSE_EPSILON, center.getY() + (HOUSE_LENGTH / 4.0) + HOUSE_WINDOW_WIDTH, center.getZ() + HOUSE_WINDOW_HEIGHT_FROM_GROUND + HOUSE_WINDOW_HEIGHT);
    glVertex3d(center.getX() + (HOUSE_WIDTH / 2.0) + HOUSE_EPSILON, center.getY() + (HOUSE_LENGTH / 4.0), center.getZ() + HOUSE_WINDOW_HEIGHT_FROM_GROUND + HOUSE_WINDOW_HEIGHT);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3d(center.getX() + (HOUSE_WIDTH / 2.0) + HOUSE_EPSILON, center.getY() - (HOUSE_LENGTH / 4.0), center.getZ() + HOUSE_WINDOW_HEIGHT_FROM_GROUND);
    glVertex3d(center.getX() + (HOUSE_WIDTH / 2.0) + HOUSE_EPSILON, center.getY() - (HOUSE_LENGTH / 4.0) - HOUSE_WINDOW_WIDTH, center.getZ() + HOUSE_WINDOW_HEIGHT_FROM_GROUND);
    glVertex3d(center.getX() + (HOUSE_WIDTH / 2.0) + HOUSE_EPSILON, center.getY() - (HOUSE_LENGTH / 4.0) - HOUSE_WINDOW_WIDTH, center.getZ() + HOUSE_WINDOW_HEIGHT_FROM_GROUND + HOUSE_WINDOW_HEIGHT);
    glVertex3d(center.getX() + (HOUSE_WIDTH / 2.0) + HOUSE_EPSILON, center.getY() - (HOUSE_LENGTH / 4.0), center.getZ() + HOUSE_WINDOW_HEIGHT_FROM_GROUND + HOUSE_WINDOW_HEIGHT);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3d(center.getX() - (HOUSE_WIDTH / 2.0) - HOUSE_EPSILON, center.getY() + (HOUSE_LENGTH / 4.0), center.getZ() + HOUSE_WINDOW_HEIGHT_FROM_GROUND);
    glVertex3d(center.getX() - (HOUSE_WIDTH / 2.0) - HOUSE_EPSILON, center.getY() + (HOUSE_LENGTH / 4.0) + HOUSE_WINDOW_WIDTH, center.getZ() + HOUSE_WINDOW_HEIGHT_FROM_GROUND);
    glVertex3d(center.getX() - (HOUSE_WIDTH / 2.0) - HOUSE_EPSILON, center.getY() + (HOUSE_LENGTH / 4.0) + HOUSE_WINDOW_WIDTH, center.getZ() + HOUSE_WINDOW_HEIGHT_FROM_GROUND + HOUSE_WINDOW_HEIGHT);
    glVertex3d(center.getX() - (HOUSE_WIDTH / 2.0) - HOUSE_EPSILON, center.getY() + (HOUSE_LENGTH / 4.0), center.getZ() + HOUSE_WINDOW_HEIGHT_FROM_GROUND + HOUSE_WINDOW_HEIGHT);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3d(center.getX() - (HOUSE_WIDTH / 2.0) - HOUSE_EPSILON, center.getY() - (HOUSE_LENGTH / 4.0), center.getZ() + HOUSE_WINDOW_HEIGHT_FROM_GROUND);
    glVertex3d(center.getX() - (HOUSE_WIDTH / 2.0) - HOUSE_EPSILON, center.getY() - (HOUSE_LENGTH / 4.0) - HOUSE_WINDOW_WIDTH, center.getZ() + HOUSE_WINDOW_HEIGHT_FROM_GROUND);
    glVertex3d(center.getX() - (HOUSE_WIDTH / 2.0) - HOUSE_EPSILON, center.getY() - (HOUSE_LENGTH / 4.0) - HOUSE_WINDOW_WIDTH, center.getZ() + HOUSE_WINDOW_HEIGHT_FROM_GROUND + HOUSE_WINDOW_HEIGHT);
    glVertex3d(center.getX() - (HOUSE_WIDTH / 2.0) - HOUSE_EPSILON, center.getY() - (HOUSE_LENGTH / 4.0), center.getZ() + HOUSE_WINDOW_HEIGHT_FROM_GROUND + HOUSE_WINDOW_HEIGHT);
    glEnd();
}
