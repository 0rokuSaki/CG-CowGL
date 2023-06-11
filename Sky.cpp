/*****************************************************************//**
 * \file   Sky.cpp
 * \brief  
 * 
 * \author aaron
 * \date   June 2023
 *********************************************************************/

/******************************
*          INCLUDES           *
*******************************/
#include <GL/glut.h>
#include "Sky.h"
#include "RGBColor.h"

/******************************
*     FUNCTION DEFINITIONS    *
*******************************/
void renderSky()
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	/* Render sky */
	glColor3d(RGB_COLOR_SKY_BLUE);
	glutSolidSphere(SKY_SPHERE_PROPERTIES);

	/* Render sun */
	glTranslated(SKY_SUN_POSITION);
	glColor3d(RGB_COLOR_SUN_YELLOW);
	glutSolidSphere(SKY_SUN_SPHERE_PROPERTIES);

	glPopMatrix();
}
