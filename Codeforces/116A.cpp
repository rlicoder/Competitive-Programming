#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int count = 0;
    int high = 0;
    for (int i = 0; i < n; i++)
    {
        int a,b;
        cin >> a >> b;
        count -= a;
        count += b;
        high = max(high, count);
    }
    cout << high;
}

