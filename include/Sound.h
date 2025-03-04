/***************************************
* iBeni
* File name: Sound.h
* Description: This file contains the declaration of the Sound class
*****************************************/

// Include directives
#pragma once // Include guard to ensure this header file is only included once
#include <SFML/Audio.hpp>
#include <iostream>

class SoundManager {
public:
    // Constructor
    SoundManager();

    // Function to play the shoot sound
    void playHitSound();

    // Function to play the hit sound
    void playScoreSound();

private:
    sf::SoundBuffer hitBuffer;    // Sound buffer for hit sound
    sf::Sound hitSound;          // Sound object for hit sound
    sf::SoundBuffer scoreBuffer;  // Sound buffer for score sound
    sf::Sound scoreSound;        // Sound object for score sound
};
