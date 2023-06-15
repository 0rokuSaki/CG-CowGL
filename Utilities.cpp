/*****************************************************************//**
 * \file   Utilities.cpp
 * \brief  
 * 
 * \author aaron
 * \date   June 2023
 *********************************************************************/

/******************************
*          INCLUDES           *
*******************************/
#include "WcPt3D.h"
#include "WcVector3D.h"

/******************************
*     FUNCTION DEFINITIONS    *
*******************************/
WcVector3D crossProduct(const WcVector3D& v1, const WcVector3D& v2)
{
    WcVector3D result;

    result.setX(v1.getY() * v2.getZ() - v1.getZ() * v2.getY());
    result.setY(-(v1.getX() * v2.getZ() - v1.getZ() * v2.getX()));
    result.setZ(v1.getX() * v2.getY() - v1.getY() * v2.getX());

    return result;
}


WcVector3D getNormalVector(const WcPt3D& v1, const WcPt3D& v2, const WcPt3D& v3)
{
    WcVector3D a, b, result;

    a.setX(v1.getX() - v2.getX());
    a.setY(v1.getY() - v2.getY());
    a.setZ(v1.getZ() - v2.getZ());

    b.setX(v1.getX() - v3.getX());
    b.setY(v1.getY() - v3.getY());
    b.setZ(v1.getZ() - v3.getZ());

    result = crossProduct(a, b);
    result.normalize();
    return result;
}
