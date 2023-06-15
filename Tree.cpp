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
void renderTree(WcPt3D position)
{
    /* Tree stem parameters */
    static const GLdouble TREE_STEM_BASE_RADIUS = 0.5;
    static const GLdouble TREE_STEM_HEIGHT = 8.0;
    static const GLint TREE_STEM_NUM_SLICES = 10;
    static const GLint TREE_STEM_NUM_STACKS = 10;

    /* Leaf parameters */
    static const GLdouble LEAF_BASE_WIDTH1 = 1.5;
    static const GLdouble LEAF_BASE_WIDTH2 = 1.25;
    static const GLdouble LEAF_BASE_WIDTH3 = 1.0;
    static const GLdouble LEAF_HEIGHT = 2.5;
    static const GLdouble LEAF_HEIGHT_FROM_GROUND = 2.0;
    static const GLint LEAF_NUM_SLICES = 25;
    static const GLint LEAF_NUM_STACKS = 25;

    /* Lighting */
    static const GLfloat darkBrownColor[] = { RGB_COLOR_DARK_BROWN, 1.0 };
    static const GLfloat darkGreenColor[] = { RGB_COLOR_DARK_GREEN, 1.0 };
    static const GLfloat mediumGreenColor[] = { RGB_COLOR_MEDIUM_GREEN, 1.0 };
    static const GLfloat forestGreenColor[] = { RGB_COLOR_FOREST_GREEN, 1.0 };
    static const GLfloat blackColor[] = { RGB_COLOR_BLACK, 1.0 };
    static const GLfloat whiteColor[] = { RGB_COLOR_WHITE, 1.0 };

    glEnable(GL_LIGHTING);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glTranslated(position.getX(), position.getY(), position.getZ());  // move tree to position

    /* Render tree stem */
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, darkBrownColor);
    glMaterialfv(GL_FRONT, GL_EMISSION, blackColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, blackColor);

    glutSolidCone(TREE_STEM_BASE_RADIUS, TREE_STEM_HEIGHT, TREE_STEM_NUM_SLICES, TREE_STEM_NUM_STACKS);

    GLUquadric* disk = gluNewQuadric();

    /* Render leaf #1 */
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, darkGreenColor);
    glMaterialfv(GL_FRONT, GL_EMISSION, blackColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, blackColor);

    glTranslatef(0.0, 0.0, LEAF_HEIGHT_FROM_GROUND);
    gluDisk(disk, 0.0, LEAF_BASE_WIDTH1, LEAF_NUM_SLICES, LEAF_NUM_STACKS);
    glutSolidCone(LEAF_BASE_WIDTH1, LEAF_HEIGHT, LEAF_NUM_SLICES, LEAF_NUM_STACKS);

    /* Render leaf #2 */
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mediumGreenColor);
    glMaterialfv(GL_FRONT, GL_EMISSION, blackColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, blackColor);

    glTranslatef(0.0, 0.0, LEAF_HEIGHT_FROM_GROUND);
    gluDisk(disk, 0.0, LEAF_BASE_WIDTH2, LEAF_NUM_SLICES, LEAF_NUM_STACKS);
    glutSolidCone(LEAF_BASE_WIDTH2, LEAF_HEIGHT, LEAF_NUM_SLICES, LEAF_NUM_STACKS);

    /* Render leaf #3 */
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, forestGreenColor);
    glMaterialfv(GL_FRONT, GL_EMISSION, blackColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, blackColor);

    glTranslatef(0.0, 0.0, LEAF_HEIGHT_FROM_GROUND);
    gluDisk(disk, 0.0, LEAF_BASE_WIDTH3, LEAF_NUM_SLICES, LEAF_NUM_STACKS);
    glutSolidCone(LEAF_BASE_WIDTH3, LEAF_HEIGHT, LEAF_NUM_SLICES, LEAF_NUM_STACKS);

    gluDeleteQuadric(disk);

    glPopMatrix();
    glDisable(GL_LIGHTING);
}
