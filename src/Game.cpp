/***************************************
* iBeni
* File name: Game.cpp
* Description: This file contains the main function
*****************************************/

// Include directives
#include "Game.h"
#include "Sound.h"

// Initialize sound manager
SoundManager soundManager;

// Initialize game objects
Ball gameBall(
    static_cast<float>(screen_width) / 2,   // x
    static_cast<float>(screen_height) / 2,  // y
    20.0f,                                  // radius
    7.0f,                                   // speedX
    7.0f,                                   // speedY
    ::Color{0, 121, 241, 255},             // color (BLUE)
    soundManager                            // sound manager reference
);

void InitGame() {
    // Initialize window
    InitWindow(screen_width, screen_height, gameTitle);
    SetTargetFPS(60);
}

void UpdateGame() {
    // Update ball position
    gameBall.update();
}

void DrawGame() {
    BeginDrawing();
    ClearBackground(Dark_Navy_blue);

    // Draw ball
    gameBall.draw();

    EndDrawing();
}

void CloseGame() {
    CloseWindow();
}

int main() {
    // Initialize Raylib window and set target FPS
    InitWindow(screen_width, screen_height, gameTitle);
    SetTargetFPS(60);

    // Declare player paddle
    Paddle player;
    player.setPaddleWidth(25);  // Width of the player's paddle
    player.setPaddleHeight(120);  // Height of the player's paddle
    player.setPaddleX(screen_width - (player.getPaddleWidth() + 10));  // Initial x-coordinate of the player's paddle
    player.setPaddleY(screen_height / 2 - player.getPaddleHeight() / 2);  // Initial y-coordinate of the player's paddle
    player.setPaddleSpeed(6);  // Speed of the player's paddle
    player.setSegment(0);  // Segment
    player.setRoundness(0.8);  // Roundness of the player's paddle
    player.setPaddleColor(Light_Blue);  // Color of the player's paddle

    // Declare Computer paddle
    AIPaddle paddleAI;
    paddleAI.setPaddleWidth(25);  // Width of the Computer's paddle
    paddleAI.setPaddleHeight(120);  // Height of the Computer's paddle
    paddleAI.setPaddleX(10);  // Initial x-coordinate of the Computer's paddle
    paddleAI.setPaddleY(screen_height / 2 - paddleAI.getPaddleHeight() / 2);  // Initial y-coordinate of the Computer's paddle
    paddleAI.setPaddleSpeed(6);  // Speed of the Computer's paddle
    paddleAI.setSegment(0);  // Segment
    paddleAI.setRoundness(0.8);  // Roundness of the Computer's paddle
    paddleAI.setPaddleColor(Light_Blue);  // Color of the Computer's paddle

    // Declare middle line
    Line middleLine;
    middleLine.setStartPosX(screen_width / 2);  // Start x-coordinate of the middle line
    middleLine.setStartPosY(0);  // Start y-coordinate of the middle line
    middleLine.setEndPosX(screen_width / 2);  // End x-coordinate of the middle line
    middleLine.setEndPosY(screen_height);  // End y-coordinate of the middle line
    middleLine.setColor(Gray);  // Color of the middle line

    // Game loop
    while (!WindowShouldClose()) {
        // Check for space key to start the game
        if (IsKeyPressed(KEY_SPACE) && !gameBall.getIsMoving()) {
            gameBall.setIsMoving(true);
        }

        BeginDrawing();

        // Update Ball position
        gameBall.update();

        // Update Player paddle position
        player.updatePaddle();

        // Update Computer paddle position
        paddleAI.updatePaddleAI(gameBall.getBallY());

        // Check for collisions with paddles and reflect ball if necessary
        if (CheckCollisionCircleRectangle(gameBall.getBallX(), gameBall.getBallY(), gameBall.getBallRadius(),
            player.getPaddleX(), player.getPaddleY(), player.getPaddleWidth(), player.getPaddleHeight()))
        {
            gameBall.setBallSpeed(-gameBall.getBallSpeedX(), gameBall.getBallSpeedY());
            soundManager.playHitSound();
        }

        if (CheckCollisionCircleRectangle(gameBall.getBallX(), gameBall.getBallY(), gameBall.getBallRadius(),
            paddleAI.getPaddleX(), paddleAI.getPaddleY(), paddleAI.getPaddleWidth(), paddleAI.getPaddleHeight()))
        {
            gameBall.setBallSpeed(-gameBall.getBallSpeedX(), gameBall.getBallSpeedY());
            soundManager.playHitSound();
        }

        // Clear Background
        ClearBackground(Dark_Navy_blue);

        // Draw a circle in the center
        DrawCircle(screen_width / 2, screen_height / 2, 150, Lavender);

        // Draw Ball
        gameBall.draw();

        // Draw Player paddle
        player.drawPaddle();

        // Draw Computer paddle
        paddleAI.drawPaddle();

        // Draw middle line
        middleLine.drawLine();

        // Draw Player_AI score
        DrawText(TextFormat("%i", static_cast<int>(ai_score)), screen_width / 4 - 20, 20, 80, Light_Gray);

        // Draw Player score
        DrawText(TextFormat("%i", static_cast<int>(player_score)), 3 * screen_width / 4 - 20, 20, 80, Light_Gray);

        // Draw start message if ball is not moving
        if (!gameBall.getIsMoving()) {
            const char* startText = "Press SPACE to start";
            int textWidth = MeasureText(startText, 40);
            DrawText(startText, screen_width/2 - textWidth/2, screen_height/2 + 100, 40, Light_Gray);
        }

        // End drawing
        EndDrawing();
    }

    // Close Raylib window
    CloseWindow();
    return 0;
}