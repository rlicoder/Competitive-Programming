#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n <= 10 || n >=22)
    {
        cout << 0;
    }
    if (n >= 11 && n <= 19)
    {
        cout << 4 << endl;
    }
    if (n == 20)
    {
        cout << 15 << endl;
    }
    if (n == 21)
    {
        cout << 4 << endl;
    }
}

