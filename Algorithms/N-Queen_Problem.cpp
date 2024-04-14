#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> board;
int n,way=1;

bool is_safe(vector<vector<int>> &board, int x, int y)
{
    // diagonal
    for (int i = ++x, j = ++y; i < n and j < n; i++, j++)
    {
        if (board[i][j] == 1)
            return false;
    }
    for (int i = --x, j = --y; i >= 0 and j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
            return false;
    }
    for (int i = ++x, j = --y; i < n and j >= 0; i++, j--)
    {
        if (board[i][j] == 1)
            return false;
    }
    for (int i = --x, j = ++y; i >= 0 and j < n; i--, j++)
    {
        if (board[i][j] == 1)
            return false;
    }
    for(int i=x,j=y+1;j<n;j++){
        if (board[i][j] == 1)
            return false;
    }
    for(int i=x,j=y-1;j>=0;j--){
        if (board[i][j] == 1)
            return false;
    }
    for(int i=x+1,j=y;i<n;i++){
        if (board[i][j] == 1)
            return false;
    }
    for(int i=x-1,j=y;i>=0;i--){
        if (board[i][j] == 1)
            return false;
    }
    return true;
}

void n_queen(vector<vector<int>> &board, int col)
{
    if (col == n)
    {
        //display
        cout<<way++<<"th number solution:\n";
        for (int i = 0; i < n; i++)
        {
            for (auto a : board[i])
            {
                cout << a << " ";
            }
            cout << endl;
        }
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (is_safe(board, row, col))
        {
            board[row][col] = 1;
            n_queen(board,col+1);
            board[row][col] = 0;
        }
    }
}

int main()
{
    cin >> n;
    board.assign(n, vector<int>(n, 0));
    n_queen(board, 0);
}