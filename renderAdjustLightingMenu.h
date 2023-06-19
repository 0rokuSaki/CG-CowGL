#pragma once
/*****************************************************************//**
 * \file   renderAdjustLightingMenu.h
 * \brief  
 * 
 * \author aaron
 * \date   June 2023
 *********************************************************************/

/******************************
*      EXTERNAL VARIABLES     *
*******************************/
extern bool displayAdjustLightingMenu;

/******************************
*     FUNCTION PROTOTYPES     *
*******************************/
void renderAdjustLightingMenu(void);
void handleKeyboardEventAdjustLightingMenu(unsigned char key, int x, int y);
void handleMouseEventAdjustLightingMenu(int button, int state, int x, int y);
void resetProjectionAndModelviewMatrices(void);
