#include <bits/stdc++.h>

using namespace std;

int main()
{
    int total = 0;
    int n;
    cin >> n;
    int p;
    cin >> p;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (i % 2 == 1)
        {
            x--;
        }
        total += x;
    }
    if (total <= p)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    cout << endl;

}
