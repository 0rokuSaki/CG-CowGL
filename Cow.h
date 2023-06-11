#pragma once
#include "SceneObject.h"
#include "WcPt3D.h"

class Cow : public SceneObject
{
public:
    Cow();
    Cow(WcPt3D pos);

    void render() const;

    void moveForward();
    void moveBackward();
    void turnLeft();
    void turnRight();

    void moveHeadUp();
    void moveHeadDown();
    void moveHeadLeft();
    void moveHeadRight();

    void moveTailUp();
    void moveTailDown();
    void moveTailLeft();
    void moveTailRight();

private:
    WcPt3D _pos;

    void renderBody() const;
    void renderUtter() const;
    void renderLegs() const;
};

