#pragma once
/*****************************************************************//**
 * \file   RGBColor.h
 * \brief  Class RGBColor declaration and definition.
 * 
 * \author aaron
 * \date   May 2023
 *********************************************************************/

/******************************
*          INCLUDES           *
*******************************/
#include <GL/glut.h>

/******************************
*          DEFINES            *
*******************************/
#define RGB_COLOR_BLACK 0.0, 0.0, 0.0
#define RGB_COLOR_WHITE 1.0, 1.0, 1.0
#define RGB_COLOR_RED   1.0, 0.0, 0.0
#define RGB_COLOR_GREEN 0.0, 1.0, 0.0
#define RGB_COLOR_BLUE  0.0, 0.0, 1.0
#define RGB_COLOR_LIGHT_GRAY 0.8, 0.8, 0.8
#define RGB_COLOR_GRASS_GREEN 0.25, 0.8, 0.25
#define RGB_COLOR_LIGHT_BROWN 0.8, 0.52, 0.25
#define RGB_COLOR_DARK_BROWN 0.31, 0.21, 0.14
#define RGB_COLOR_LIGHT_BLUE 0.62, 0.82, 0.88

/**
 * Represents an RGB triplet (r,g,b).
 */
class RGBColor
{
public:
    RGBColor() : _r(0.0), _g(0.0), _b(0.0) {}
    RGBColor(GLdouble r, GLdouble g, GLdouble b) : _r(normalize(r)), _g(normalize(g)), _b(normalize(b)) {}
    RGBColor(const RGBColor& color) : _r(color.getR()), _g(color.getG()), _b(color.getB()) {}

    GLdouble getR() const { return _r; }
    GLdouble getG() const { return _g; }
    GLdouble getB() const { return _b; }

    void setR(GLdouble r) { _r = normalize(r); }
    void setG(GLdouble g) { _g = normalize(g); }
    void setB(GLdouble b) { _b = normalize(b); }

private:
    GLdouble _r, _g, _b;

    GLdouble normalize(GLdouble x)
    {
        x = (x > 1.0) ? 1.0 : x;
        x = (x < 0.0) ? 0.0 : x;
        return x;
    }
};
