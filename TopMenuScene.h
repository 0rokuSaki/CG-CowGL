#pragma once
/*****************************************************************//**
 * \file   TopMenuScene.h
 * \brief  
 * 
 * \author aaron
 * \date   May 2023
 *********************************************************************/

/******************************
*          INCLUDES           *
*******************************/
#include <GL/glut.h>
#include "Button.h"

/******************************
*          DEFINES            *
*******************************/
#define FRAME_WIDTH 3
#define BTN_HEIGHT 30
#define EXIT_BTN_WIDTH  45
#define HELP_BTN_WIDTH 50
#define ADJ_AMB_LIGHT_BTN_WIDTH 165

/******************************
*      EXTERNAL VARIABLES     *
*******************************/
extern Button exitBtn;
extern Button helpBtn;
extern Button adjAmbLightBtn;

/******************************
*     FUNCTION PROTOTYPES     *
*******************************/
void renderTopMenuScene(void);
