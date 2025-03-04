/***************************************
* iBeni
* File name: GameFunctions.cpp
* Description: This file contains game functions
*****************************************/

// Include the game header file which contains necessary declarations and definitions
#include "Game.h"

/**
  Clamps a given value between a specified minimum and maximum.
  @param value - the value to be clamped
  @param min - the minimum value allowed
  @param max - the maximum value allowed
  @return the clamped value
*/
float clamp(float value, float min, float max) {
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

/**
  Checks collision between a circle and a rectangle.
  @param ballX - x-coordinate of the circle center
  @param ballY - y-coordinate of the circle center
  @param ballRadius - radius of the circle
  @param rectX - x-coordinate of the rectangle
  @param rectY - y-coordinate of the rectangle
  @param rectWidth - width of the rectangle
  @param rectHeight - height of the rectangle
  @return true if there is a collision, false otherwise
*/
bool CheckCollisionCircleRectangle(float ballX, float ballY, float ballRadius, float rectX, float rectY, float rectWidth, float rectHeight) {
    float closestX = clamp(ballX, rectX, rectX + rectWidth);
    float closestY = clamp(ballY, rectY, rectY + rectHeight);

    float distanceX = ballX - closestX;
    float distanceY = ballY - closestY;

    return (distanceX * distanceX + distanceY * distanceY) < (ballRadius * ballRadius);
}