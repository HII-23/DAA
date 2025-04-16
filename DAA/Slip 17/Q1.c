#include <stdio.h>

#include <stdbool.h>



#define N 4 // Number of queens



// Function to print the solution matrix

void printSolution(int board[N][N]) {

    for (int i = 0; i < N; i++) {

        for (int j = 0; j < N; j++)

            printf("%d ", board[i][j]);

        printf("\n");

    }

}



// Function to check if a queen can be placed on board[row][col]

bool isSafe(int board[N][N], int row, int col) {

    int i, j;



    // Check this row on the left side

    for (i = 0; i < col; i++)

        if (board[row][i])

            return false;



    // Check upper diagonal on left side

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)

        if (board[i][j])

            return false;



    // Check lower diagonal on left side

    for (i = row, j = col; j >= 0 && i < N; i++, j--)

        if (board[i][j])

            return false;



    return true;

}



// Recursive function to solve N Queens problem

bool solveNQUtil(int board[N][N], int col) {

    // Base case: If all queens are placed, return true

    if (col >= N)

        return true;



    // Consider this column and try placing this queen in all rows one by one

    for (int i = 0; i < N; i++) {

        // Check if the queen can be placed on board[i][col]

        if (isSafe(board, i, col)) {

            // Place this queen in board[i][col]

            board[i][col] = 1;



            // Recur to place rest of the queens

            if (solveNQUtil(board, col + 1))

                return true;



            // If placing queen in board[i][col] doesn't lead to a solution, then remove it

            board[i][col] = 0;

        }

    }



    // If the queen can't be placed in any row in this column, return false

    return false;

}



// Function to solve the N Queens problem

bool solveNQ() {

    int board[N][N] = {{0, 0, 0, 0},

                       {0, 0, 0, 0},

                       {0, 0, 0, 0},

                       {0, 0, 0, 0}};



    if (solveNQUtil(board, 0) == false) {

        printf("Solution does not exist\n");

        return false;

    }



    printSolution(board);

    return true;

}



int main() {

    solveNQ();

    return 0;

}