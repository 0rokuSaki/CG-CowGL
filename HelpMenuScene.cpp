/*****************************************************************//**
 * \file   HelpMenuScene.cpp
 * \brief  
 * 
 * \author aaron
 * \date   May 2023
 *********************************************************************/

/******************************
*          INCLUDES           *
*******************************/
#include <GL/glut.h>
#include <iostream>
#include "HelpMenuScene.h"
#include "RGBColor.h"
#include "PixelPt.h"

/******************************
*       GLOBAL VARIABLES      *
*******************************/
bool displayHelpMenu = false;
std::vector<std::string> helpMenuTextLines(HELP_MENU_TEXT);

/******************************
*     FUNCTION DEFINITIONS    *
*******************************/
void renderHelpMenuScene(void)
{
    const GLint windowWidth = glutGet(GLUT_WINDOW_WIDTH);
    const GLint windowHeight = glutGet(GLUT_WINDOW_HEIGHT);

    /* Render the window for the menu */
    PixelPt pos((windowWidth - HELP_MENU_WIDTH) / 2, (windowHeight - HELP_MENU_HEIGHT) / 2);
    glViewport(pos.getX(), pos.getY(), HELP_MENU_WIDTH, HELP_MENU_HEIGHT);

    resetProjectionAndModelviewMatrices();

    gluOrtho2D(0.0, (GLdouble)HELP_MENU_WIDTH, 0.0, (GLdouble)HELP_MENU_HEIGHT);

    /* Render a background */
    glColor3d(RGB_COLOR_LIGHT_GRAY);
    glRectd(0.0, 0.0, (GLdouble)HELP_MENU_WIDTH, (GLdouble)HELP_MENU_HEIGHT);

    /* Render a frame */
    glColor3d(RGB_COLOR_BLACK);
    glLineWidth(HELP_MENU_FRAME_WIDTH);
    glBegin(GL_LINE_LOOP);
    glVertex2d(1.0, 1.0);
    glVertex2d((GLdouble)HELP_MENU_WIDTH, 1.0);
    glVertex2d((GLdouble)HELP_MENU_WIDTH, (GLdouble)HELP_MENU_HEIGHT);
    glVertex2d(1.0, (GLdouble)HELP_MENU_HEIGHT);
    glEnd();

    /* Render help menu title */
    glRasterPos2d(HELP_MENU_TITLE_POS);
    for (const auto c : HELP_MENU_TITLE)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }

    /* Render help menu text */
    GLdouble textRasterPos[2] = { HELP_MENU_TEXT_POS };
    for (auto line : helpMenuTextLines)
    {
        glRasterPos2dv(textRasterPos);

        for (const auto c : line)
        {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
        }

        textRasterPos[1] -= HELP_MENU_TEXT_LINE_OFFSET;
    }

    /* Render help menu footer */
    glRasterPos2d(HELP_MENU_FOOTER_POS);
    for (const auto c : HELP_MENU_FOOTER)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
}


void handleKeyboardEventHelpMenu(unsigned char key, int x, int y)
{
    if ((int)key == HELP_MENU_ENTER_KEY_VAL)
    {
        displayHelpMenu = false;
        glutPostRedisplay();
    }
}
