#pragma once
/*****************************************************************//**
 * \file   renderTopMenu.h
 * \brief  Function declarations for rendering top menu.
 * 
 * \author aaron
 * \date   June 2023
 *********************************************************************/

/******************************
*          INCLUDES           *
*******************************/
#include "Button.h"

/******************************
*     FUNCTION PROTOTYPES     *
*******************************/
void renderTopMenu(void);
void handleMouseEventTopMenu(int button, int state, int x, int y);
void resetProjectionAndModelviewMatrices(void);
