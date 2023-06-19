/*****************************************************************//**
 * \file   Menus.cpp
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

#include "Menus.h"
#include "SceneObjects.h"

#include "PixelPt.h"
#include "RGBColor.h"
#include "WcPt3D.h"
#include "Button.h"

/******************************
*       GLOBAL VARIABLES      *
*******************************/
/* Top menu */
const GLint TOP_MENU_HEIGHT = 30;

const GLint EXIT_BTN_WIDTH = 45;
const GLint HELP_BTN_WIDTH = 50;
const GLint ADJ_LIGHTING_BTN_WIDTH = 165;
const GLint BTN_HEIGHT = TOP_MENU_HEIGHT;

Button exitBtn(0, 0, EXIT_BTN_WIDTH, BTN_HEIGHT, "Exit");
Button helpBtn(0, 0, HELP_BTN_WIDTH, BTN_HEIGHT, "Help");
Button adjAmbLightBtn(0, 0, ADJ_LIGHTING_BTN_WIDTH, BTN_HEIGHT, "Adjust Lighting");

/* Help menu */
bool displayHelpMenu = false;

/* Adjust Lighting menu */
bool displayAdjustLightingMenu = false;
Button decreaseAmbientLightBtn;
Button increaseAmbientLightBtn;
Button decreaseSunLightBtn;
Button increaseSunLightBtn;
Button moveSunCcwBtn;
Button moveSunCwBtn;

/******************************
*     FUNCTION DEFINITIONS    *
*******************************/
void renderTopMenu(void)
{
    static const GLint TOP_MENU_FRAME_WIDTH = 3;

    if (!displayHelpMenu)
    {
        return;
    }

    const GLint windowWidth = glutGet(GLUT_WINDOW_WIDTH);
    const GLint windowHeight = glutGet(GLUT_WINDOW_HEIGHT);

    /* Render a frame for the top menu */
    glViewport(0, windowHeight - TOP_MENU_HEIGHT, windowWidth, TOP_MENU_HEIGHT);

    resetProjectionAndModelviewMatrices();

    gluOrtho2D(0.0, windowWidth, windowHeight - TOP_MENU_HEIGHT, windowHeight);

    glRectf(0.0, 0.0, windowWidth, TOP_MENU_HEIGHT);

    glColor3d(RGB_COLOR_BLACK);
    glLineWidth(TOP_MENU_FRAME_WIDTH);
    glBegin(GL_LINE_LOOP);
    glVertex2d(1.0, windowHeight - TOP_MENU_HEIGHT + 1.0);
    glVertex2d(windowWidth, windowHeight - TOP_MENU_HEIGHT + 1.0);
    glVertex2d(windowWidth, windowHeight);
    glVertex2d(1.0, windowHeight);
    glEnd();

    /* Render buttons */
    exitBtn.setPosition(0, windowHeight - BTN_HEIGHT);
    helpBtn.setPosition(EXIT_BTN_WIDTH, windowHeight - BTN_HEIGHT);
    adjAmbLightBtn.setPosition(EXIT_BTN_WIDTH + HELP_BTN_WIDTH, windowHeight - BTN_HEIGHT);

    exitBtn.render();
    helpBtn.render();
    adjAmbLightBtn.render();
}


void handleMouseEventTopMenu(int button, int state, int x, int y)
{
    const GLint windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
    y = windowHeight - y;

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if (exitBtn.clicked(x, y))
        {
            exit(0);
        }
        else if (helpBtn.clicked(x, y))
        {
            displayHelpMenu = true;
            displayAdjustLightingMenu = false;
        }
        else if (adjAmbLightBtn.clicked(x, y))
        {
            displayHelpMenu = false;
            displayAdjustLightingMenu = true;
        }
    }
}


void renderHelpMenu(void)
{
    static const GLint HELP_MENU_WIDTH = 375;
    static const GLint HELP_MENU_HEIGHT = 300;
    static const GLint HELP_MENU_FRAME_WIDTH = 7;
    static const GLfloat HELP_MENU_TITLE_POS[] = { 90.0, 260.0 };
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


void renderAdjustLightingMenu(void)
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

    if (!displayAdjustLightingMenu)
    {
        return;
    }

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
    glRasterPos2f(MENU_HEADER_POS.getX(), MENU_HEADER_POS.getY());
    for (const auto& c : MENU_HEADER)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }

    /* Render adjustment text */
    glRasterPos2f(ADJ_AMB_LIGHT_TEXT_POS.getX(), ADJ_AMB_LIGHT_TEXT_POS.getY());
    for (const auto& c : ADJ_AMB_LIGHT_TEXT)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
    }

    glRasterPos2f(ADJ_SUN_LIGHT_TEXT_POS.getX(), ADJ_SUN_LIGHT_TEXT_POS.getY());
    for (const auto& c : ADJ_SUN_LIGHT_TEXT)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
    }

    glRasterPos2f(ADJ_SUN_POS_TEXT_POS.getX(), ADJ_SUN_POS_TEXT_POS.getY());
    for (const auto& c : ADJ_SUN_POS_TEXT)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
    }

    /* Render footer */
    glRasterPos2f(MENU_FOOTER_POS.getX(), MENU_FOOTER_POS.getY());
    for (const auto& c : MENU_FOOTER)
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


void handleKeyboardEventAdjustLightingMenu(unsigned char key, int x, int y)
{
    static const int ENTER_KEY_VAL = 13;
    if ((int)key == ENTER_KEY_VAL)
    {
        displayAdjustLightingMenu = false;
        glutPostRedisplay();
    }
}


void handleMouseEventAdjustLightingMenu(int button, int state, int x, int y)
{
    static const GLdouble SUN_ANGLE_DIFF = 5.0;
    static const GLfloat SUN_CONST_ATTEN_DIFF = 0.2;
    static const GLfloat GLOBAL_AMB_DIFF = 0.05;

    const GLint windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
    y = windowHeight - y;

    if (displayAdjustAmbientLightMenu && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if (decreaseAmbientLightBtn.clicked(x, y))
        {
            if (globalAmbient[0] - GLOBAL_AMB_DIFF >= 0.0)
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
            if (sunConstAttenuation + SUN_CONST_ATTEN_DIFF <= 1.0)
            {
                sunConstAttenuation += SUN_CONST_ATTEN_DIFF;
            }
        }
        else if (increaseSunLightBtn.clicked(x, y))
        {
            if (sunConstAttenuation - SUN_CONST_ATTEN_DIFF >= 0.0)
            {
                sunConstAttenuation -= SUN_CONST_ATTEN_DIFF;
            }
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