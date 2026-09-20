# Sudoku Solver in C++

A simple and efficient **Sudoku Solver** implemented in C++ using the **Backtracking Algorithm**.

## 📌 Project Overview

This project solves a standard **9×9 Sudoku puzzle** by filling the empty cells with valid numbers.

The program uses **backtracking** to systematically try possible numbers and backtrack whenever a number violates the Sudoku rules.

## 🚀 Features

- Solves a standard 9×9 Sudoku puzzle
- Uses a recursive backtracking algorithm
- Checks row constraints
- Checks column constraints
- Checks 3×3 subgrid constraints
- Displays the solved Sudoku grid
- Simple and beginner-friendly C++ implementation

## 🧠 Algorithm

The program follows these steps:

1. Find an empty cell in the Sudoku grid.
2. Try numbers from `1` to `9`.
3. Check whether the number is valid in:
   - The current row
   - The current column
   - The current 3×3 subgrid
4. If the number is valid, place it in the cell.
5. Recursively solve the remaining puzzle.
6. If the current choice leads to no solution, remove the number and try another possibility.
7. Continue until the Sudoku is completely solved.

This technique is called **Backtracking**.

## 💻 Technologies Used

- **Language:** C++
- **Concepts:** 
  - Recursion
  - Backtracking
  - 2D Arrays
  - Functions
  - Conditional Statements
