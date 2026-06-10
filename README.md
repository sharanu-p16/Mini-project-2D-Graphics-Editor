# 2D Text Graphics Editor

## About
A simple, terminal-based graphics editor written in C. It uses a 2D array of characters to store and display pictures. Shapes are drawn using asterisks (`*`) and empty space is filled with underscores (`_`).

## Features
* **Draw Shapes:** Supports drawing Lines, Rectangles, Triangles, and Circles.
* **Manage Objects:** Add, modify, or delete shapes from the picture.
* **Shape Memory:** Deletes shapes instantly using a unique ID number rather than re-entering coordinates.
* **Live Display:** Clears and re-renders the updated picture directly in the terminal.

## How to Run

**1. Compile the code:**
`gcc main.c -o editor`

**2. Run the program:**
* **Windows:** `./editor.exe`
* **Mac/Linux:** `./editor`

## Usage
Simply run the program and use the number keys to navigate the on-screen menu. Follow the prompts to enter coordinates (X, Y) and dimensions to draw your shapes onto the canvas!