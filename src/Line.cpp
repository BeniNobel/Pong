/***************************************
* iBeni
* File name: Line.cpp
* Description: This file contains the function definitions for the Line class.
*****************************************/

// Include directives
#include "Game.h"

// Setters functions

/**
  Sets the x-coordinate of the starting point of the line.
  @param x - x-coordinate of the starting point
*/
void Line::setStartPosX(float x) {
    startPosX = x;
}

/**
  Sets the y-coordinate of the starting point of the line.
  @param y - y-coordinate of the starting point
*/
void Line::setStartPosY(float y) {
    startPosY = y;
}

/**
  Sets the x-coordinate of the ending point of the line.
  @param x - x-coordinate of the ending point
*/
void Line::setEndPosX(float x) {
    endPosX = x;
}

/**
  Sets the y-coordinate of the ending point of the line.
  @param y - y-coordinate of the ending point
*/
void Line::setEndPosY(float y) {
    endPosY = y;
}

/**
  Sets the color of the line.
  @param clr - color of the line
*/
void Line::setColor(::Color clr) {
    color = clr;
}

// Getters functions

/**
  Returns the x-coordinate of the starting point of the line.
  @return x-coordinate of the starting point
*/
float Line::getStartPosX() const {
    return startPosX;
}

/**
  Returns the y-coordinate of the starting point of the line.
  @return y-coordinate of the starting point
*/
float Line::getStartPosY() const {
    return startPosY;
}

/**
  Returns the x-coordinate of the ending point of the line.

  @return x-coordinate of the ending point
*/
float Line::getEndPosX() const {
    return endPosX;
}

/**
  Returns the y-coordinate of the ending point of the line.
  @return y-coordinate of the ending point
*/
float Line::getEndPosY() const {
    return endPosY;
}

/**
  Returns the color of the line.
  @return color of the line
*/
::Color Line::getColor() const {
    return color;
}

/**
  Draws a line on the screen.
  @param startPosX - x-coordinate of the starting point
  @param startPosY - y-coordinate of the starting point
  @param endPosX - x-coordinate of the ending point
  @param endPosY - y-coordinate of the ending point
  @param color - color of the line
*/
void Line::drawLine() {
    DrawLine(startPosX, startPosY, endPosX, endPosY, color);
}