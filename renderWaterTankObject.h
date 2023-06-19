#pragma once
/*****************************************************************//**
 * \file   renderWaterTankObject.h
 * \brief  Declaration of renderWaterTankObject function.
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
void renderWaterTank(const WcPt3D& position, const GLfloat rotationAngle);
