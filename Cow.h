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
	void switchCameraMode(void);
	void TPCamRotateCW(void);
	void TPCamRotateCCW(void);
	void TPCamRotateUp(void);
	void TPCamRotateDown(void);
	void TPCamIncreaseRadius(void);
	void TPCamDecreaseRadius(void);

private:
	void _renderBody(void);
	void _renderHead(void);
	void _renderTail(void);

	enum CameraMode
	{
		FIRST_PERSON = 0,
		THIRD_PERSON,
		LAST_OF_CAMERA_MODE
	};

	void _renderFirstPersonCamera(void);
	void _renderThirdPersonCamera(void);
	WcPt3D _pos;
	GLfloat _directionAngle;
	GLfloat _headAngleHorizontal, _headAngleVertical;
	GLfloat _tailAngleHorizontal, _tailAngleVertical;
	GLfloat _tpCameraRadius, _tpCamVerticalAngle, _tpCamHorizontalAngle;
	CameraMode _cameraMode;
};
