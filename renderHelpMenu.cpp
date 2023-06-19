/*****************************************************************//**
 * \file   renderHelpMenu.cpp
 * \brief  
 * 
 * \author aaron
 * \date   June 2023
 *********************************************************************/

/******************************
*          INCLUDES           *
*******************************/
#include <GL/glut.h>
#include <vector>
#include <string>
#include "renderHelpMenu.h"
#include "RGBColor.h"
#include "PixelPt.h"

/******************************
*       GLOBAL VARIABLES      *
*******************************/
bool displayHelpMenu = false;

/******************************
*     FUNCTION DEFINITIONS    *
*******************************/
void renderHelpMenu(void)
{
    static const GLint HELP_MENU_WIDTH = 375;
    static const GLint HELP_MENU_HEIGHT = 300;
    static const GLint HELP_MENU_FRAME_WIDTH = 7;
    static const GLfloat HELP_MENU_TITLE_POS[] = {90.0, 260.0};
    static const GLfloat HELP_MENU_FOOTER_POS[] = { 40.0, 20.0 };
    static const GLfloat HELP_MENU_TEXT_POS[] = { 10.0, 225.0 };
    static const GLfloat HELP_MENU_TEXT_LINE_OFFSET = 20.0;
    static const std::string HELP_MENU_HEADER = "Help Menu - CowGL";
    static const std::string HELP_MENU_FOOTER = "Press ENTER to close this window";
    static const std::vector<std::string> helpMenuTextLines({ "Use the arrow keys to move the cow around.",\
                        "Use W,A,S,D keys to move the cow's tail.",\
                        "Use TBD keys to move the cow's head.",\
                        "Press V to switch between first-person and third-person views.",\
                        "Use the left mouse button to click on menu buttons." });

    const GLint windowWidth = glutGet(GLUT_WINDOW_WIDTH);
    const GLint windowHeight = glutGet(GLUT_WINDOW_HEIGHT);

    /* Render the window for the menu */
    PixelPt pos((windowWidth - HELP_MENU_WIDTH) / 2, (windowHeight - HELP_MENU_HEIGHT) / 2);
    glViewport(pos.getX(), pos.getY(), HELP_MENU_WIDTH, HELP_MENU_HEIGHT);

    resetProjectionAndModelviewMatrices();

    gluOrtho2D(0.0, (GLdouble)HELP_MENU_WIDTH, 0.0, (GLdouble)HELP_MENU_HEIGHT);

    /* Render a background */
    glColor3f(RGB_COLOR_LIGHT_GRAY);
    glRectf(0.0, 0.0, (GLdouble)HELP_MENU_WIDTH, (GLdouble)HELP_MENU_HEIGHT);

    /* Render a frame */
    glColor3f(RGB_COLOR_BLACK);
    glLineWidth(HELP_MENU_FRAME_WIDTH);
    glBegin(GL_LINE_LOOP);
    glVertex2f(1.0, 1.0);
    glVertex2f((GLdouble)HELP_MENU_WIDTH, 1.0);
    glVertex2f((GLdouble)HELP_MENU_WIDTH, (GLdouble)HELP_MENU_HEIGHT);
    glVertex2f(1.0, (GLdouble)HELP_MENU_HEIGHT);
    glEnd();

    /* Render help menu title */
    glRasterPos2f(HELP_MENU_TITLE_POS[0], HELP_MENU_TITLE_POS[1]);
    for (const auto& c : HELP_MENU_HEADER)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }

    /* Render help menu text */
    GLfloat textRasterPos[2] = { HELP_MENU_TEXT_POS[0], HELP_MENU_TEXT_POS[1] };
    for (const auto& line : helpMenuTextLines)
    {
        glRasterPos2fv(textRasterPos);

        for (const auto c : line)
        {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
        }

        textRasterPos[1] -= HELP_MENU_TEXT_LINE_OFFSET;
    }

    /* Render help menu footer */
    glRasterPos2f(HELP_MENU_FOOTER_POS[0], HELP_MENU_FOOTER_POS[1]);
    for (const auto& c : HELP_MENU_FOOTER)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
}


void handleKeyboardEventHelpMenu(unsigned char key, int x, int y)
{
    static const int ENTER_KEY_VAL = 13;
    if ((int)key == ENTER_KEY_VAL)
    {
        displayHelpMenu = false;
    }
}
