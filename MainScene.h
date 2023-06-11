#pragma once
/*****************************************************************//**
 * \file   MainScene.h
 * \brief  
 * 
 * \author aaron
 * \date   May 2023
 *********************************************************************/

/******************************
*          INCLUDES           *
*******************************/

/******************************
*          DEFINES            *
*******************************/
#define VIEW_ORIGIN 30, 30, 10
#define LOOK_AT_POINT 0.0, 0.0, 30.0
#define UP_VECTOR 0.0, 0.0, 1.0

#define XW_MIN -3
#define XW_MAX 3
#define YW_MIN -3
#define YW_MAX 3
#define Z_NEAR 5
#define Z_FAR 175

#define BORDER_PT1 100.0, 100.0, 0.0
#define BORDER_PT2 -100.0, 100.0, 0.0
#define BORDER_PT3 -100.0, -100.0, 0.0
#define BORDER_PT4 100.0, -100.0, 0.0

/******************************
*      EXTERNAL VARIABLES     *
*******************************/

/******************************
*     FUNCTION PROTOTYPES     *
*******************************/
void renderMainScene(void);
void handleKeyboardEventMain(unsigned char key, int x, int y);
void resetProjectionAndModelviewMatrices(void);
