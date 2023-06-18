#pragma once
/*****************************************************************//**
 * \file   AdjustAmbientLightMenuScene.h
 * \brief  
 * 
 * \author aaron
 * \date   June 2023
 *********************************************************************/

/******************************
*          INCLUDES           *
*******************************/

/******************************
*          DEFINES            *
*******************************/

/******************************
*      EXTERNAL VARIABLES     *
*******************************/
extern bool displayAdjustAmbientLightMenu;

/******************************
*     FUNCTION PROTOTYPES     *
*******************************/
void renderAdjustAmbientLightScene(void);
void handleKeyboardEventAdjustAmbientLightMenu(unsigned char key, int x, int y);
void resetProjectionAndModelviewMatrices(void);
