/***************************************
* iBeni
* File name: Game.h
* Description: This file contains the function prototypes and includes necessary libraries.
*****************************************/

// Include directives
#pragma once

// Standard library includes
#include <iostream>
#include <string>

// SFML includes - specific components to avoid conflicts
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Clock.hpp>

// Game specific includes
#include "raylib.h"
#include "Ball.h"
#include "Paddle.h"
#include "Line.h"
#include "Scores.h"

// Set up window dimensions and title
const int screen_width = 1280;   // Width of the game window
const int screen_height = 800;   // Height of the game window
extern const char* gameTitle;  // Title of the game window

// Game colors using Raylib's Color type
extern ::Color Dark_Navy_blue;
extern ::Color Light_Blue;
extern ::Color Orange;
extern ::Color Gray;
extern ::Color Light_Gray;
extern ::Color Lavender;

// Declare function prototypes for functions defined in other source files
float clamp(float value, float min, float max); // Clamps a value between a minimum and maximum value
bool CheckCollisionCircleRectangle(float ballX, float ballY, float ballRadius, float rectX, float rectY, float rectWidth, float rectHeight); // Checks for collision between a circle and a rectangle

// Game functions
void InitGame();
void UpdateGame();
void DrawGame();
void CloseGame();
