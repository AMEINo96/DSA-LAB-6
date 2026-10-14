#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Checks if the next move is within board limits and unvisited
bool isValid(int x, int y, const vector<vector<int>>& board, int N) {
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}

// Recursive function to solve the Knight's Tour problem
bool solveKnightTour(int x, int y, int moveNumber, vector<vector<int>>& board, int dx[], int dy[], int N) {
    // Base case: All N^2 squares have been visited
    if (moveNumber == N * N) {
        return true;
    }

    // Explore candidate moves
    for (int k = 0; k < 8; k++) {
        int next_x = x + dx[k];
        int next_y = y + dy[k];

        if (isValid(next_x, next_y, board, N)) {
            // Mark the candidate square with the current move number
            board[next_x][next_y] = moveNumber;

            // Make a recursive call
            if (solveKnightTour(next_x, next_y, moveNumber + 1, board, dx, dy, N)) {
                return true; 
            }

            // Backtrack: If the recursive call fails, undo the move
            board[next_x][next_y] = -1;
        }
    }

    // Stop when a valid tour is not found from this path
    return false;
}

// Function to print the board neatly
void displayBoard(const vector<vector<int>>& board, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(3) << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int N, startX, startY;

    cout << "Enter the size of the board (N): ";
    cin >> N;

    cout << "Enter starting X position (0 to " << N - 1 << "): ";
    cin >> startX;
    
    cout << "Enter starting Y position (0 to " << N - 1 << "): ";
    cin >> startY;

    // Initialize an N x N board with -1 (unvisited)
    vector<vector<int>> board(N, vector<int>(N, -1));

    // Define the 8 possible knight moves (row and column offsets)
    int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    // Mark the starting square with move 0
    board[startX][startY] = 0;

    // Start backtracking search from move 1
    if (solveKnightTour(startX, startY, 1, board, dx, dy, N)) {
        cout << "\nValid Knight's Tour found:\n";
        displayBoard(board, N);
    } else {
        cout << "\nNo tour was found by the search." << endl;
    }

    return 0;
}