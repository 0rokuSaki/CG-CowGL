#include <GL/glut.h>

#include "Cow.h"
#include "RGBColor.h"


Cow::Cow() : _pos(0.0, 0.0, 0.0)
{
}

Cow::Cow(WcPt3D pos) : _pos(pos)
{
}

void Cow::render() const
{
    renderBody();
    renderLegs();
    renderUtter();
}

void Cow::moveForward()
{
}

void Cow::moveBackward()
{
}

void Cow::turnLeft()
{
}

void Cow::turnRight()
{
}

void Cow::moveHeadUp()
{
}

void Cow::moveHeadDown()
{
}

void Cow::moveHeadLeft()
{
}

void Cow::moveHeadRight()
{
}

void Cow::moveTailUp()
{
}

void Cow::moveTailDown()
{
}

void Cow::moveTailLeft()
{
}

void Cow::moveTailRight()
{
}

void Cow::renderBody() const
{
    /* Cow body parameters */
    static const RGBColor COW_BODY_COLOR(RGB_COLOR_DARK_TAN);
    static const WcPt3D COW_BODY_TRANSLATION(0.0, 0.0, 1.0);
    static const GLdouble COW_BODY_ROTATION[4] = { 90.0, 1.0, 0.0, 0.0 };  // angle, rotation vector (x, y, z)
    static const GLdouble COW_BODY_WIDTH = 0.5;
    static const GLdouble COW_BODY_LENGTH = 1.5;
    static const GLint COW_BODY_NUM_SLICES = 25;
    static const GLint COW_BODY_NUM_STACKS = 25;
    static const GLint COW_BODY_NUM_LOOPS = 25;

    glMatrixMode(GL_MODELVIEW);

    /* Draw main body using cylinders and disks */
    glPushMatrix();

    glColor3d(COW_BODY_COLOR.getR(), COW_BODY_COLOR.getG(), COW_BODY_COLOR.getB());
    glTranslated(_pos.getX() + COW_BODY_TRANSLATION.getX(), _pos.getY() + COW_BODY_TRANSLATION.getY(), _pos.getZ() + COW_BODY_TRANSLATION.getZ());
    glRotated(COW_BODY_ROTATION[0], COW_BODY_ROTATION[1], COW_BODY_ROTATION[2], COW_BODY_ROTATION[3]);

    GLUquadric* cylinder = gluNewQuadric();
    GLUquadric* disk = gluNewQuadric();

    gluCylinder(cylinder, COW_BODY_WIDTH, COW_BODY_WIDTH, COW_BODY_LENGTH, COW_BODY_NUM_SLICES, COW_BODY_NUM_STACKS);
    gluDisk(disk, 0.0, COW_BODY_WIDTH, COW_BODY_NUM_SLICES, COW_BODY_NUM_LOOPS);
    glTranslated(0.0, 0.0, COW_BODY_LENGTH);
    gluCylinder(cylinder, COW_BODY_WIDTH, 0.1, 0.25, 20, 20);
    //gluDisk(disk, 0.0, COW_BODY_WIDTH, COW_BODY_NUM_SLICES, COW_BODY_NUM_LOOPS);

    gluDeleteQuadric(cylinder);
    gluDeleteQuadric(disk);

    glPopMatrix();
}

void Cow::renderUtter() const
{
    /* Cow utter parameters */
    static const RGBColor COW_UDDER_COLOR(RGB_COLOR_PINK);
    static const WcPt3D COW_UDDER_TRANSLATION(0.0, -0.50, 0.5);
    static const GLdouble COW_UDDER_RADIOUS = 0.3;
    static const GLint COW_UDDER_NUM_SLICES = 15;
    static const GLint COW_UDDER_NUM_STACKS = 15;

    glMatrixMode(GL_MODELVIEW);

    /* Draw udder using a sphere */
    glPushMatrix();

    glColor3d(COW_UDDER_COLOR.getR(), COW_UDDER_COLOR.getG(), COW_UDDER_COLOR.getB());
    glTranslated(_pos.getX() + COW_UDDER_TRANSLATION.getX(), _pos.getY() + COW_UDDER_TRANSLATION.getY(), _pos.getZ() + COW_UDDER_TRANSLATION.getZ());
    glutSolidSphere(COW_UDDER_RADIOUS, COW_UDDER_NUM_SLICES, COW_UDDER_NUM_STACKS);

    glPopMatrix();
}

