#include <iostream>
using namespace std;

// Check whether placing num at grid[row][col] is valid
bool isSafe(int grid[9][9], int row, int col, int num)
{
    // Check row
    for (int j = 0; j < 9; j++)
    {
        if (grid[row][j] == num)
            return false;
    }

    // Check column
    for (int i = 0; i < 9; i++)
    {
        if (grid[i][col] == num)
            return false;
    }

    // Check 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[startRow + i][startCol + j] == num)
                return false;
        }
    }

    return true;
}

// Backtracking function
bool solveSudoku(int grid[9][9])
{
    // Find an empty cell
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            if (grid[row][col] == 0)
            {
                // Try numbers 1 to 9
                for (int num = 1; num <= 9; num++)
                {
                    if (isSafe(grid, row, col, num))
                    {
                        // Place number
                        grid[row][col] = num;

                        // Recursively solve remaining Sudoku
                        if (solveSudoku(grid))
                            return true;

                        // If solution doesn't work, undo
                        grid[row][col] = 0;
                    }
                }

                // No number works
                return false;
            }
        }
    }

    // No empty cells -> Sudoku solved
    return true;
}

// Print Sudoku
void printGrid(int grid[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int grid[9][9] =
    {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},

        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},

        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (solveSudoku(grid))
    {
        cout << "Solved Sudoku:\n";
        printGrid(grid);
    }
    else
    {
        cout << "No solution exists.";
    }

    return 0;
}