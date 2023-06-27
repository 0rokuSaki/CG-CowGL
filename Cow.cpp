/*****************************************************************//**
 * \file   Cow.cpp
 * \brief  
 * 
 * \author aaron
 * \date   June 2023
 *********************************************************************/

/******************************
*          DEFINES            *
*******************************/
#define _USE_MATH_DEFINES

/******************************
*          INCLUDES           *
*******************************/
#include <cmath>

#include "Cow.h"
#include "SceneObjects.h"
#include "RGBColor.h"

/******************************
*       GLOBAL VARIABLES      *
*******************************/
static const GLfloat INIT_TAIL_VERTICAL_ANGLE = -70.0;

static const GLfloat cowBrownColor[] = { RGB_COLOR_COW_BROWN, 1.0 };
static const GLfloat darkGrayColor[] = { RGB_COLOR_DARK_GRAY, 1.0 };
static const GLfloat pinkColor[] = { RGB_COLOR_PINK, 1.0 };
static const GLfloat ivoryColor[] = { RGB_COLOR_IVORY, 1.0 };
static const GLfloat walnutColor[] = { RGB_COLOR_WALNUT, 1.0 };
static const GLfloat blackColor[] = { RGB_COLOR_BLACK, 1.0 };
static const GLfloat whiteColor[] = { RGB_COLOR_WHITE, 1.0 };

static const GLfloat MOVEMENT_DIFF = 0.1;
static const GLfloat ROTATION_DIFF = 1.0;
static const GLfloat HEAD_MOVEMENT_DIFF = 1.0;
static const GLfloat TAIL_MOVEMENT_DIFF = 1.0;

static const GLfloat HEAD_MAX_HORIZONTAL_ANGLE = 80.0;
static const GLfloat HEAD_MAX_VERTICAL_ANGLE = 60.0;
static const GLfloat TAIL_MAX_HORIZONTAL_ANGLE = 80.0;
static const GLfloat TAIL_MAX_VERTICAL_ANGLE = 90.0;

/******************************
*    FUNCTION DEFINITIONS     *
*******************************/
Cow::Cow() :
	_pos(0, 0, 0),
	_directionAngle(45.0),
	_headAngleHorizontal(0.0),
	_headAngleVertical(0.0),
	_tailAngleHorizontal(0.0),
	_tailAngleVertical(INIT_TAIL_VERTICAL_ANGLE)
{
}


Cow::Cow(GLfloat x, GLfloat y, GLfloat z) :
	_pos(x, y, z),
	_directionAngle(0.0),
	_headAngleHorizontal(0.0),
	_headAngleVertical(0.0),
	_tailAngleHorizontal(0.0),
	_tailAngleVertical(INIT_TAIL_VERTICAL_ANGLE)
{
}


Cow::Cow(WcPt3D pos) :
	_pos(pos),
	_directionAngle(0.0),
	_headAngleHorizontal(0.0),
	_headAngleVertical(0.0),
	_tailAngleHorizontal(0.0),
	_tailAngleVertical(INIT_TAIL_VERTICAL_ANGLE)
{
}


void Cow::render()
{
	glEnable(GL_LIGHTING);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	/* Common */
	glMaterialfv(GL_FRONT, GL_EMISSION, blackColor);
	glMaterialfv(GL_FRONT, GL_SPECULAR, blackColor);

	/* Render body parts */
	_renderBody();
	_renderHead();
	_renderTail();

	glPopMatrix();
	glDisable(GL_LIGHTING);
}


void Cow::setPosition(WcPt3D pos)
{
	_pos = pos;
}


void Cow::setDirectionAngle(GLfloat directionAngle)
{
	_directionAngle = directionAngle;
}


