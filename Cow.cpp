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

static const GLfloat MOVEMENT_DIFF = 0.25;
static const GLfloat ROTATION_DIFF = 1.0;
static const GLfloat HEAD_MOVEMENT_DIFF = 1.0;
static const GLfloat TAIL_MOVEMENT_DIFF = 1.0;

/******************************
*    FUNCTION DEFINITIONS     *
*******************************/
Cow::Cow() :
	_pos(0, 0, 0),
	_directionAngle(0.0),
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


void Cow::_renderBody(void)
{
	GLUquadric* quadric = gluNewQuadric();

	glPushMatrix();

	glTranslatef(_pos.getX(), _pos.getY(), _pos.getZ());
	glRotatef(_directionAngle, 0.0, 0.0, 1.0);

	/* Body */
	glPushMatrix();
	glTranslatef(0.0, -0.7, 1.0);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cowBrownColor);
	gluCylinder(quadric, 0.5, 0.5, 1.4, 20, 20);  // Main body
	glRotatef(180.0, 1.0, 0.0, 0.0);
	gluDisk(quadric, 0.0, 0.5, 20, 20);  // Main body back end (butt)
	glTranslatef(0.0, 0.0, -1.4);
	glutSolidSphere(0.5, 20, 20);  // Neck
	glPopMatrix();

	/* Udder */
	glPushMatrix();
	glTranslatef(0.0, -0.25, 0.5);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, pinkColor);
	glutSolidSphere(0.35, 20, 20);
	glPopMatrix();

	/* Leg - rear left */
	glPushMatrix();
	glTranslatef(-0.4, -0.6, 0.0);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cowBrownColor);
	gluCylinder(quadric, 0.1, 0.1, 1.0, 20, 20);  // Leg
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, darkGrayColor);
	gluCylinder(quadric, 0.10001, 0.10001, 0.15, 20, 20);  // Hoof
	glPopMatrix();

	/* Leg - rear right */
	glPushMatrix();
	glTranslatef(0.4, -0.6, 0.0);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cowBrownColor);
	gluCylinder(quadric, 0.1, 0.1, 1.0, 20, 20);  // Leg
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, darkGrayColor);
	gluCylinder(quadric, 0.10001, 0.10001, 0.15, 20, 20);  // Hoof
	glPopMatrix();

	/* Leg - front left */
	glPushMatrix();
	glTranslatef(-0.4, 0.6, 0.0);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cowBrownColor);
	gluCylinder(quadric, 0.1, 0.1, 1.0, 20, 20);  // Leg
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, darkGrayColor);
	gluCylinder(quadric, 0.10001, 0.10001, 0.15, 20, 20);  // Hoof
	glPopMatrix();

	/* Leg - front right */
	glPushMatrix();
	glTranslatef(0.4, 0.6, 0.0);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cowBrownColor);
	gluCylinder(quadric, 0.1, 0.1, 1.0, 20, 20);  // Leg
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, darkGrayColor);
	gluCylinder(quadric, 0.10001, 0.10001, 0.15, 20, 20);  // Hoof
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
	glTranslatef(0.0, 1.1, 1.3);  // Move head relative to cow's body
	glRotatef(_headAngleHorizontal, 0.0, 0.0, 1.0);
	glRotatef(_headAngleVertical, 1.0, 0.0, 0.0);

	/* Head */
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cowBrownColor);
	glPushMatrix();
	glutSolidSphere(0.4, 20, 20);  // Head sphere
	glPopMatrix();

	/* Horns */
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, ivoryColor);
	glPushMatrix();
	glRotatef(20.0, -1.0, 0.0, 0.0);
	glPushMatrix();
	glRotatef(20.0, 0.0, 1.0, 0.0);
	glutSolidCone(0.15, 0.6, 20, 20);
	glPopMatrix();
	glPushMatrix();
	glRotatef(20.0, 0.0, -1.0, 0.0);
	glutSolidCone(0.15, 0.6, 20, 20);
	glPopMatrix();
	glPopMatrix();

	/* Ears */
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cowBrownColor);
	glPushMatrix();
	glPushMatrix();
	glTranslatef(0.34, 0.0, 0.2);
	glRotatef(90, 1.0, 0.0, 0.0);
	gluDisk(quadric, 0.0, 0.1, 20, 20);  // Ear disk
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-0.34, 0.0, 0.2);
	glRotatef(90, 1.0, 0.0, 0.0);
	gluDisk(quadric, 0.0, 0.1, 20, 20);  // Ear disk
	glPopMatrix();
	glPopMatrix();

	/* Nose */
	glPushMatrix();
	glTranslatef(0.0, 0.25, -0.2);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, pinkColor);
	glutSolidSphere(0.25, 20, 20);  // Nose sphere
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, darkGrayColor);
	glRotatef(105.0, -1.0, 0.0, 0.0);
	glPushMatrix();
	glRotatef(25.0, 0.0, 1.0, 0.0);
	glTranslatef(0.0, 0.0, 0.250001);
	gluDisk(quadric, 0.0, 0.02, 20, 20);  // Nostril
	glPopMatrix();
	glPushMatrix();
	glRotatef(25.0, 0.0, -1.0, 0.0);
	glTranslatef(0.0, 0.0, 0.250001);
	gluDisk(quadric, 0.0, 0.02, 20, 20);  // Nostril
	glPopMatrix();
	glPopMatrix();

	/* Eyes */
	glPushMatrix();
	glRotatef(80.0, -1.0, 0.0, 0.0);
	glPushMatrix();
	glRotatef(15, 0.0, 1.0, 0.0);
	glTranslatef(0.0, 0.0, 0.40001);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, whiteColor);
	gluDisk(quadric, 0.0, 0.04, 20, 20);  // Eyeball
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, blackColor);
	glTranslatef(0.0, 0.0, 0.001);
	gluDisk(quadric, 0.0, 0.025, 20, 20);  // Pupil
	glPopMatrix();
	glPushMatrix();
	glRotatef(15, 0.0, -1.0, 0.0);
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
	glTranslatef(0.0, -0.69, 1.45);  // Move tail relative to cow's body
	glRotatef(_tailAngleHorizontal, 0.0, 0.0, 1.0);
	glRotatef(_tailAngleVertical, -1.0, 0.0, 0.0);

	glRotatef(90.0, 1.0, 0.0, 0.0);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cowBrownColor);
	glutSolidSphere(0.05, 20, 20);
	gluCylinder(quadric, 0.05, 0.05, 0.75, 20, 20);
	glTranslatef(0.0, 0.0, 0.75);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, walnutColor);
	glutSolidSphere(0.075, 20, 20);
	glPopMatrix();

	gluDeleteQuadric(quadric);
}
