#pragma once
/*****************************************************************//**
 * \file   SceneObject.h
 * \brief  
 * 
 * \author aaron
 * \date   May 2023
 *********************************************************************/

/**
 * Common interface for objects in the scene.
 */
class SceneObject
{
public:
    virtual void render() const = 0;
};
