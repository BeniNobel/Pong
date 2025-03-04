/***************************************
* iBeni
* File name: Paddle.h
* Description: This file contains the declaration of the Paddle class.
*****************************************/

// include directives
#pragma once
#include "Game.h"
#include <raylib.h>

// Class definition for the Paddle
class Paddle {
protected:
    // Function declaration for limiting the paddle's vertical movement
    void limitPaddleRange();

public:
    // Getter functions

    // Function declaration for getting the paddle's width
    float getPaddleWidth() const;

    // Function declaration for getting the paddle's height
    float getPaddleHeight() const;

    // Function declaration for getting the paddle's x-coordinate
    float getPaddleX() const;

    // Function declaration for getting the paddle's y-coordinate
    float getPaddleY() const;

    // Function declaration for getting the paddle's speed
    int getPaddleSpeed() const;

    // Function declaration for getting the paddle's segment
    int getSegment() const;

    // Function declaration for getting the paddle's roundness
    float getRoundness() const;

    // Function declaration for getting the paddle's color
    ::Color getPaddleColor() const;

    // Setter functions

    // Function declaration for setting the paddle's width
    void setPaddleWidth(float width);

    // Function declaration for setting the paddle's height
    void setPaddleHeight(float height);

    // Function declaration for setting the paddle's x-coordinate
    void setPaddleX(float x);

    // Function declaration for setting the paddle's y-coordinate
    void setPaddleY(float y);

    // Function declaration for setting the paddle's speed
    void setPaddleSpeed(int speed);

    // Function declaration for setting the paddle's segment
    void setSegment(int segment);

    // Function declaration for setting the paddle's roundness
    void setRoundness(float roundness);

    // Function declaration for setting the paddle's color
    void setPaddleColor(::Color color);

    // Function declaration for drawing the paddle
    void drawPaddle();

    // Function declaration for updating the paddle's position
    void updatePaddle();

    // Function declaration for moving the paddle up
    friend class AIPaddle;

private:
    float paddle_width; // width of the paddle
    float paddle_height; // height of the paddle
    float paddle_x; // x-coordinate of the paddle
    float paddle_y; // y-coordinate of the paddle
    int paddle_speed; // speed of the paddle
    int segment; // segment of the paddle
    float roundness; // roundness of the paddle
    ::Color paddle_color; // color of the paddle
};

// Class definition for the AI-controlled Paddle, inheriting from the base Paddle class
class AIPaddle : public Paddle {
public:
    // Function declaration for updating the AI-controlled paddle based on the ball's position
    void updatePaddleAI(float ball_y);
};