void Cow::moveForward(void)
{
	GLfloat newX = _pos.getX() + cos((_directionAngle * M_PI) / 180.0) * MOVEMENT_DIFF;
	GLfloat newY = _pos.getY() + sin((_directionAngle * M_PI) / 180.0) * MOVEMENT_DIFF;

	if ((WORLD_MIN_COORD <= newX && newX <= WORLD_MAX_COORD) &&
		(WORLD_MIN_COORD <= newY && newY <= WORLD_MAX_COORD))
	{
		_pos.setX(newX);
		_pos.setY(newY);
	}
}


void Cow::moveBackward(void)
{
	GLfloat newX = _pos.getX() - cos((_directionAngle * M_PI) / 180.0) * MOVEMENT_DIFF;
	GLfloat newY = _pos.getY() - sin((_directionAngle * M_PI) / 180.0) * MOVEMENT_DIFF;

	if ((WORLD_MIN_COORD <= newX && newX <= WORLD_MAX_COORD) &&
		(WORLD_MIN_COORD <= newY && newY <= WORLD_MAX_COORD))
	{
		_pos.setX(newX);
		_pos.setY(newY);
	}
}


void Cow::turnLeft(void)
{
	GLfloat newDirectionAngle = (_directionAngle + ROTATION_DIFF);
	if (newDirectionAngle >= 360.0)
	{
		newDirectionAngle -= 360.0;
	}
	_directionAngle = newDirectionAngle;
}


void Cow::turnRight(void)
{
	GLfloat newDirectionAngle = (_directionAngle - ROTATION_DIFF);
	if (newDirectionAngle <= 0.0)
	{
		newDirectionAngle += 360.0;
	}
	_directionAngle = newDirectionAngle;
}


void Cow::moveHeadUp(void)
{
	GLfloat newHeadAngleVertical = _headAngleVertical + HEAD_MOVEMENT_DIFF;
	if (newHeadAngleVertical <= HEAD_MAX_VERTICAL_ANGLE)
	{
		_headAngleVertical = newHeadAngleVertical;
	}
}


void Cow::moveHeadDown(void)
{
	GLfloat newHeadAngleVertical = _headAngleVertical - HEAD_MOVEMENT_DIFF;
	if (newHeadAngleVertical >= -HEAD_MAX_VERTICAL_ANGLE)
	{
		_headAngleVertical = newHeadAngleVertical;
	}
}


void Cow::turnHeadLeft(void)
{
	GLfloat newHeadAngleHorizontal = _headAngleHorizontal + HEAD_MOVEMENT_DIFF;
	if (newHeadAngleHorizontal <= HEAD_MAX_HORIZONTAL_ANGLE)
	{
		_headAngleHorizontal = newHeadAngleHorizontal;
	}
}


void Cow::turnHeadRight(void)
{
	GLfloat newHeadAngleHorizontal = _headAngleHorizontal - HEAD_MOVEMENT_DIFF;
	if (newHeadAngleHorizontal >= -HEAD_MAX_HORIZONTAL_ANGLE)
	{
		_headAngleHorizontal = newHeadAngleHorizontal;
	}
}


void Cow::moveTailUp(void)
{
	GLfloat newTailAngleVertical = _tailAngleVertical + TAIL_MOVEMENT_DIFF;
	if (newTailAngleVertical <= TAIL_MAX_VERTICAL_ANGLE)
	{
		_tailAngleVertical = newTailAngleVertical;
	}
}


void Cow::moveTailDown(void)
{
	GLfloat newTailAngleVertical = _tailAngleVertical - TAIL_MOVEMENT_DIFF;
	if (newTailAngleVertical >= -TAIL_MAX_VERTICAL_ANGLE)
	{
		_tailAngleVertical = newTailAngleVertical;
	}
}


void Cow::turnTailLeft(void)
{
	GLfloat newTailAngleHorizontal = _tailAngleHorizontal + TAIL_MOVEMENT_DIFF;
	if (newTailAngleHorizontal <= TAIL_MAX_HORIZONTAL_ANGLE)
	{
		_tailAngleHorizontal = newTailAngleHorizontal;
	}
}


