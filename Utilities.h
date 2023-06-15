#pragma once
/*****************************************************************//**
 * \file   Utilities.h
 * \brief  
 * 
 * \author aaron
 * \date   June 2023
 *********************************************************************/

/******************************
*    FORWARD DECLARATIONS     *
*******************************/
class WcPt3D;
class WcVector3D;

/******************************
*     FUNCTION PROTOTYPES     *
*******************************/
WcVector3D crossProduct(const WcVector3D& v1, const WcVector3D& v2);
WcVector3D getNormalVector(const WcPt3D& v1, const WcPt3D& v2, const WcPt3D& v3);
