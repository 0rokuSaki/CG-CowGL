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
#include <iostream>

#include "AdjustAmbientLightMenuScene.h"
#include "MainScene.h"
#include "Background.h"
#include "PixelPt.h"
#include "RGBColor.h"
#include "WcPt3D.h"
#include "Button.h"

/******************************
*       GLOBAL VARIABLES      *
*******************************/
bool displayAdjustAmbientLightMenu = false;
Button decreaseAmbientLightBtn;
Button increaseAmbientLightBtn;
Button decreaseSunLightBtn;
Button increaseSunLightBtn;
Button moveSunCcwBtn;
Button moveSunCwBtn;

/******************************
*     FUNCTION DEFINITIONS    *
*******************************/
void renderAdjustAmbientLightScene(void)
{
    /* Dimensions */
    static const GLint MENU_WIDTH = 375;
    static const GLint MENU_HEIGHT = 300;
    static const GLfloat MENU_FRAME_WIDTH = 7.0;

    /* Header & footer */
    static const WcPt3D MENU_HEADER_POS(30.0, 260.0, 0.0);
    static const WcPt3D MENU_FOOTER_POS(40.0, 20.0, 0.0);
    static const std::string MENU_HEADER = "Adjust Ambient Light Menu - CowGL";
    static const std::string MENU_FOOTER = "Press ENTER to close this window.";

    /* Adjustment text */
    static const WcPt3D ADJ_AMB_LIGHT_TEXT_POS(150.0, 210.0, 0.0);
    static const WcPt3D ADJ_SUN_LIGHT_TEXT_POS(150.0, 150.0, 0.0);
    static const WcPt3D ADJ_SUN_POS_TEXT_POS(150.0, 90.0, 0.0);
    static const std::string ADJ_AMB_LIGHT_TEXT = "Ambient Light";
    static const std::string ADJ_SUN_LIGHT_TEXT = "Sun Light";
    static const std::string ADJ_SUN_POS_TEXT = "Sun Position";

    /* Buttons */
    static const GLint BTN_WIDTH = 30;
    static const GLint BTN_HEIGHT = 30;

    const GLint windowWidth = glutGet(GLUT_WINDOW_WIDTH);
    const GLint windowHeight = glutGet(GLUT_WINDOW_HEIGHT);

    /* Render the window for the menu */
    glViewport((windowWidth - MENU_WIDTH) / 2, (windowHeight - MENU_HEIGHT) / 2, MENU_WIDTH, MENU_HEIGHT);

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

    /* Render adjustment text */
    glRasterPos2d(ADJ_AMB_LIGHT_TEXT_POS.getX(), ADJ_AMB_LIGHT_TEXT_POS.getY());
    for (const auto& c : ADJ_AMB_LIGHT_TEXT)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
    }

    glRasterPos2d(ADJ_SUN_LIGHT_TEXT_POS.getX(), ADJ_SUN_LIGHT_TEXT_POS.getY());
    for (const auto& c : ADJ_SUN_LIGHT_TEXT)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
    }

    glRasterPos2d(ADJ_SUN_POS_TEXT_POS.getX(), ADJ_SUN_POS_TEXT_POS.getY());
    for (const auto& c : ADJ_SUN_POS_TEXT)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
    }

    /* Render footer */
    glRasterPos2d(MENU_FOOTER_POS.getX(), MENU_FOOTER_POS.getY());
    for (const auto &c : MENU_FOOTER)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }

    /* Render buttons */
    GLint btnX1 = (windowWidth - MENU_WIDTH) / 2 + 100;
    GLint btnX2 = (windowWidth - MENU_WIDTH) / 2 + 250;
    GLint btnY = (windowHeight - MENU_HEIGHT) / 2 + 200;

    decreaseAmbientLightBtn = Button(btnX1, btnY, BTN_WIDTH, BTN_HEIGHT, "-");
    increaseAmbientLightBtn = Button(btnX2, btnY, BTN_WIDTH, BTN_HEIGHT, "+");

    btnY -= 2 * BTN_HEIGHT;

    decreaseSunLightBtn = Button(btnX1, btnY, BTN_WIDTH, BTN_HEIGHT, "-");
    increaseSunLightBtn = Button(btnX2, btnY, BTN_WIDTH, BTN_HEIGHT, "+");

    btnY -= 2 * BTN_HEIGHT;

    moveSunCcwBtn = Button(btnX1, btnY, BTN_WIDTH, BTN_HEIGHT, "-");
    moveSunCwBtn = Button(btnX2, btnY, BTN_WIDTH, BTN_HEIGHT, "+");

    decreaseAmbientLightBtn.render();
    increaseAmbientLightBtn.render();
    decreaseSunLightBtn.render();
    increaseSunLightBtn.render();
    moveSunCcwBtn.render();
    moveSunCwBtn.render();
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


void handleMouseEventAdjustAmbientLightMenu(int button, int state, int x, int y)
{
    static const GLdouble SUN_ANGLE_DIFF = 5.0;
    static const GLfloat GLOBAL_AMB_DIFF = 0.05;

    const GLint windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
    y = windowHeight - y;

    if (displayAdjustAmbientLightMenu && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if (decreaseAmbientLightBtn.clicked(x, y))
        {
            if (globalAmbient[0] - GLOBAL_AMB_DIFF >= 0)
            {
                globalAmbient[0] -= GLOBAL_AMB_DIFF;
                globalAmbient[1] -= GLOBAL_AMB_DIFF;
                globalAmbient[2] -= GLOBAL_AMB_DIFF;
            }
        }
        else if (increaseAmbientLightBtn.clicked(x, y))
        {
            if (globalAmbient[0] + GLOBAL_AMB_DIFF <= 1.0)
            {
                globalAmbient[0] += GLOBAL_AMB_DIFF;
                globalAmbient[1] += GLOBAL_AMB_DIFF;
                globalAmbient[2] += GLOBAL_AMB_DIFF;
            }
        }
        else if (decreaseSunLightBtn.clicked(x, y))
        {
            std::cout << "3" << std::endl;
        }
        else if (increaseSunLightBtn.clicked(x, y))
        {
            std::cout << "4" << std::endl;
        }
        else if (moveSunCcwBtn.clicked(x, y))
        {
            if (sunAngle + SUN_ANGLE_DIFF <= 180.0)
            {
                sunAngle += SUN_ANGLE_DIFF;
            }
        }
        else if (moveSunCwBtn.clicked(x, y))
        {
            if (sunAngle - SUN_ANGLE_DIFF >= 0.0)
            {
                sunAngle -= SUN_ANGLE_DIFF;
            }
        }
    }
}
