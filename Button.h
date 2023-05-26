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
#include "SceneObject.h"
#include "PixelPt.h"
#include "RGBColor.h"
#include <string>

/**
 * This class represents a button.
 */
class Button : public SceneObject
{
public:
    Button(PixelPt pos, GLint w, GLint h, std::string label);
    Button(GLint x, GLint y, GLint w, GLint h, std::string label);
    Button(PixelPt pos, GLint w, GLint h, std::string label, RGBColor bgColor, RGBColor frameColor, RGBColor labelColor);
    Button(GLint x, GLint y, GLint w, GLint h, std::string label, RGBColor bgColor, RGBColor frameColor, RGBColor labelColor);

    void render() const;
    bool clicked(GLint x, GLint y);

    void setPosition(PixelPt pos);
    void setPosition(GLint x, GLint y);
    void setWidth(GLint w);
    void setHeight(GLint h);
    void setBackgroundColor(RGBColor rgbColor);
    void setFrameColor(RGBColor rgbColor);
    void setLabelColor(RGBColor rgbColor);

private:
    PixelPt _pos;   // Lower left corner (in pixels)
    GLint _width;   // Pixel width
    GLint _height;  // Pixel Height
    std::string _label;
    RGBColor _bgColor;
    RGBColor _frameColor; 
    RGBColor _labelColor;
};
