#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        long long n, m, x;
        cin >> n >> m >> x;
        long long col = x / n;
        long long row = x % n;
        col++;
        if (row == 0)
        {
            row = n;
            col--;
        }
        cout << ((row-1) * m) + col << endl;
    }
}
