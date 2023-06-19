#pragma once
/*****************************************************************//**
 * \file   renderShedObject.h
 * \brief  Declaration of renderShedObject function.
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
void renderShedObject(const WcPt3D& position, const GLfloat rotationAngle);