void Cow::renderLegs() const
{
    /* Cow legs and hooves parameters */
    static const RGBColor COW_LEG_COLOR(RGB_COLOR_DARK_TAN);
    static const RGBColor COW_HOOVE_COLOR(RGB_COLOR_DARK_GRAY);
    static const WcPt3D COW_LEG1_TRANSLATION(0.4, -0.1, 0.0);  // back right
    static const WcPt3D COW_LEG2_TRANSLATION(-0.4, -0.1, 0.0);  // back left
    static const WcPt3D COW_LEG3_TRANSLATION(0.4, -1.3, 0.0);  // front right
    static const WcPt3D COW_LEG4_TRANSLATION(-0.4, -1.3, 0.0);  // front left
    static const GLdouble COW_HOOVE_WIDTH = 0.11;
    static const GLdouble COW_LEG_WIDTH = 0.1;
    static const GLdouble COW_LEG_LENGTH = 1.1;
    static const GLdouble COW_HOOVE_LENGTH = 0.15;
    static const GLint COW_LEG_NUM_SLICES = 10;
    static const GLint COW_LEG_NUM_STACKS = 20;
    static const GLint COW_HOOVE_NUM_SLICES = 10;
    static const GLint COW_HOOVE_NUM_STACKS = 5;

    glMatrixMode(GL_MODELVIEW);

    /* Render legs using cylinders */
    glPushMatrix();

    GLUquadric* cylinder = gluNewQuadric();

    /* Legs */
    glColor3d(COW_LEG_COLOR.getR(), COW_LEG_COLOR.getG(), COW_LEG_COLOR.getB());

    glTranslated(_pos.getX() + COW_LEG1_TRANSLATION.getX(), _pos.getY() + COW_LEG1_TRANSLATION.getY(), _pos.getZ() + COW_LEG1_TRANSLATION.getZ());
    gluCylinder(cylinder, COW_LEG_WIDTH, COW_LEG_WIDTH, COW_LEG_LENGTH, COW_LEG_NUM_SLICES, COW_LEG_NUM_STACKS);
    glTranslated(-(_pos.getX() + COW_LEG1_TRANSLATION.getX()), -(_pos.getY() + COW_LEG1_TRANSLATION.getY()), -(_pos.getZ() + COW_LEG1_TRANSLATION.getZ()));

    glTranslated(_pos.getX() + COW_LEG2_TRANSLATION.getX(), _pos.getY() + COW_LEG2_TRANSLATION.getY(), _pos.getZ() + COW_LEG2_TRANSLATION.getZ());
    gluCylinder(cylinder, COW_LEG_WIDTH, COW_LEG_WIDTH, COW_LEG_LENGTH, COW_LEG_NUM_SLICES, COW_LEG_NUM_STACKS);
    glTranslated(-(_pos.getX() + COW_LEG2_TRANSLATION.getX()), -(_pos.getY() + COW_LEG2_TRANSLATION.getY()), -(_pos.getZ() + COW_LEG2_TRANSLATION.getZ()));

    glTranslated(_pos.getX() + COW_LEG3_TRANSLATION.getX(), _pos.getY() + COW_LEG3_TRANSLATION.getY(), _pos.getZ() + COW_LEG3_TRANSLATION.getZ());
    gluCylinder(cylinder, COW_LEG_WIDTH, COW_LEG_WIDTH, COW_LEG_LENGTH, COW_LEG_NUM_SLICES, COW_LEG_NUM_STACKS);
    glTranslated(-(_pos.getX() + COW_LEG3_TRANSLATION.getX()), -(_pos.getY() + COW_LEG3_TRANSLATION.getY()), -(_pos.getZ() + COW_LEG3_TRANSLATION.getZ()));

    glTranslated(_pos.getX() + COW_LEG4_TRANSLATION.getX(), _pos.getY() + COW_LEG4_TRANSLATION.getY(), _pos.getZ() + COW_LEG4_TRANSLATION.getZ());
    gluCylinder(cylinder, COW_LEG_WIDTH, COW_LEG_WIDTH, COW_LEG_LENGTH, COW_LEG_NUM_SLICES, COW_LEG_NUM_STACKS);
    glTranslated(-(_pos.getX() + COW_LEG4_TRANSLATION.getX()), -(_pos.getY() + COW_LEG4_TRANSLATION.getY()), -(_pos.getZ() + COW_LEG4_TRANSLATION.getZ()));

    /* Hooves */
    glColor3d(COW_HOOVE_COLOR.getR(), COW_HOOVE_COLOR.getG(), COW_HOOVE_COLOR.getB());

    glTranslated(_pos.getX() + COW_LEG1_TRANSLATION.getX(), _pos.getY() + COW_LEG1_TRANSLATION.getY(), _pos.getZ() + COW_LEG1_TRANSLATION.getZ());
    gluCylinder(cylinder, COW_HOOVE_WIDTH, COW_HOOVE_WIDTH, COW_HOOVE_LENGTH, COW_HOOVE_NUM_SLICES, COW_HOOVE_NUM_STACKS);
    glTranslated(-(_pos.getX() + COW_LEG1_TRANSLATION.getX()), -(_pos.getY() + COW_LEG1_TRANSLATION.getY()), -(_pos.getZ() + COW_LEG1_TRANSLATION.getZ()));

    glTranslated(_pos.getX() + COW_LEG2_TRANSLATION.getX(), _pos.getY() + COW_LEG2_TRANSLATION.getY(), _pos.getZ() + COW_LEG2_TRANSLATION.getZ());
    gluCylinder(cylinder, COW_HOOVE_WIDTH, COW_HOOVE_WIDTH, COW_HOOVE_LENGTH, COW_HOOVE_NUM_SLICES, COW_HOOVE_NUM_STACKS);
    glTranslated(-(_pos.getX() + COW_LEG2_TRANSLATION.getX()), -(_pos.getY() + COW_LEG2_TRANSLATION.getY()), -(_pos.getZ() + COW_LEG2_TRANSLATION.getZ()));

    glTranslated(_pos.getX() + COW_LEG3_TRANSLATION.getX(), _pos.getY() + COW_LEG3_TRANSLATION.getY(), _pos.getZ() + COW_LEG3_TRANSLATION.getZ());
    gluCylinder(cylinder, COW_HOOVE_WIDTH, COW_HOOVE_WIDTH, COW_HOOVE_LENGTH, COW_HOOVE_NUM_SLICES, COW_HOOVE_NUM_STACKS);
    glTranslated(-(_pos.getX() + COW_LEG3_TRANSLATION.getX()), -(_pos.getY() + COW_LEG3_TRANSLATION.getY()), -(_pos.getZ() + COW_LEG3_TRANSLATION.getZ()));

    glTranslated(_pos.getX() + COW_LEG4_TRANSLATION.getX(), _pos.getY() + COW_LEG4_TRANSLATION.getY(), _pos.getZ() + COW_LEG4_TRANSLATION.getZ());
    gluCylinder(cylinder, COW_HOOVE_WIDTH, COW_HOOVE_WIDTH, COW_HOOVE_LENGTH, COW_HOOVE_NUM_SLICES, COW_HOOVE_NUM_STACKS);
    glTranslated(-(_pos.getX() + COW_LEG4_TRANSLATION.getX()), -(_pos.getY() + COW_LEG4_TRANSLATION.getY()), -(_pos.getZ() + COW_LEG4_TRANSLATION.getZ()));

    gluDeleteQuadric(cylinder);

    glPopMatrix();
}
