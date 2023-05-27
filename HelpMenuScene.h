#pragma once
/*****************************************************************//**
 * \file   HelpMenuScene.h
 * \brief  
 * 
 * \author aaron
 * \date   May 2023
 *********************************************************************/

/******************************
*          INCLUDES           *
*******************************/
#include <string>
#include <vector>

/******************************
*          DEFINES            *
*******************************/
#define HELP_MENU_ENTER_KEY_VAL 13

#define HELP_MENU_WIDTH 375
#define HELP_MENU_HEIGHT 300
#define HELP_MENU_FRAME_WIDTH 7

#define HELP_MENU_TITLE_POS 90.0, 260.0
#define HELP_MENU_FOOTER_POS 40.0, 20.0
#define HELP_MENU_TEXT_POS 10.0, 225.0
#define HELP_MENU_TEXT_LINE_OFFSET 20.0

#define HELP_MENU_TITLE "Help Menu - CowGL"
#define HELP_MENU_FOOTER "Press ENTER to close this window."
#define HELP_MENU_TEXT {"Use the arrow keys to move the cow around.",\
                        "Use W,A,S,D keys to move the cow's tail.",\
                        "Use TBD keys to move the cow's head.",\
                        "Press V to switch between first-person and third-person views.",\
                        "Use the left mouse button to click on menu buttons."}


/******************************
*      EXTERNAL VARIABLES     *
*******************************/
extern bool displayHelpMenu;
extern std::vector<std::string> helpMenuTextLines;

/******************************
*     FUNCTION PROTOTYPES     *
*******************************/
void renderHelpMenuScene(void);
void handleKeyboardEventHelpMenu(unsigned char key, int x, int y);
