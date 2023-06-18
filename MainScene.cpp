/*****************************************************************//**
 * \file   MainScene.cpp
 * \brief  
 * 
 * \author aaron
 * \date   May 2023
 *********************************************************************/

/******************************
*          INCLUDES           *
*******************************/
#include <GL/glut.h>
#include "MainScene.h"
#include "TopMenuScene.h"
#include "RGBColor.h"
#include "WcPt3D.h"

#include "Background.h"
#include "House.h"
#include "Shed.h"
#include "Tree.h"
#include "WaterTank.h"

/******************************
*          DEFINES            *
*******************************/

#define XW_MIN -1
#define XW_MAX 1
#define YW_MIN -1
#define YW_MAX 1
#define Z_NEAR 1
#define Z_FAR 175

/******************************
*       GLOBAL VARIABLES      *
*******************************/
WcPt3D viewOrigin(20.0, 20.0, 10.0);
WcPt3D lookAtPoint(0.0, 0.0, 1.0);
WcVector3D upVector(0.0, 0.0, 1.0);

/******************************
*     FUNCTION DEFINITIONS    *
*******************************/
void renderMainScene(void)
{
    const GLint windowWidth = glutGet(GLUT_WINDOW_WIDTH);
    const GLint windowHeight = glutGet(GLUT_WINDOW_HEIGHT);

    glViewport(0, 0, windowWidth, windowHeight - TOP_MENU_HEIGHT);

    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
    GLfloat globalAmbient[] = { 0.75, 0.75, 0.75, 1.0 };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbient);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    
    resetProjectionAndModelviewMatrices();

    glMatrixMode(GL_MODELVIEW);
    gluLookAt(viewOrigin.getX(), viewOrigin.getY(), viewOrigin.getZ(), lookAtPoint.getX(), lookAtPoint.getY(), lookAtPoint.getZ(), upVector.getX(), upVector.getY(), upVector.getZ());

    glMatrixMode(GL_PROJECTION);
    glFrustum(XW_MIN, XW_MAX, YW_MIN, YW_MAX, Z_NEAR, Z_FAR);

    /* Render temporary WC axes */
    /* RED = X, GREEN = Y, BLUE = Z */
    renderAxes(2.0);

    renderBackground();
    renderHouse(WcPt3D(-5, 0, 0), 0.0);
    renderShed(WcPt3D(0, 6, 0), 180.0);
    renderWaterTank(WcPt3D(2.5, 6, 0), 0.0);
    renderTree(WcPt3D(-4, 6, 0));
    renderTree(WcPt3D(0, -5, 0));
    renderTree(WcPt3D(10, 10, 0));
    renderTree(WcPt3D(10, -10, 0));
    renderTree(WcPt3D(-10, -10, 0));

    glDisable(GL_DEPTH_TEST);
}


void renderAxes(GLdouble height)
{
    static const GLdouble AXIS_LENGTH = 15.0;
    static const GLdouble AXIS_WIDTH = 10.0;
    static const GLdouble AXIS_ARROW_RADIUS = 0.5;
    static const GLdouble AXIS_ARROW_LENGTH = 1.5;
    static const GLint NUM_SLICES = 20;
    static const GLint NUM_STACKS = 20;
    static const GLint NUM_LOOPS = 20;

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glTranslated(0.0, 0.0, height);

    glLineWidth(AXIS_WIDTH);
    glColor3d(RGB_COLOR_RED);

    GLUquadric* disk = gluNewQuadric();

    /* X axis */
    glBegin(GL_LINES);
    glVertex3d(AXIS_LENGTH / 2.0, 0.0, 0.02);
    glVertex3d(-AXIS_LENGTH / 2.0, 0.0, 0.02);
    glEnd();

    glTranslated(AXIS_LENGTH / 2.0, 0.0, 0.0);
    glRotated(90.0, 0.0, 1.0, 0.0);

    gluDisk(disk, 0.0, AXIS_ARROW_RADIUS, NUM_SLICES, NUM_LOOPS);
    glutSolidCone(AXIS_ARROW_RADIUS, AXIS_ARROW_LENGTH, NUM_SLICES, NUM_STACKS);

    glRotated(-90.0, 0.0, 1.0, 0.0);
    glTranslated(-AXIS_LENGTH / 2.0, 0.0, 0.0);

    /* Y axis */
    glColor3d(RGB_COLOR_GREEN);
    glBegin(GL_LINES);
    glVertex3d(0.0, AXIS_LENGTH / 2.0, 0.02);
    glVertex3d(0.0, -AXIS_LENGTH / 2.0, 0.02);
    glEnd();

    glTranslated(0.0, AXIS_LENGTH / 2.0, 0.0);
    glRotated(-90.0, 1.0, 0.0, 0.0);

    gluDisk(disk, 0.0, AXIS_ARROW_RADIUS, NUM_SLICES, NUM_LOOPS);
    glutSolidCone(AXIS_ARROW_RADIUS, AXIS_ARROW_LENGTH, NUM_SLICES, NUM_STACKS);

    glRotated(90.0, 1.0, 0.0, 0.0);
    glTranslated(0.0, -AXIS_LENGTH / 2.0, 0.0);

    /* Z axis */
    glColor3d(RGB_COLOR_BLUE);
    glBegin(GL_LINES);
    glVertex3d(0.0, 0.0, AXIS_LENGTH / 2.0);
    glVertex3d(0.0, 0.0, -AXIS_LENGTH / 2.0);
    glEnd();

    glTranslated(0.0, 0.0, AXIS_LENGTH / 2.0);

    gluDisk(disk, 0.0, AXIS_ARROW_RADIUS, NUM_SLICES, NUM_LOOPS);
    glutSolidCone(AXIS_ARROW_RADIUS, AXIS_ARROW_LENGTH, NUM_SLICES, NUM_STACKS);

    glTranslated(0.0, 0.0, -AXIS_LENGTH / 2.0);

    gluDeleteQuadric(disk);

    glPopMatrix();
}


void handleKeyboardEventMain(unsigned char key, int x, int y)
{
}
