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
#include "WcPt3D.h"
#include "WcVector3D.h"

/******************************
*      EXTERNAL VARIABLES     *
*******************************/
extern WcPt3D viewOrigin;
extern WcPt3D lookAtPoint;
extern WcVector3D upVector;
extern GLfloat globalAmbient[];

/******************************
*     FUNCTION PROTOTYPES     *
*******************************/
void renderMainScene(void);
void renderAxes(GLdouble height);
void handleKeyboardEventMain(unsigned char key, int x, int y);
void resetProjectionAndModelviewMatrices(void);
