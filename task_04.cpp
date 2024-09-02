#include <iostream>
using namespace std;

bool validity(int grid[9][9], int row, int col, int num);
bool SolvingS(int grid[9][9]);
void display(int grid[9][9]);
void inputGrid(int grid[9][9]);

int main() {
    int grid[9][9];
    inputGrid(grid); // Input the Sudoku puzzle

    if (SolvingS(grid)) {
        cout<<endl;
        cout<<"SOLVED SUCCESSFULLY!"<<endl;
        display(grid); // Display the solved puzzle
    } else {
        cout << "No solution exists!";
    }

    return 0;
}

void inputGrid(int grid[9][9]) {
    cout << "Enter the Sudoku grid (use * for empty spaces): \n";
    char input;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> input;
            while (input == ' ' || input == '\n') {
                cin >> input;
            }
            if (input == '*') {
                grid[i][j] = 0; // Treat * as 0 for empty spaces
            } else if (input >= '1' && input <= '9') {
                grid[i][j] = input - '0'; 
            } else {
                cout << "Invalid input! Please enter digits 1-9 or '*'.\n";
                --j; 
            }
        }
    }
}

void display(int grid[9][9]) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

bool validity(int grid[9][9], int row, int col, int num) {
    for (int x = 0; x < 9; ++x) {
        if (grid[row][x] == num || grid[x][col] == num ||
            grid[3 * (row / 3) + x / 3][3 * (col / 3) + x % 3] == num) {
            return false;
        }
    }
    return true;
}

bool SolvingS(int grid[9][9]) {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            if (grid[row][col] == 0) {
                for (int num = 1; num <= 9; ++num) {
                    if (validity(grid, row, col, num)) {
                        grid[row][col] = num;
                        if (SolvingS(grid)) {
                            return true;
                        }
                        grid[row][col] = 0; // Backtrack
                    }
                }
                return false;
            }
        }
    }
    return true;
}
