# Pong

**Pong** is a simple 2D game developed in **C++** using the **Raylib** library. Inspired by the classic arcade game, Pong features player-controlled and AI-controlled paddles, a bouncing ball, and a scoring system. This project blends nostalgia with modern C++ programming concepts, making it an ideal practice for game development fundamentals.

---

## Table of Contents

- [Features](#features)
- [Technologies Used](#technologies-used)
- [Build and Run](#build-and-run)

---

## Features

- Player-controlled paddle with keyboard input.
- AI-controlled paddle with basic tracking behavior.
- Ball movement with realistic bouncing physics.
- Collision detection between ball and paddles.
- Scoring system to track player and AI points.
- Colorful graphics using **Raylib**.
- Sound effects integrated using **SFML**.
- Cross-platform compatibility.

---

## Technologies Used

### Language:
- **C++**

### Library:
- **Raylib** (Graphics & Input)
- **SFML** (Audio Effects)

---

## Build and Run

### Prerequisites
- **C++ Compiler**
- **Raylib Library**
- **SFML Library**

### Installation

Clone this repository:

```bash
git clone https://github.com/BeniNobel/Pong.git
cd Pong
```

Compile the game:

```bash
g++ *.cpp -o Pong -lraylib -lsfml-audio
```

Run the game:

```bash
./Pong
```