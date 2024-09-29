#include <iostream>
using namespace std;

const int MAX_N = 20;

int board[MAX_N][MAX_N];

void printBoard(int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 1)
                cout << " Q ";
            else
                cout << " . ";
        }
        cout << endl;
    }
}

bool isSafe(int row, int col, int N)
{
    for (int i = 0; i < row; i++)
        if (board[i][col] == 1)
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;

    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j] == 1)
            return false;

    return true;
}

bool solveNQueens(int row, int N)
{
    if (row >= N)
        return true;

    for (int col = 0; col < N; col++)
    {
        if (isSafe(row, col, N))
        {
            board[row][col] = 1;

            if (solveNQueens(row + 1, N))
                return true;

            board[row][col] = 0;
        }
    }

    return false;
}

int main()
{
    int N;
    cout << "Enter the number of queens: ";
    cin >> N;

    if(N > MAX_N){
        cout<<"Too many Queens";
        return 0;
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            board[i][j] = 0;
        }
    }

    if (!solveNQueens(0, N))
    {
        cout << "Solution does not exist." << endl;
    }
    else
    {
        printBoard(N);
    }

    return 0;
}