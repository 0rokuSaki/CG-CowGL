#pragma once
/*****************************************************************//**
 * \file   WcPt2D.h
 * \brief  Class WcPt2D declaration and definition.
 * 
 * \author aaron
 * \date   May 2023
 *********************************************************************/

/******************************
*          INCLUDES           *
*******************************/
#include <GL/glut.h>

/**
 * Class definition for WcPt2D.
 * Represents a 2D world coordinate point.
 */
class WcPt2D
{
public:
    WcPt2D() : _x(0.0), _y(0.0) {}
    WcPt2D(GLdouble x, GLdouble y) : _x(x), _y(y) {}

    GLdouble getX() const { return _x; }
    GLdouble getY() const { return _y; }

    void setX(GLdouble x) { _x = x; }
    void setY(GLdouble y) { _y = y; }

private:
    GLdouble _x, _y;
};
