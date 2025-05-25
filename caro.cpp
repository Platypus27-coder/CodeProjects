#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 15;
vector<vector<char>> board(SIZE, vector<char>(SIZE, '.'));

void printBoard() {
    cout << "   ";
    for (int i = 0; i < SIZE; ++i) cout << (i < 10 ? " " : "") << i << " ";
    cout << endl;
    for (int i = 0; i < SIZE; ++i) {
        cout << (i < 10 ? " " : "") << i << " ";
        for (int j = 0; j < SIZE; ++j) {
            cout << " " << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isWin(int row, int col, char player) {
    int dx[] = {1, 0, 1, 1};
    int dy[] = {0, 1, 1, -1};

    for (int dir = 0; dir < 4; ++dir) {
        int count = 1;
        for (int step = 1; step < 5; ++step) {
            int nx = row + dx[dir] * step;
            int ny = col + dy[dir] * step;
            if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE && board[nx][ny] == player) {
                ++count;
            } else break;
        }
        for (int step = 1; step < 5; ++step) {
            int nx = row - dx[dir] * step;
            int ny = col - dy[dir] * step;
            if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE && board[nx][ny] == player) {
                ++count;
            } else break;
        }
        if (count >= 5) return true;
    }
    return false;
}

bool isFull() {
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            if (board[i][j] == '.') return false;
    return true;
}

int main() {
    char currentPlayer = 'X';
    int row, col;
    printBoard();

    while (true) {
        cout << "Player " << currentPlayer << ", enter your move (row col): ";
        cin >> row >> col;
        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != '.') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }
        board[row][col] = currentPlayer;
        printBoard();

        if (isWin(row, col, currentPlayer)) {
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }
        if (isFull()) {
            cout << "Draw! The board is full." << endl;
            break;
        }
        currentPlayer = (currentPlayer == 'X' ? 'O' : 'X');
    }
    return 0;
}
