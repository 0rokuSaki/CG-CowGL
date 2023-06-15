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
#include <GL/glut.h>

/**
 * Class definition for WcPt3D.
 * Represents a 3D world coordinate point.
 */
class WcPt3D
{
public:
    WcPt3D() : _x(0.0), _y(0.0), _z(0.0) {}
    WcPt3D(GLdouble x, GLdouble y, GLdouble z) : _x(x), _y(y), _z(z) {}

    GLdouble getX() const { return _x; }
    GLdouble getY() const { return _y; }
    GLdouble getZ() const { return _z; }

    void setX(GLdouble x) { _x = x; }
    void setY(GLdouble y) { _y = y; }
    void setZ(GLdouble z) { _z = z; }

protected:
    GLdouble _x, _y, _z;
};
