#pragma once
/*****************************************************************//**
 * \file   House.h
 * \brief  
 * 
 * \author aaron
 * \date   May 2023HOUSE_HOUSE_EPSILON
 *********************************************************************/

/******************************
*          DEFINES            *
*******************************/
#define HOUSE_WIDTH 5.0
#define HOUSE_LENGTH 7.0 

#define HOUSE_WALL_HEIGHT 3.25

#define HOUSE_ROOF_HEIGHT 2.0

#define HOUSE_DOOR_WIDTH 1.5
#define HOUSE_DOOR_HEIGHT 2.25
#define HOUSE_DOOR_KNOB_RADIUS 0.1

#define HOUSE_WINDOW_WIDTH 0.75
#define HOUSE_WINDOW_HEIGHT 1.5
#define HOUSE_WINDOW_HEIGHT_FROM_GROUND 1.0

#define HOUSE_EPSILON 0.05

/******************************
*    FORWARD DECLARATIONS     *
*******************************/
class WcPt3D;

/******************************
*     FUNCTION PROTOTYPES     *
*******************************/
void renderHouse(WcPt3D center);