void Cow::turnTailRight(void)
{
	GLfloat newTailAngleHorizontal = _tailAngleHorizontal - TAIL_MOVEMENT_DIFF;
	if (newTailAngleHorizontal >= -TAIL_MAX_HORIZONTAL_ANGLE)
	{
		_tailAngleHorizontal = newTailAngleHorizontal;
	}
}


void Cow::_renderBody(void)
{
	GLUquadric* quadric = gluNewQuadric();

	glPushMatrix();

	glTranslatef(_pos.getX(), _pos.getY(), _pos.getZ());
	glRotatef(_directionAngle, 0.0, 0.0, 1.0);

	/* Body */
	glPushMatrix();
	glTranslatef(-0.7, 0.0, 1.0);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cowBrownColor);
	gluCylinder(quadric, 0.5, 0.5, 1.4, 20, 20);  // Main body
	glRotatef(180.0, 1.0, 0.0, 0.0);
	gluDisk(quadric, 0.0, 0.5, 20, 20);  // Main body back end (butt)
	glTranslatef(0.0, 0.0, -1.4);
	glutSolidSphere(0.5, 20, 20);  // Neck
	glPopMatrix();

	/* Udder */
	glPushMatrix();
	glTranslatef(-0.25, 0.0, 0.5);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, pinkColor);
	glutSolidSphere(0.35, 20, 20);
	glPopMatrix();

	/* Leg - rear left */
	glPushMatrix();
	glTranslatef(-0.6, 0.4, 0.0);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cowBrownColor);
	gluCylinder(quadric, 0.1, 0.1, 1.0, 20, 20);  // Leg
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, darkGrayColor);
	gluCylinder(quadric, 0.10002, 0.10002, 0.15, 20, 20);  // Hoof
	glPopMatrix();

	/* Leg - rear right */
	glPushMatrix();
	glTranslatef(-0.6, -0.4, 0.0);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cowBrownColor);
	gluCylinder(quadric, 0.1, 0.1, 1.0, 20, 20);  // Leg
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, darkGrayColor);
	gluCylinder(quadric, 0.10002, 0.10002, 0.15, 20, 20);  // Hoof
	glPopMatrix();

	/* Leg - front left */
	glPushMatrix();
	glTranslatef(0.6, 0.4, 0.0);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cowBrownColor);
	gluCylinder(quadric, 0.1, 0.1, 1.0, 20, 20);  // Leg
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, darkGrayColor);
	gluCylinder(quadric, 0.10002, 0.10002, 0.15, 20, 20);  // Hoof
	glPopMatrix();

	/* Leg - front right */
	glPushMatrix();
	glTranslatef(0.6, -0.4, 0.0);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cowBrownColor);
	gluCylinder(quadric, 0.1, 0.1, 1.0, 20, 20);  // Leg
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, darkGrayColor);
	gluCylinder(quadric, 0.10002, 0.10002, 0.15, 20, 20);  // Hoof
	glPopMatrix();
	
	glPopMatrix();

	gluDeleteQuadric(quadric);
}


