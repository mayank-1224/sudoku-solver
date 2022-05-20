# sudoku-solver
This simple C++ application solves Sudoku puzzles.
It uses the concept of Backtracking and Bit Masks.

# Intuition:
The Sudoku can be solved by checking for the values one at a time at empty cells. Before every assignment, the value is checked whether or not the sudoku will be valid after putting in the value. This is done by checking if the value going to be assigned is present in the current row, column or the current 3x3 sub-matrix, according to the Sudokyu rules.
When the number is checked whether it is valid or not, it is assigned in it's proper place. If the number results in an invalid Sudoku, the next number is tried for that particular empty cell.
If none of the numbers from 1 to 9 result in a valid evaluation, then false is returned - meaning that the sudoku cannot be solved and has no valid solution.

# Algorithm
1. function that checks after assignment whether the grid becomes valid or not. This is achieved by maintaining a hashma for row, column and the 3x3 sub-grids.
2. Return false if any value has frequency greter than 1 else return true.
3. Recursive function that takes the grid
4. Check for empty locations.
5. Assign numbers 1 - 9.
6. Check whether assignment makes the grid valid or invalid.
7. if valid, call function for all valid values from 1 - 9. If any call returns true, return true overall and end loop.
8. If no recursive call return true, return false overall.
9. Finally, if no unassigned location is left, return true.

# Time complexity
O(9 ^ (n * n))

# Space Complexity
O(n ^ 2)
