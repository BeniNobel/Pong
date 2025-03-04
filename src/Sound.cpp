 /***************************************
* iBeni
* File name: Sound.cpp
* Description: This file contains the implementation of the SoundManager class
*****************************************/

// Include the game header file which contains necessary declarations and definitions
#include "Game.h"
#include "Sound.h"

// Constructor for the SoundManager class
SoundManager::SoundManager() 
    : hitBuffer(), scoreBuffer(), 
      hitSound(hitBuffer), scoreSound(scoreBuffer) {
    // Load sound buffers and set up sounds
    if (!hitBuffer.loadFromFile("assets/hit.mp3")) {
        // Handle error loading hit sound file
        std::cout << "Error loading hit sound file" << std::endl;
    }

    if (!scoreBuffer.loadFromFile("assets/score.mp3")) {
        // Handle error loading score sound file
        std::cout << "Error loading score sound file" << std::endl;
    }
}

// Function to play the shoot sound
void SoundManager::playHitSound() {
    hitSound.play();
}

// Function to play the hit sound
void SoundManager::playScoreSound() {
    scoreSound.play();
}
