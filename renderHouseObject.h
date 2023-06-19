#pragma once
/*****************************************************************//**
 * \file   renderHouseObject.h
 * \brief  Declaration of renderHouseObject function.
 * 
 * \author aaron
 * \date   June 2023
 *********************************************************************/

/******************************
*          INCLUDES           *
*******************************/
#include <GL/glut.h>

/******************************
*    FORWARD DECLARATIONS     *
*******************************/
class WcPt3D;

/******************************
*     FUNCTION PROTOTYPES     *
*******************************/
void renderHouseObject(WcPt3D position, GLfloat rotationAngle);