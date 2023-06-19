#pragma once
/*****************************************************************//**
 * \file   renderBackground.h
 * \brief  Declaration of renderBackground function.
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
extern GLfloat worldMinCoord;
extern GLfloat worldMaxCoord;
extern GLfloat SKY_SPHERE_RADIUS;

/******************************
*     FUNCTION PROTOTYPES     *
*******************************/
void renderBackground(void);
