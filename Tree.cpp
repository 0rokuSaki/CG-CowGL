/*****************************************************************//**
 * \file   Tree.cpp
 * \brief  
 * 
 * \author aaron
 * \date   May 2023
 *********************************************************************/

/******************************
*          INCLUDES           *
*******************************/
#include <GL/glut.h>
#include "Tree.h"
#include "WcPt3D.h"
#include "RGBColor.h"

/******************************
*     FUNCTION DEFINITIONS    *
*******************************/
void renderTree(WcPt3D center)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glColor3d(RGB_COLOR_DARK_BROWN);
    /* Base */
    glTranslated(center.getX(), center.getY(), center.getZ());
    glutSolidCone(TREE_BASE_RADIUS, TREE_BASE_HEIGHT, TREE_CONE_NUM_SLICES, TREE_CONE_NUM_STACKS);
    glPopMatrix();
    glPushMatrix();

    /* Branch #1 */
    glTranslated(center.getX() + TREE_BRANCH1_TRANSLATION_X, center.getY() + TREE_BRANCH1_TRANSLATION_Y, center.getZ() + TREE_BRANCH1_TRANSLATION_Z);
    glRotated(TREE_BRANCH1_ROTATION_ANGLE, TREE_BRANCH1_ROTATION_VECTOR);
    glutSolidCone(TREE_BRANCH1_RADIUS, TREE_BRANCH1_LENGTH, TREE_CONE_NUM_SLICES, TREE_CONE_NUM_STACKS);
    glPopMatrix();
    glPushMatrix();

    /* Branch #2 */
    glTranslated(center.getX() + TREE_BRANCH2_TRANSLATION_X, center.getY() + TREE_BRANCH2_TRANSLATION_Y, center.getZ() + TREE_BRANCH2_TRANSLATION_Z);
    glRotated(TREE_BRANCH2_ROTATION_ANGLE, TREE_BRANCH2_ROTATION_VECTOR);
    glutSolidCone(TREE_BRANCH2_RADIUS, TREE_BRANCH2_LENGTH, TREE_CONE_NUM_SLICES, TREE_CONE_NUM_STACKS);
    glPopMatrix();
    glPushMatrix();

    /* Branch #3 */
    glTranslated(center.getX() + TREE_BRANCH3_TRANSLATION_X, center.getY() + TREE_BRANCH3_TRANSLATION_Y, center.getZ() + TREE_BRANCH3_TRANSLATION_Z);
    glRotated(TREE_BRANCH3_ROTATION_ANGLE, TREE_BRANCH3_ROTATION_VECTOR);
    glutSolidCone(TREE_BRANCH3_RADIUS, TREE_BRANCH3_LENGTH, TREE_CONE_NUM_SLICES, TREE_CONE_NUM_STACKS);
    glPopMatrix();
    glPushMatrix();

    /* Base sphere */
    glTranslated(center.getX(), center.getY(), center.getZ() + TREE_BASE_HEIGHT);
    glColor3d(RGB_COLOR_MEDIUM_GREEN);
    glutSolidSphere(TREE_BASE_SPHERE_RADIUS, TREE_SPHERE_NUM_SLICES, TREE_SPHERE_NUM_STACKS);
    glPopMatrix();
    glPushMatrix();

    /* Branch #1 sphere */
    glColor3d(RGB_COLOR_DARK_GREEN);
    glTranslated(center.getX() + TREE_BRANCH1_SPHERE_TRANSLATION_X, center.getY() + TREE_BRANCH1_SPHERE_TRANSLATION_Y, center.getZ() + TREE_BRANCH1_SPHERE_TRANSLATION_Z);
    glutSolidSphere(TREE_BRANCH1_SPHERE_RADIUS, TREE_SPHERE_NUM_SLICES, TREE_SPHERE_NUM_STACKS);
    glPopMatrix();
    glPushMatrix();

    /* Branch #2 sphere */
    glColor3d(RGB_COLOR_MEDIUM_GREEN);
    glTranslated(center.getX() + TREE_BRANCH2_SPHERE_TRANSLATION_X, center.getY() + TREE_BRANCH2_SPHERE_TRANSLATION_Y, center.getZ() + TREE_BRANCH2_SPHERE_TRANSLATION_Z);
    glutSolidSphere(TREE_BRANCH2_SPHERE_RADIUS, TREE_SPHERE_NUM_SLICES, TREE_SPHERE_NUM_STACKS);
    glPopMatrix();
    glPushMatrix();

    /* Branch #3 sphere */
    glColor3d(RGB_COLOR_DARK_GREEN);
    glTranslated(center.getX() + TREE_BRANCH3_SPHERE_TRANSLATION_X, center.getY() + TREE_BRANCH3_SPHERE_TRANSLATION_Y, center.getZ() + TREE_BRANCH3_SPHERE_TRANSLATION_Z);
    glutSolidSphere(TREE_BRANCH3_SPHERE_RADIUS, TREE_SPHERE_NUM_SLICES, TREE_SPHERE_NUM_STACKS);
    glPopMatrix();
    glPushMatrix();

    glPopMatrix();
}
