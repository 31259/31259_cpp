#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;

void printTablica(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int cell : row)
            cout << (cell ? "X " : ". ");
        cout << endl;
    }
    cout << endl;
    this_thread::sleep_for(chrono::milliseconds(50));
}

bool BezpDama(const vector<vector<int>>& board, int row, int col, int N) {
    for (int i = 0; i < col; i++)
        if (board[row][i]) return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;
    for (int i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j]) return false;
    return true;
}

bool BezpWierz(const vector<vector<int>>& board, int row, int col, int N) {
    for (int i = 0; i < col; i++)
        if (board[row][i]) return false;
    for (int i = 0; i < row; i++)
        if (board[i][col]) return false;
    return true;
}

bool solve(vector<vector<int>>& board, int col, int N, int count, bool isQueen) {
    if (count == 0) return true;
    if (col >= N) return false;

    for (int i = 0; i < N; i++) {
        if ((isQueen && BezpDama(board, i, col, N)) ||
            (!isQueen && BezpWierz(board, i, col, N))) {
            board[i][col] = 1;
            printTablica(board);
            if (solve(board, col + 1, N, count - 1, isQueen))
                return true;
            board[i][col] = 0;
        }
    }
    return solve(board, col + 1, N, count, isQueen);
}

int main() {
    int N, count;
    char fig;

    cout << "Wybierz fig (Q - hetman, R - wieza): ";
    cin >> fig;
    bool isQueen = (fig == 'Q' || fig == 'q');

    cout << "Podaj rozmiar szachownicy (N): ";
    cin >> N;

    cout << "Podaj liczbe figur do umieszczenia: ";
    cin >> count;

    vector<vector<int>> board(N, vector<int>(N, 0));

    auto start = high_resolution_clock::now();
    bool rezultat = solve(board, 0, N, count, isQueen);
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(end - start);
    cout << "\nCzas wykonania: " << duration.count() << " ms" << endl;

    if (rezultat) {
        cout << "Rozwiazanie znalezione:\n";
        printTablica(board);
    }
    else {
        cout << "Brak rozwiazania\n";
    }

    return 0;
}
