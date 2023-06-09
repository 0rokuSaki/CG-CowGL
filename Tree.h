#pragma once
/*****************************************************************//**
 * \file   Tree.h
 * \brief  
 * 
 * \author aaron
 * \date   May 2023
 *********************************************************************/

/******************************
*          DEFINES            *
*******************************/
#define TREE_CONE_NUM_SLICES 20
#define TREE_CONE_NUM_STACKS 20

#define TREE_SPHERE_NUM_SLICES 20
#define TREE_SPHERE_NUM_STACKS 20

#define TREE_BASE_RADIUS 0.5
#define TREE_BASE_HEIGHT 7.5
#define TREE_BASE_SPHERE_RADIUS 2.0

#define TREE_BRANCH1_RADIUS 0.2
#define TREE_BRANCH1_LENGTH 3.0
#define TREE_BRANCH1_TRANSLATION_X 0.0
#define TREE_BRANCH1_TRANSLATION_Y 0.0
#define TREE_BRANCH1_TRANSLATION_Z 3.0
#define TREE_BRANCH1_ROTATION_ANGLE 70.0
#define TREE_BRANCH1_ROTATION_VECTOR 0.0, 1.0, 0.0
#define TREE_BRANCH1_SPHERE_RADIUS 1.0
#define TREE_BRANCH1_SPHERE_TRANSLATION_X 0.0
#define TREE_BRANCH1_SPHERE_TRANSLATION_Y 2.5
#define TREE_BRANCH1_SPHERE_TRANSLATION_Z 4.0

#define TREE_BRANCH2_RADIUS 0.3
#define TREE_BRANCH2_LENGTH 3.5
#define TREE_BRANCH2_TRANSLATION_X 0.0
#define TREE_BRANCH2_TRANSLATION_Y 0.0
#define TREE_BRANCH2_TRANSLATION_Z 2.75
#define TREE_BRANCH2_ROTATION_ANGLE 55.0
#define TREE_BRANCH2_ROTATION_VECTOR -1.0, 0.0, 0.0
#define TREE_BRANCH2_SPHERE_RADIUS 1.5
#define TREE_BRANCH2_SPHERE_TRANSLATION_X 2.0
#define TREE_BRANCH2_SPHERE_TRANSLATION_Y 0.0
#define TREE_BRANCH2_SPHERE_TRANSLATION_Z 3.5

#define TREE_BRANCH3_RADIUS 0.35
#define TREE_BRANCH3_LENGTH 4
#define TREE_BRANCH3_TRANSLATION_X 0.0
#define TREE_BRANCH3_TRANSLATION_Y 0.0
#define TREE_BRANCH3_TRANSLATION_Z 3.25
#define TREE_BRANCH3_ROTATION_ANGLE 65.0
#define TREE_BRANCH3_ROTATION_VECTOR 1.0, -1.0, 0.0
#define TREE_BRANCH3_SPHERE_RADIUS 2.0
#define TREE_BRANCH3_SPHERE_TRANSLATION_X -2.0
#define TREE_BRANCH3_SPHERE_TRANSLATION_Y -2.0
#define TREE_BRANCH3_SPHERE_TRANSLATION_Z 4

/******************************
*    FORWARD DECLARATIONS     *
*******************************/
class WcPt3D;

/******************************
*     FUNCTION PROTOTYPES     *
*******************************/
void renderTree(WcPt3D center);
