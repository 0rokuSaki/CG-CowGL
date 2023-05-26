#pragma once
/*****************************************************************//**
 * \file   PixelPt.h
 * \brief  Class PixelPt declaration and definition.
 * 
 * \author aaron
 * \date   May 2023
 *********************************************************************/

/******************************
*          INCLUDES           *
*******************************/
#include <GL/glut.h>

/**
 * Represents a pixel position (x,y).
 */
class PixelPt
{
public:
    PixelPt() : _x(0), _y(0) {}
    PixelPt(GLint x, GLint y) : _x(x), _y(y) {}

    GLint getX() const { return _x; }
    GLint getY() const { return _y; }

    void setX(GLint x) { _x = x; }
    void setY(GLint y) { _y = y; }

private:
    GLint _x, _y;
};
