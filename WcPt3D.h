#pragma once
/*****************************************************************//**
 * \file   WcPt3D.h
 * \brief  Class WcPt3D declaration and definition.
 * 
 * \author aaron
 * \date   May 2023
 *********************************************************************/

/******************************
*          INCLUDES           *
*******************************/
#include "WcPt2D.h"

/**
 * Class definition for WcPt3D.
 * Represents a 3D world coordinate point.
 */
class WcPt3D : public WcPt2D
{
public:
    WcPt3D() : WcPt2D(), _z(0.0) {}
    WcPt3D(GLdouble x, GLdouble y, GLdouble z) : WcPt2D(x, y), _z(z) {}

    GLdouble getX() const { return WcPt2D::getX(); }
    GLdouble getY() const { return WcPt2D::getY(); }
    GLdouble getZ() const { return _z; }

    void setX(GLdouble x) { WcPt2D::setX(x); }
    void setY(GLdouble y) { WcPt2D::setY(y); }
    void setZ(GLdouble z) { _z = z; }

private:
    GLdouble _z;
};
