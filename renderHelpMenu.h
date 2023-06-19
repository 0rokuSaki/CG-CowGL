#pragma once
/*****************************************************************//**
 * \file   renderHelpMenu.h
 * \brief  
 * 
 * \author aaron
 * \date   June 2023
 *********************************************************************/

/******************************
*      EXTERNAL VARIABLES     *
*******************************/
extern bool displayHelpMenu;

/******************************
*     FUNCTION PROTOTYPES     *
*******************************/
void renderHelpMenu(void);
void handleKeyboardEventHelpMenu(unsigned char key, int x, int y);
void resetProjectionAndModelviewMatrices(void);
