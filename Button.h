#pragma once
/*****************************************************************//**
 * \file   Button.h
 * \brief  Class Button declaration.
 * 
 * \author aaron
 * \date   May 2023
 *********************************************************************/

/******************************
*          INCLUDES           *
*******************************/
#include <string>
#include "PixelPt.h"
#include "RGBColor.h"

/******************************
*     CLASS DECLARATIONS      *
*******************************/
class Button
{
public:
    Button();
    Button(PixelPt pos, GLint w, GLint h, std::string label);
    Button(GLint x, GLint y, GLint w, GLint h, std::string label);

    void render() const;
    bool clicked(GLint x, GLint y) const;

    void setPosition(PixelPt pos);
    void setPosition(GLint x, GLint y);
    void setWidth(GLint w);
    void setHeight(GLint h);

private:
    PixelPt _pos;   // Lower left corner (in pixels)
    GLint _width;   // Pixel width
    GLint _height;  // Pixel Height
    std::string _label;
};
