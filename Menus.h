#pragma once
/*****************************************************************//**
 * \file   Menus.h
 * \brief  A collection of functions for rendering the menus
 *         of CowGL.
 * 
 * \author aaron
 * \date   June 2023
 *********************************************************************/

/******************************
*          INCLUDES           *
*******************************/
#include <GL/glut.h>

/******************************
*      EXTERNAL VARIABLES     *
*******************************/
extern const GLint TOP_MENU_HEIGHT;

/******************************
*     FUNCTION PROTOTYPES     *
*******************************/
/* Resets projection and modelview matrices. */
void resetProjectionAndModelviewMatrices(void);

/* Top menu */
void renderTopMenu(void);
void handleMouseEventTopMenu(int button, int state, int x, int y);

/* Help menu */
void renderHelpMenu(void);
void handleKeyboardEventHelpMenu(unsigned char key, int x, int y);

/* Adjust Lighting menu */
void renderAdjustLightingMenu(void);
void handleKeyboardEventAdjustLightingMenu(unsigned char key, int x, int y);
void handleMouseEventAdjustLightingMenu(int button, int state, int x, int y);
