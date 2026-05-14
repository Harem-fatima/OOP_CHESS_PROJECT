Here is a professional and engaging description for your GitHub repository. It highlights your role as a student at FAST-NUCES and showcases the technical depth of the project.

---

# ♟️ Graphical Chess Game in C++ (SFML)

## **Project Overview**

This project is a fully functional, two-player **Chess Game** developed as the final semester project for the **Object-Oriented Programming (OOP) Lab** at **National University of Computer & Emerging Sciences (FAST-NUCES)**. It demonstrates the practical application of core OOP principles such as inheritance, polymorphism, and composition within a C++ environment.

Unlike standard console-based projects, this version features a **Graphical User Interface (GUI)** built using the **SFML (Simple and Fast Multimedia Library)**, providing a polished and interactive user experience.

## **✨ Key Features**

* **Graphical Interface**: A complete 800x800 pixel game window with a checkered board and custom-rendered geometric pieces.
* **Full Move Validation**: Strict enforcement of official chess rules for all pieces (Pawns, Rooks, Knights, Bishops, Queens, and Kings).
* **Visual Move Assistance**: Real-time highlighting of selected pieces and translucent "path markers" showing all valid legal moves for the player.
* **Turn Management**: Automated turn-switching between White and Black teams with status updates displayed in the window title bar.
* **Capture Log**: A live console-based log that tracks and displays all captured pieces using ANSI color coding.
* **Win Condition**: Automatic detection of King capture to announce the winner and end the session.

## **🚀 Bonus & Advanced Tasks**

* **Interactive GUI (SFML)**: Successfully implemented the bonus task of moving beyond text-based output to a custom graphical window.
* **Audio System**: Integrated the `windows.h` library to provide auditory feedback (beeps) for moves, captures, and illegal actions.
* **Persistent Storage (Save/Load)**: Implemented file handling using `fstream` to allow players to save their progress (`Key S`) and resume later (`Key L`).
* **Robust Error Handling**: Used `try-catch` blocks and exception handling to manage out-of-range clicks and invalid logic, ensuring a crash-free experience.

## **🛠️ OOP Principles Applied**

1. **Encapsulation**: Protected member variables and public getter/setter methods for piece properties.
2. 
**Inheritance**: A hierarchical structure where all specific piece classes inherit from a base `Piece` class.


3. **Polymorphism**: Used `virtual` functions and dynamic binding to execute piece-specific move logic at runtime.
4. **Composition**: The `Board` class is composed of an $8\times8$ grid of `Piece` pointers, managing their lifecycle and interactions.

## **🎮 Controls**

* **Left Click**: Select a piece or choose a destination square.
* **S Key**: Save current game state.
* **L Key**: Load last saved game.
* **E Key**: Exit game.



**Course**: Object Oriented Programming Lab (CS-1004)

