/***************************************
* iBeni
* File name: Ball.h
* Description: This file contains the declaration of the Ball class.
*****************************************/

// Header guard to prevent multiple inclusion
#pragma once

// Include necessary headers
#include <raylib.h>
#include "Sound.h"

// Forward declaration
class SoundManager;

// Class definition for the Ball
class Ball {
public:
    Ball(float x, float y, float radius, float speedX, float speedY, ::Color color, SoundManager& soundManager);
    void update();
    void draw() const;
    void reset();
    void setBallPosition(float x, float y);
    void setBallSpeed(float speedX, float speedY);
    void setBallColor(::Color color);
    void setIsMoving(bool moving);
    float getBallX() const;
    float getBallY() const;
    float getBallRadius() const;
    float getBallSpeedX() const;
    float getBallSpeedY() const;
    ::Color getBallColor() const;
    bool getIsMoving() const;

private:
    float x;
    float y;
    float radius;
    float speedX;
    float speedY;
    ::Color color;
    bool isMoving;
    SoundManager& soundManager;  // Reference to sound manager
};