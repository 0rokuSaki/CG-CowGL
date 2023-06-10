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
#define VIEW_ORIGIN 26, -26, 6
#define LOOK_AT_POINT 0.0, 0.0, 2.0
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

#define SKY_SPHERE_PROPERTIES (Z_FAR / 2.0), 50.0, 50.0  // radius, slices, stacks

/******************************
*      EXTERNAL VARIABLES     *
*******************************/

/******************************
*     FUNCTION PROTOTYPES     *
*******************************/
void renderMainScene(void);
void handleKeyboardEventMain(unsigned char key, int x, int y);
void resetProjectionAndModelviewMatrices(void);
