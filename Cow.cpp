/*****************************************************************//**
 * \file   Cow.cpp
 * \brief  
 * 
 * \author aaron
 * \date   June 2023
 *********************************************************************/

/******************************
*          INCLUDES           *
*******************************/
#include "Cow.h"
#include "RGBColor.h"

/******************************
*       GLOBAL VARIABLES      *
*******************************/
static const GLint TESSELLATION_RES = 30;

static const GLfloat COW_BODY_LENGTH = 1.4;
static const GLfloat COW_BODY_RADIUS = 0.5;

static const GLfloat COW_LEG_LENGTH = 1.0;
static const GLfloat COW_LEG_RADIUS = 0.1;
static const GLfloat COW_HOOF_LENGTH = 0.15;
static const GLfloat COW_HOOF_RADIUS = COW_LEG_RADIUS + 0.005;

static const GLfloat COW_UDDER_RADIUS = 0.3;
static const GLfloat COW_UDDER_OFFSET_X = 0.5;
static const GLfloat COW_UDDER_OFFSET_Z = 0.4;

static const GLfloat cowBrownColor[] = { RGB_COLOR_COW_BROWN, 1.0 };
static const GLfloat darkGrayColor[] = { RGB_COLOR_DARK_GRAY, 1.0 };
static const GLfloat pinkColor[] = { RGB_COLOR_PINK, 1.0 };
static const GLfloat blackColor[] = { RGB_COLOR_BLACK, 1.0 };
static const GLfloat whiteColor[] = { RGB_COLOR_WHITE, 1.0 };

/******************************
*     FUNCTION PROTOTYPES     *
*******************************/
inline void renderHoof(void);

/******************************
*    FUNCTION DEFINITIONS     *
*******************************/
Cow::Cow() :
	_pos(0, 0, 0),
	_directionAngle(0.0),
	_headAngleHorizontal(0.0),
	_headAngleVertical(0.0),
	_tailAngleHorizontal(0.0),
	_tailAngleVertical(0.0)
{
}


Cow::Cow(GLfloat x, GLfloat y, GLfloat z) :
	_pos(x, y, z),
	_directionAngle(0.0),
	_headAngleHorizontal(0.0),
	_headAngleVertical(0.0),
	_tailAngleHorizontal(0.0),
	_tailAngleVertical(0.0)
{
}


Cow::Cow(WcPt3D pos) :
	_pos(pos),
	_directionAngle(0.0),
	_headAngleHorizontal(0.0),
	_headAngleVertical(0.0),
	_tailAngleHorizontal(0.0),
	_tailAngleVertical(0.0)
{
}


void Cow::render()
{
	glEnable(GL_LIGHTING);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	/* Common */
	glRotatef(_directionAngle, 0.0, 0.0, 1.0);
	glTranslatef(_pos.getX(), _pos.getY(), _pos.getZ());
	glMaterialfv(GL_FRONT, GL_EMISSION, blackColor);
	glMaterialfv(GL_FRONT, GL_SPECULAR, blackColor);

	GLUquadric* quadric = gluNewQuadric();

	/* Body */
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cowBrownColor);
	glTranslatef(0.0, 0.0, COW_LEG_LENGTH);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	glRotatef(180.0, 1.0, 0.0, 0.0);
	gluDisk(quadric, 0.0, COW_BODY_RADIUS, TESSELLATION_RES, TESSELLATION_RES);
	glRotatef(180.0, -1.0, 0.0, 0.0);
	gluCylinder(quadric, COW_BODY_RADIUS, COW_BODY_RADIUS, COW_BODY_LENGTH, TESSELLATION_RES, TESSELLATION_RES);
	glTranslatef(0, 0, COW_BODY_LENGTH);
	glutSolidSphere(COW_BODY_RADIUS, TESSELLATION_RES, TESSELLATION_RES);
	glTranslatef(0, 0, -COW_BODY_LENGTH);

	/* Legs & hooves */
	glPushMatrix();

	/* Back - left */
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cowBrownColor);
	glTranslatef(0.0, COW_BODY_RADIUS - COW_LEG_RADIUS, COW_LEG_RADIUS);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	gluCylinder(quadric, COW_LEG_RADIUS, COW_LEG_RADIUS, COW_LEG_LENGTH, TESSELLATION_RES, TESSELLATION_RES);
	renderHoof();
	
	/* Back - right */
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cowBrownColor);
	glTranslatef(0.0, (-2 * COW_BODY_RADIUS) + (2 * COW_LEG_RADIUS), 0.0);
	gluCylinder(quadric, COW_LEG_RADIUS, COW_LEG_RADIUS, COW_LEG_LENGTH, TESSELLATION_RES, TESSELLATION_RES);
	renderHoof();

	/* Front - right */
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cowBrownColor);
	glRotatef(90.0, 0.0, -1.0, 0.0);
	glTranslatef(0.0, 0.0, COW_BODY_LENGTH - (2 * COW_LEG_RADIUS));
	glRotatef(90.0, 0.0, 1.0, 0.0);
	gluCylinder(quadric, COW_LEG_RADIUS, COW_LEG_RADIUS, COW_LEG_LENGTH, TESSELLATION_RES, TESSELLATION_RES);
	renderHoof();

	/* Front - left */
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cowBrownColor);
	glTranslatef(0.0, 2 * COW_BODY_RADIUS - 2 * COW_LEG_RADIUS, 0.0);
	gluCylinder(quadric, COW_LEG_RADIUS, COW_LEG_RADIUS, COW_LEG_LENGTH, TESSELLATION_RES, TESSELLATION_RES);
	renderHoof();

	glPopMatrix();

	/* Udder */
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, pinkColor);
	glMaterialfv(GL_FRONT, GL_EMISSION, blackColor);
	glMaterialfv(GL_FRONT, GL_SPECULAR, blackColor);

	glPushMatrix();
	glTranslatef(COW_UDDER_OFFSET_X, 0.0, COW_UDDER_OFFSET_Z);
	glutSolidSphere(COW_UDDER_RADIUS, TESSELLATION_RES, TESSELLATION_RES);
	glPopMatrix();

	gluDeleteQuadric(quadric);

	glPopMatrix();
	glDisable(GL_LIGHTING);
}


void Cow::moveForward(void)
{
}


void Cow::moveBackward(void)
{
}


void Cow::turnLeft(void)
{
}


void Cow::turnRight(void)
{
}


void Cow::moveHeadUp(void)
{
}


void Cow::moveHeadDown(void)
{
}


void Cow::turnHeadLeft(void)
{
}


void Cow::turnHeadRight(void)
{
}


void Cow::moveTailUp(void)
{
}


void Cow::moveTailDown(void)
{
}


void Cow::turnTailLeft(void)
{
}


void Cow::turnTailRight(void)
{
}


void renderHoof(void)
{
	GLUquadric* quadric = gluNewQuadric();

	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, darkGrayColor);
	glTranslatef(0.0, 0.0, COW_LEG_LENGTH - COW_HOOF_LENGTH);
	gluCylinder(quadric, COW_HOOF_RADIUS, COW_HOOF_RADIUS, COW_HOOF_LENGTH, TESSELLATION_RES, TESSELLATION_RES);
	glTranslatef(0.0, 0.0, -(COW_LEG_LENGTH - COW_HOOF_LENGTH));

	gluDeleteQuadric(quadric);
}
