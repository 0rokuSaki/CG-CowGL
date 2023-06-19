#pragma once
/*****************************************************************//**
 * \file   SceneObjects.h
 * \brief  A collection of functions for rendering various objects
 *         in the CowGL world.
 * 
 * \author aaron
 * \date   June 2023
 *********************************************************************/

/******************************
*          INCLUDES           *
*******************************/
#include <GL/glut.h>

/******************************
*    FORWARD DECLARATIONS     *
*******************************/
class WcPt3D;

/******************************
*      EXTERNAL VARIABLES     *
*******************************/
/* Background */
extern GLfloat worldMinCoord;
extern GLfloat worldMaxCoord;

/* Sun */
extern GLfloat sunAngle;             // Angle of the sun relative to the ground.
extern GLfloat sunConstAttenuation;  // Sun light source constant attenuation.

/******************************
*     FUNCTION PROTOTYPES     *
*******************************/

/* Renders a green plane and a blue sky. */
void renderBackground(void);

/* Renders a house. */
void renderHouseObject(const WcPt3D& position, const GLfloat rotationAngle);

/* Renders a metal garden shed. */
void renderShedObject(const WcPt3D& position, const GLfloat rotationAngle);

/* Renders a sun (point light source). */
void renderSunObject(void);

/* Renders a tree. */
void renderTreeObject(const WcPt3D& position);

/* Renders a water tank (water trough). */
void renderWaterTank(const WcPt3D& position, const GLfloat rotationAngle);
