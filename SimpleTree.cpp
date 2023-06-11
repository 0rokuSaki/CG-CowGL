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
#include "SimpleTree.h"
#include "WcPt3D.h"
#include "RGBColor.h"

/******************************
*     FUNCTION DEFINITIONS    *
*******************************/
void renderSimpleTree(WcPt3D pos)
{
    /* Tree stem parameters */
    static const RGBColor TREE_STEM_COLOR(RGB_COLOR_DARK_BROWN);
    static const GLdouble TREE_STEM_BASE_RADIUS = 0.5;
    static const GLdouble TREE_STEM_HEIGHT = 8.0;
    static const GLint TREE_STEM_NUM_SLICES = 10;
    static const GLint TREE_STEM_NUM_STACKS = 10;

    /* Leaf parameters */
    static const RGBColor LEAF_COLOR1(RGB_COLOR_DARK_GREEN);
    static const RGBColor LEAF_COLOR2(RGB_COLOR_MEDIUM_GREEN);
    static const RGBColor LEAF_COLOR3(RGB_COLOR_FOREST_GREEN);
    static const GLdouble LEAF_BASE_WIDTH1 = 1.5;
    static const GLdouble LEAF_BASE_WIDTH2 = 1.25;
    static const GLdouble LEAF_BASE_WIDTH3 = 1.0;
    static const GLdouble LEAF_HEIGHT = 2.0;
    static const GLint LEAF_NUM_SLICES = 25;
    static const GLint LEAF_NUM_STACKS = 25;

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glTranslated(pos.getX(), pos.getY(), pos.getZ());  // move tree to pos

    /* Render tree stem */
    glColor3d(TREE_STEM_COLOR.getR(), TREE_STEM_COLOR.getG(), TREE_STEM_COLOR.getB());
    glutSolidCone(TREE_STEM_BASE_RADIUS, TREE_STEM_HEIGHT, TREE_STEM_NUM_SLICES, TREE_STEM_NUM_STACKS);

    /* Render leaf #1 */
    glColor3d(LEAF_COLOR1.getR(), LEAF_COLOR1.getG(), LEAF_COLOR1.getB());
    glTranslatef(0.0, 0.0, LEAF_HEIGHT);
    glutSolidCone(LEAF_BASE_WIDTH1, LEAF_HEIGHT, LEAF_NUM_SLICES, LEAF_NUM_STACKS);

    /* Render leaf #2 */
    glColor3d(LEAF_COLOR2.getR(), LEAF_COLOR2.getG(), LEAF_COLOR2.getB());
    glTranslatef(0.0, 0.0, LEAF_HEIGHT);
    glutSolidCone(LEAF_BASE_WIDTH2, LEAF_HEIGHT, LEAF_NUM_SLICES, LEAF_NUM_STACKS);

    /* Render leaf #3 */
    glColor3d(LEAF_COLOR3.getR(), LEAF_COLOR3.getG(), LEAF_COLOR3.getB());
    glTranslatef(0.0, 0.0, LEAF_HEIGHT);
    glutSolidCone(LEAF_BASE_WIDTH3, LEAF_HEIGHT, LEAF_NUM_SLICES, LEAF_NUM_STACKS);

    glPopMatrix();
}
