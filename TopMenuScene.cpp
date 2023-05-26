/*****************************************************************//**
 * \file   TopMenuScene.cpp
 * \brief  
 * 
 * \author aaron
 * \date   May 2023
 *********************************************************************/

/******************************
*          INCLUDES           *
*******************************/
#include "TopMenuScene.h"

Button exitBtn(0, 0, EXIT_BTN_WIDTH, BTN_HEIGHT, "Exit");
Button helpBtn(0, 0, HELP_BTN_WIDTH, BTN_HEIGHT, "Help");
Button adjAmbLightBtn(0, 0, ADJ_AMB_LIGHT_BTN_WIDTH, BTN_HEIGHT, "Adj. Ambient Light");

/******************************
*     FUNCTION DEFINITIONS    *
*******************************/
void renderTopMenuScene(void)
{
    GLint windowWidth = glutGet(GLUT_WINDOW_WIDTH);
    GLint windowHeight = glutGet(GLUT_WINDOW_HEIGHT);

    /**
     * Render a frame for the top menu.
     * The frame spans the width of the window, and it's height
     * is BTN_HEIGHT.
     */
    glViewport(0, windowHeight - BTN_HEIGHT, windowWidth, BTN_HEIGHT);
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, (GLdouble) windowWidth, (GLdouble)(windowHeight - BTN_HEIGHT), (GLdouble) windowHeight);
    
    glColor3d(RGB_COLOR_BLACK);
    glLineWidth(FRAME_WIDTH);
    glBegin(GL_LINE_LOOP);
    glVertex2d(0.0, windowHeight - BTN_HEIGHT);
    glVertex2d(windowWidth, windowHeight - BTN_HEIGHT);
    glVertex2d(windowWidth, windowHeight);
    glVertex2d(0.0, windowHeight);
    glEnd();

    /* Render buttons */
    exitBtn.setPosition(0, windowHeight - BTN_HEIGHT);
    helpBtn.setPosition(EXIT_BTN_WIDTH, windowHeight - BTN_HEIGHT);
    adjAmbLightBtn.setPosition(EXIT_BTN_WIDTH + HELP_BTN_WIDTH, windowHeight - BTN_HEIGHT);

    exitBtn.setBackgroundColor(RGBColor(RGB_COLOR_LIGHT_GRAY));
    helpBtn.setBackgroundColor(RGBColor(RGB_COLOR_LIGHT_GRAY));
    adjAmbLightBtn.setBackgroundColor(RGBColor(RGB_COLOR_LIGHT_GRAY));

    exitBtn.render();
    helpBtn.render();
    adjAmbLightBtn.render();
}
