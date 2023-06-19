#pragma once
/*****************************************************************//**
 * \file   renderSunObject.h
 * \brief  Declaration of renderSunObject function.
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
extern GLfloat sunAngle;
extern GLfloat sunConstAttenuation;

/******************************
*     FUNCTION PROTOTYPES     *
*******************************/
void renderSunObject(void);
