#pragma once
/*****************************************************************//**
 * \file   Sky.h
 * \brief  
 * 
 * \author aaron
 * \date   June 2023
 *********************************************************************/

/******************************
*          DEFINES            *
*******************************/
#define SKY_SPHERE_PROPERTIES 125.0, 50.0, 50.0  // radius, slices, stacks
#define SKY_SUN_SPHERE_PROPERTIES 10.0, 20.0, 20.0  // radius, slices, stacks  
#define SKY_SUN_POSITION -70.0, 70.0, -70.0  // x, y, z

/******************************
*    FORWARD DECLARATIONS     *
*******************************/
class WcPt3D;

/******************************
*     FUNCTION PROTOTYPES     *
*******************************/
void renderSky();
