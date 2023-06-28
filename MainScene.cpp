/*****************************************************************//**
 * \file   MainScene.cpp
 * \brief  
 * 
 * \author aaron
 * \date   May 2023
 *********************************************************************/

/******************************
*          DEFINES            *
*******************************/
#define _USE_MATH_DEFINES
#define XW_MIN -1
#define XW_MAX 1
#define YW_MIN -1
#define YW_MAX 1
#define Z_NEAR 1
#define Z_FAR 175

/******************************
*          INCLUDES           *
*******************************/
#include <GL/glut.h>
#include <vector>
#include <cctype>
#include <cmath>

#include "MainScene.h"
#include "Menus.h"
#include "SceneObjects.h"
#include "Cow.h"

#include "RGBColor.h"
#include "WcPt3D.h"

/******************************
*            ENUMS            *
*******************************/
enum CameraMode
{
    FIRST_PERSON = 0,
    THIRD_PERSON,
    LAST_OF_CAMERA_MODE
};

enum OrganMode
{
    HEAD = 0,
    TAIL,
    LAST_OF_ORGAN_MODE
};

/******************************
*       GLOBAL VARIABLES      *
*******************************/
GLfloat globalAmbient[] = { 0.75, 0.75, 0.75, 1.0 };
CameraMode cameraMode = THIRD_PERSON;
OrganMode organMode = HEAD;
Cow cow;

/******************************
*     FUNCTION DEFINITIONS    *
*******************************/
void renderMainScene(void)
{
    const GLint windowWidth = glutGet(GLUT_WINDOW_WIDTH);
    const GLint windowHeight = glutGet(GLUT_WINDOW_HEIGHT);

    glViewport(0, 0, windowWidth, windowHeight - TOP_MENU_HEIGHT);

    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbient);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    
    resetProjectionAndModelviewMatrices();

    renderCamera();

    glMatrixMode(GL_PROJECTION);
    glFrustum(XW_MIN, XW_MAX, YW_MIN, YW_MAX, Z_NEAR, Z_FAR);

    /* Render WC axes */
    /* RED = X, GREEN = Y, BLUE = Z */
    //renderAxes(3.0);

    renderBackground();
    renderSunObject();
    renderHouseObject(WcPt3D(-10, 0, 0), 0.0);
    renderShedObject(WcPt3D(0, 8, 0), 180.0);
    renderWaterTank(WcPt3D(2.5, 8, 0), 0.0);

    cow.render();

    glDisable(GL_DEPTH_TEST);
}


void renderCamera(void)
{
    static const WcVector3D upVector(0.0, 0.0, 1.0);
    static WcPt3D viewOrigin;
    static WcPt3D lookAtPoint;

    if (cameraMode == FIRST_PERSON)
    {
        viewOrigin = WcPt3D(cow.getFpCamViewOrigin());
        lookAtPoint = WcPt3D(cow.getFpCamLookAtPoint());
    }
    else
    {
        viewOrigin = WcPt3D(cow.getTpCamViewOrigin());
        lookAtPoint = WcPt3D(cow.getTpCamLookAtPoint());
    }

    glMatrixMode(GL_MODELVIEW);
    gluLookAt(viewOrigin.getX(), viewOrigin.getY(), viewOrigin.getZ(), lookAtPoint.getX(), lookAtPoint.getY(), lookAtPoint.getZ(), upVector.getX(), upVector.getY(), upVector.getZ());
}


void renderAxes(GLdouble height)
{
    static const GLdouble AXIS_LENGTH = 10.0;
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


void handleKeyboardEventMainScene(unsigned char key, int x, int y)
{
    key = static_cast<unsigned char>(tolower(key));

    switch (key)
    {
        /* Organ mode toggle (head / tail) */
    case 't':
        organMode = TAIL;
        break;

    case 'h':
        organMode = HEAD;
        break;

        /* Camera mode toggle */
    case 'v':
        if (cameraMode == THIRD_PERSON)
        {
            cameraMode = FIRST_PERSON;
            organMode = HEAD;
        }
        else
            cameraMode = THIRD_PERSON;
        break;

        /* TP Camera controls */
    case '1':
        if (cameraMode == THIRD_PERSON)
            cow.TPCamDecreaseRadius();
        break;

    case '2':
        if (cameraMode == THIRD_PERSON)
            cow.TPCamRotateDown();
        break;

    case '4':
        if (cameraMode == THIRD_PERSON)
            cow.TPCamRotateCW();
        break;

    case '5':
        if (cameraMode == THIRD_PERSON)
        {
            cow.TPCamReset();
            cow.resetTail();
            cow.resetHead();
        }
        else
            cow.resetHead();
        break;

    case '6':
        if (cameraMode == THIRD_PERSON)
            cow.TPCamRotateCCW();
        break;

    case '7':
        if (cameraMode == THIRD_PERSON)
            cow.TPCamIncreaseRadius();
        break;

    case '8':
        if (cameraMode == THIRD_PERSON)
            cow.TPCamRotateUp();
        break;

        /* FP Camera and head controls / Tail controls */
    case 'i':
        if (organMode == HEAD)
            cow.moveHeadUp();
        else
            cow.moveTailUp();
        break;
        
    case 'k':
        if (organMode == HEAD)
            cow.moveHeadDown();
        else
            cow.moveTailDown();
        break;

    case 'j':
        if (organMode == HEAD)
            cow.turnHeadLeft();
        else
            cow.turnTailLeft();
        break;

    case 'l':
        if (organMode == HEAD)
            cow.turnHeadRight();
        else
            cow.turnTailRight();
        break;

        /* Movement controls */
    case 'w':
        cow.moveForward();
        break;

    case 's':
        cow.moveBackward();
        break;

    case 'a':
        cow.turnLeft();
        break;

    case 'd':
        cow.turnRight();
        break;
    }
}
