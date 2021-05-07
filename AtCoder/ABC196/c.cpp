#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    for (int i = 1; i < 1e7; i++)
    {
        if (stol(to_string(i) + to_string(i)) > n)
        {
            cout << i-1 << endl;
            break;
        }
    }
}
