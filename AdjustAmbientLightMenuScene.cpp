/*****************************************************************//**
 * \file   AdjustAmbientLightMenuScene.cpp
 * \brief  
 * 
 * \author aaron
 * \date   June 2023
 *********************************************************************/

 /******************************
 *          INCLUDES           *
 *******************************/
#include <GL/glut.h>
#include <string>

#include "AdjustAmbientLightMenuScene.h"
#include "PixelPt.h"
#include "RGBColor.h"
#include "WcPt3D.h"

/******************************
*       GLOBAL VARIABLES      *
*******************************/
bool displayAdjustAmbientLightMenu = false;

/******************************
*     FUNCTION DEFINITIONS    *
*******************************/
void renderAdjustAmbientLightScene(void)
{
    static const GLint MENU_WIDTH = 375;
    static const GLint MENU_HEIGHT = 300;
    static const GLfloat MENU_FRAME_WIDTH = 7.0;
    static const WcPt3D MENU_HEADER_POS(20.0, 260.0, 0.0);
    static const WcPt3D MENU_FOOTER_POS(40.0, 20.0, 0.0);
    static const std::string MENU_HEADER = "Adjust Ambient Light Menu - CowGL";
    static const std::string MENU_FOOTER = "Press ENTER to close this window.";

    const GLint windowWidth = glutGet(GLUT_WINDOW_WIDTH);
    const GLint windowHeight = glutGet(GLUT_WINDOW_HEIGHT);

    /* Render the window for the menu */
    PixelPt pos((windowWidth - MENU_WIDTH) / 2, (windowHeight - MENU_HEIGHT) / 2);
    glViewport(pos.getX(), pos.getY(), MENU_WIDTH, MENU_HEIGHT);

    resetProjectionAndModelviewMatrices();

    gluOrtho2D(0.0, MENU_WIDTH, 0.0, MENU_HEIGHT);

    /* Render a background */
    glColor3d(RGB_COLOR_LIGHT_GRAY);
    glRectd(0.0, 0.0, MENU_WIDTH, MENU_HEIGHT);

    /* Render a frame */
    glColor3d(RGB_COLOR_BLACK);
    glLineWidth(MENU_FRAME_WIDTH);
    glBegin(GL_LINE_LOOP);
    glVertex2f(1.0, 1.0);
    glVertex2f(MENU_WIDTH, 1.0);
    glVertex2f(MENU_WIDTH, MENU_HEIGHT);
    glVertex2f(1.0, MENU_HEIGHT);
    glEnd();

    /* Render header */
    glRasterPos2d(MENU_HEADER_POS.getX(), MENU_HEADER_POS.getY());
    for (const auto& c : MENU_HEADER)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }

    /* Render footer */
    glRasterPos2d(MENU_FOOTER_POS.getX(), MENU_FOOTER_POS.getY());
    for (const auto &c : MENU_FOOTER)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
}


void handleKeyboardEventAdjustAmbientLightMenu(unsigned char key, int x, int y)
{
    static const int ENTER_KEY_VAL = 13;
    if ((int)key == ENTER_KEY_VAL)
    {
        displayAdjustAmbientLightMenu = false;
        glutPostRedisplay();
    }
}
