#pragma once
/*****************************************************************//**
 * \file   Cow.h
 * \brief  
 * 
 * \author aaron
 * \date   June 2023
 *********************************************************************/

/******************************
*          INCLUDES           *
*******************************/
#include <GL/glut.h>
#include "WcPt3D.h"

class Cow
{
public:
	Cow();
	Cow(WcPt3D pos);
	Cow(GLfloat x, GLfloat y, GLfloat z);
	void render(void);

	void setPosition(WcPt3D pos);
	void setDirectionAngle(GLfloat directionAngle);

	/* Cow movement */
	void moveForward(void);
	void moveBackward(void);
	void turnLeft(void);
	void turnRight(void);

	/* Head movement */
	void moveHeadUp(void);
	void moveHeadDown(void);
	void turnHeadLeft(void);
	void turnHeadRight(void);

	/* Tail movement */
	void moveTailUp(void);
	void moveTailDown(void);
	void turnTailLeft(void);
	void turnTailRight(void);

	/* Camera controls */
	void TPCamRotateCW(void);
	void TPCamRotateCCW(void);
	void TPCamRotateUp(void);
	void TPCamRotateDown(void);
	void TPCamIncreaseRadius(void);
	void TPCamDecreaseRadius(void);

	/* Getters */
	GLfloat getTpCamRadius(void);
	GLfloat getTpCamVerticalAngle(void);
	GLfloat getTpCamHorizontalAngle(void);

private:
	void _renderBody(void);
	void _renderHead(void);
	void _renderTail(void);

	void _renderFirstPersonCamera(void);
	void _renderThirdPersonCamera(void);
	WcPt3D _pos;
	GLfloat _directionAngle;
	GLfloat _headAngleHorizontal, _headAngleVertical;
	GLfloat _tailAngleHorizontal, _tailAngleVertical;
	GLfloat _tpCamRadius, _tpCamVerticalAngle, _tpCamHorizontalAngle;
};
