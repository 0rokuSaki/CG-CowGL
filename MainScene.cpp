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

#include "House.h"
#include "Tree.h"

/******************************
*       GLOBAL VARIABLES      *
*******************************/

/******************************
*     FUNCTION DEFINITIONS    *
*******************************/
void renderMainScene(void)
{
    const GLint windowWidth = glutGet(GLUT_WINDOW_WIDTH);
    const GLint windowHeight = glutGet(GLUT_WINDOW_HEIGHT);

    glViewport(0, 0, windowWidth, windowHeight - TOP_MENU_HEIGHT);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    
    resetProjectionAndModelviewMatrices();

    glMatrixMode(GL_MODELVIEW);
    gluLookAt(VIEW_ORIGIN, LOOK_AT_POINT, UP_VECTOR);

    glMatrixMode(GL_PROJECTION);
    glFrustum(XW_MIN, XW_MAX, YW_MIN, YW_MAX, Z_NEAR, Z_FAR);

    /* Render plane */
    glColor3d(RGB_COLOR_GRASS_GREEN);
    glBegin(GL_POLYGON);
    glVertex3d(BORDER_PT1);
    glVertex3d(BORDER_PT2);
    glVertex3d(BORDER_PT3);
    glVertex3d(BORDER_PT4);
    glEnd();

    /* Render sky */
    glColor3d(RGB_COLOR_SKY_BLUE);
    glutSolidSphere(SKY_SPHERE_PROPERTIES);

    renderHouse(WcPt3D(0,0,0.0));
    renderTree(WcPt3D(13, 19, 0));
    renderTree(WcPt3D(8, -18, 0));

    glDisable(GL_DEPTH_TEST);
}


void handleKeyboardEventMain(unsigned char key, int x, int y)
{
}
