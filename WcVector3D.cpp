#include "WcVector3D.h"
#include <cmath>

void WcVector3D::normalize()
{
    const GLdouble size = sqrt(_x * _x + _y * _y + _z * _z);
    _x = _x / size;
    _y = _y / size;
    _z = _z / size;
}
