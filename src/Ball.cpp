/***************************************
* iBeni
* File name: Ball.cpp
* Description: This file contains the function definitions for the Ball class.
*****************************************/

// Include directives
#include "Game.h"
#include "Ball.h"

Ball::Ball(float x, float y, float radius, float speedX, float speedY, ::Color color, SoundManager& soundManager) 
    : x(x), y(y), radius(radius), speedX(speedX), speedY(speedY), color(color), isMoving(false), soundManager(soundManager) {
}

/**
  Draws the ball on the screen.
*/
void Ball::draw() const {
    DrawCircle(x, y, radius, color);
}

/**
  Updates the ball's position based on its speed, checks for collisions with screen boundaries, updates scores, and resets the ball.
*/
void Ball::update() {
    if (!isMoving) return;

    x += speedX;
    y += speedY;

    // Check for collision with top and bottom walls
    if (y + radius >= GetScreenHeight() || y - radius <= 0) {
        speedY *= -1;
    }

    // Check for collision with right wall (AI scores)
    if (x + radius >= GetScreenWidth()) {
        ai_score++;
        soundManager.playScoreSound();  // Play score sound
        reset();
    }

    // Check for collision with left wall (Player scores)
    if (x - radius <= 0) {
        player_score++;
        soundManager.playScoreSound();  // Play score sound
        reset();
    }
}

/**
  Resets the ball's position to the center of the screen and randomizes its speed direction.
*/
void Ball::reset() {
    x = GetScreenWidth() / 2.0f;
    y = GetScreenHeight() / 2.0f;
    
    // Randomize the initial direction
    speedX = (GetRandomValue(0, 1) == 0) ? -7.0f : 7.0f;
    speedY = (GetRandomValue(0, 1) == 0) ? -7.0f : 7.0f;
}

// Setter functions

/**
  Function to set the x-coordinate of the ball
*/
void Ball::setBallPosition(float newX, float newY) {
    x = newX;
    y = newY;
}

/**
  Function to set the speed of the ball in the x direction
*/
void Ball::setBallSpeed(float newSpeedX, float newSpeedY) {
    speedX = newSpeedX;
    speedY = newSpeedY;
}

/**
  Function to set the color of the ball
*/
void Ball::setBallColor(::Color newColor) {
    color = newColor;
}

void Ball::setIsMoving(bool moving) {
    isMoving = moving;
}

// Getter functions

/**
  Function to get the x-coordinate of the ball
*/
float Ball::getBallX() const {
    return x;
}

/**
  Function to get the y-coordinate of the ball
*/
float Ball::getBallY() const {
    return y;
}

/**
  Function to get the radius of the ball
*/
float Ball::getBallRadius() const {
    return radius;
}

/**
  Function to get the speed of the ball in the x direction
*/
float Ball::getBallSpeedX() const {
    return speedX;
}

/**
  Function to get the speed of the ball in the y direction
*/
float Ball::getBallSpeedY() const {
    return speedY;
}

/**
  Function to get the color of the ball
*/
::Color Ball::getBallColor() const {
    return color;
}

bool Ball::getIsMoving() const {
    return isMoving;
}