void Cow::_renderHead(void)
{
	GLUquadric* quadric = gluNewQuadric();

	glPushMatrix();

	glTranslatef(_pos.getX(), _pos.getY(), _pos.getZ());  // Translate modeling coordinates
	glRotatef(_directionAngle, 0.0, 0.0, 1.0);
	glTranslatef(1.1, 0.0, 1.3);  // Move head relative to cow's body
	glRotatef(_headAngleHorizontal, 0.0, 0.0, 1.0);
	glRotatef(_headAngleVertical, 0.0, -1.0, 0.0);

	/* Head */
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cowBrownColor);
	glPushMatrix();
	glutSolidSphere(0.4, 20, 20);  // Head sphere
	glPopMatrix();

	/* Horns */
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, ivoryColor);
	glPushMatrix();
	glRotatef(20.0, 0.0, 1.0, 0.0);
	glPushMatrix();
	glRotatef(20.0, 1.0, 0.0, 0.0);
	glutSolidCone(0.15, 0.6, 20, 20);
	glPopMatrix();
	glPushMatrix();
	glRotatef(20.0, -1.0, 0.0, 0.0);
	glutSolidCone(0.15, 0.6, 20, 20);
	glPopMatrix();
	glPopMatrix();

	/* Ears */
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cowBrownColor);
	glPushMatrix();
	glPushMatrix();
	glTranslatef(0.0, 0.34, 0.2);
	glRotatef(90, 0.0, 1.0, 0.0);
	gluDisk(quadric, 0.0, 0.1, 20, 20);  // Ear disk
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0, -0.34, 0.2);
	glRotatef(90, 0.0, 1.0, 0.0);
	gluDisk(quadric, 0.0, 0.1, 20, 20);  // Ear disk
	glPopMatrix();
	glPopMatrix();

	/* Nose */
	glPushMatrix();
	glTranslatef(0.25, 0.0, -0.2);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, pinkColor);
	glutSolidSphere(0.25, 20, 20);  // Nose sphere
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, darkGrayColor);
	glRotatef(105.0, 0.0, 1.0, 0.0);
	glPushMatrix();
	glRotatef(25.0, 1.0, 0.0, 0.0);
	glTranslatef(0.0, 0.0, 0.250001);
	gluDisk(quadric, 0.0, 0.02, 20, 20);  // Nostril
	glPopMatrix();
	glPushMatrix();
	glRotatef(25.0, -1.0, 0.0, 0.0);
	glTranslatef(0.0, 0.0, 0.250001);
	gluDisk(quadric, 0.0, 0.02, 20, 20);  // Nostril
	glPopMatrix();
	glPopMatrix();

	/* Eyes */
	glPushMatrix();
	glRotatef(80.0, 0.0, 1.0, 0.0);
	glPushMatrix();
	glRotatef(15, 1.0, 0.0, 0.0);
	glTranslatef(0.0, 0.0, 0.40001);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, whiteColor);
	gluDisk(quadric, 0.0, 0.04, 20, 20);  // Eyeball
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, blackColor);
	glTranslatef(0.0, 0.0, 0.001);
	gluDisk(quadric, 0.0, 0.025, 20, 20);  // Pupil
	glPopMatrix();
	glPushMatrix();
	glRotatef(15, -1.0, 0.0, 0.0);
	glTranslatef(0.0, 0.0, 0.40001);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, whiteColor);
	gluDisk(quadric, 0.0, 0.04, 20, 20);  // Eyeball
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, blackColor);
	glTranslatef(0.0, 0.0, 0.001);
	gluDisk(quadric, 0.0, 0.025, 20, 20);  // Pupil
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();

	gluDeleteQuadric(quadric);
}


void Cow::_renderTail(void)
{
	GLUquadric* quadric = gluNewQuadric();

	glPushMatrix();

	glTranslatef(_pos.getX(), _pos.getY(), _pos.getZ());  // Translate modeling coordinates
	glRotatef(_directionAngle, 0.0, 0.0, 1.0);
	glTranslatef(-0.69, 0.0, 1.45);  // Move tail relative to cow's body
	glRotatef(_tailAngleHorizontal, 0.0, 0.0, -1.0);
	glRotatef(_tailAngleVertical, 0.0, 1.0, 0.0);

	glRotatef(90.0, 0.0, -1.0, 0.0);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cowBrownColor);
	glutSolidSphere(0.05, 20, 20);
	gluCylinder(quadric, 0.05, 0.05, 0.75, 20, 20);
	glTranslatef(0.0, 0.0, 0.75);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, walnutColor);
	glutSolidSphere(0.075, 20, 20);
	glPopMatrix();

	gluDeleteQuadric(quadric);
}
