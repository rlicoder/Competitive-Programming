#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    bool ok = false;
    for (int i = 0; i <= 500; i++)
    {
        if (n == i*(i+1)/2)
        {
            ok = true;
            break;
        }
    }
    if (ok)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}
