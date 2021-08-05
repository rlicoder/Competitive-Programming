#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<vector<char>> a(8, vector<char>(8));
    set<vector<vector<bool>>> solset;
    int count = 0;
    function<void(int,vector<vector<bool>>,set<int>,set<int>,set<int>,set<int>)> recur = [&] (int n, vector<vector<bool>> board, set<int> rows, set<int> cols, set<int> lr, set<int> rl)
    {
        if (solset.size() == 92)
        {
            return;
        }
        if (n == 0)
        {
            solset.insert(board);
        }
        for (int i = 0; i < 8; i++)
        {
            if (rows.count(i)) continue;
            for (int j = 0; j < 8; j++)
            {
                if (cols.count(j)) continue;
                if (board[i][j]) continue;
                if (lr.count(i-j)) continue;
                if (rl.count(j+i)) continue;
                board[i][j] = true;
                rows.insert(i);
                cols.insert(j);
                lr.insert(i-j);
                rl.insert(j+i);
                recur(n-1, board, rows, cols, lr, rl);
                board[i][j] = false;
                rows.erase(i);
                cols.erase(j);
                lr.erase(i-j);
                rl.erase(j+i);
            }
        }
    };
    vector<vector<bool>> board(8, vector<bool>(8, false));
    set<int> rows;
    set<int> cols;
    set<int> lr;
    set<int> rl;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            board[i][j] = true;
            rows.insert(i);
            cols.insert(j);
            lr.insert(i-j);
            rl.insert(j+i);
            recur(7, board, rows, cols, lr, rl);
            rl.erase(j+i);
            lr.erase(i-j);
            rows.erase(i);
            cols.erase(j);
            board[i][j] = false;
        }
    }
    cout << "vector<vector<vector<bool>>> a {";
    for (auto it : solset)
    {
        cout << "{";
        for (auto x : it)
        {
            cout << "{";
            for (auto y : x)
            {
                cout << y << ",";
            }
            cout << "},";
        }
        cout << "},";
    }
    cout << "}";
}
