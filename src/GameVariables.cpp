/***************************************
* iBeni
* File name: GameVariables.cpp
* Description: This file contains global variables used in the game.
*****************************************/

#include "Game.h"
#include "Scores.h"

// Define the game title
const char* gameTitle = "Pong";

// Define game colors
::Color Dark_Navy_blue = ::Color{ 0, 0, 25, 255 };
::Color Light_Blue = ::Color{ 173, 216, 230, 255 };
::Color Orange = ::Color{ 255, 165, 0, 255 };
::Color Gray = ::Color{ 169, 169, 169, 255 };
::Color Light_Gray = ::Color{ 192, 192, 192, 255 };
::Color Lavender = ::Color{ 200, 160, 255, 255 };

// Define score variables
int player_score = 0;
int ai_score = 0;