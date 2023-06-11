#pragma once
/*****************************************************************//**
 * \file   WcVector3D.h
 * \brief  
 * 
 * \author aaron
 * \date   June 2023
 *********************************************************************/

/******************************
*          INCLUDES           *
*******************************/
#include "WcPt3D.h"

class WcVector3D :
    public WcPt3D
{
public:
    WcVector3D() : WcPt3D(0.0, 0.0, 0.0) {}
    WcVector3D(GLdouble x, GLdouble y, GLdouble z) : WcPt3D(x, y, z) {}
};

