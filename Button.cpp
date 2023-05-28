/*****************************************************************//**
 * \file   Button.cpp
 * \brief  Class Button definition.
 * 
 * \author aaron
 * \date   May 2023
 *********************************************************************/

/******************************
*          INCLUDES           *
*******************************/
#include "Button.h"

/******************************
*          DEFINES            *
*******************************/
#define FRAME_WIDTH 3.0
#define LABEL_MARGIN_LEFT   5
#define LABEL_MARGIN_BOTTOM 7

/******************************
*          METHODS            *
*******************************/
Button::Button(PixelPt pos, GLint w, GLint h, std::string label) :
    _pos(pos),
    _width(w),
    _height(h),
    _label(label),
    _bgColor(RGB_COLOR_WHITE),
    _frameColor(RGB_COLOR_BLACK),
    _labelColor(RGB_COLOR_BLACK)
{
}


Button::Button(GLint x, GLint y, GLint w, GLint h, std::string label) :
    _pos(x, y),
    _width(w),
    _height(h),
    _label(label),
    _bgColor(RGB_COLOR_WHITE),
    _frameColor(RGB_COLOR_BLACK),
    _labelColor(RGB_COLOR_BLACK)
{
}


Button::Button(PixelPt pos, GLint w, GLint h, std::string label, RGBColor bgColor, RGBColor frameColor, RGBColor labelColor) :
    _pos(pos),
    _width(w),
    _height(h),
    _label(label),
    _bgColor(bgColor),
    _frameColor(frameColor),
    _labelColor(labelColor)
{
}


Button::Button(GLint x, GLint y, GLint w, GLint h, std::string label, RGBColor bgColor, RGBColor frameColor, RGBColor labelColor) :
    _pos(x, y),
    _width(w),
    _height(h),
    _label(label),
    _bgColor(bgColor),
    _frameColor(frameColor),
    _labelColor(labelColor)
{
}


void Button::render() const
{
    /* Create viewport for button */
    glViewport(_pos.getX(), _pos.getY(), _width, _height);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0.0, (GLdouble)_width, 0.0, (GLdouble)_height);

    /* Add background color */
    glColor3d(_bgColor.getR(), _bgColor.getG(), _bgColor.getB());
    glRectd(0.0, 0.0, (GLdouble)_width, (GLdouble)_height);

    /* Add frame */
    glColor3d(_frameColor.getR(), _frameColor.getG(), _frameColor.getB());
    glLineWidth(FRAME_WIDTH);
    glBegin(GL_LINE_LOOP);
    glVertex2d(1.0, 1.0);
    glVertex2d(_width, 1.0);
    glVertex2d(_width, _height);
    glVertex2d(1.0, _height);
    glEnd();

    /* Add label */
    glRasterPos2d(LABEL_MARGIN_LEFT, LABEL_MARGIN_BOTTOM);
    for (const char& c : _label)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
}


bool Button::clicked(GLint x, GLint y)
{
    return (_pos.getX() <= x) && 
           (x <= (_pos.getX() + _width)) && 
           (_pos.getY() <= y) && 
           (y <= (_pos.getY() + _height));
}


void Button::setPosition(PixelPt pos)
{
    _pos = pos;
}


void Button::setPosition(GLint x, GLint y)
{
    _pos.setX(x);
    _pos.setY(y);
}


void Button::setWidth(GLint w)
{
    _width = w;
}


void Button::setHeight(GLint h)
{
    _height = h;
}


void Button::setBackgroundColor(RGBColor rgbColor)
{
    _bgColor = rgbColor;
}


void Button::setFrameColor(RGBColor rgbColor)
{
    _frameColor = rgbColor;
}


void Button::setLabelColor(RGBColor rgbColor)
{
    _labelColor = rgbColor;
}
