#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    set<int> s;
    for (int i = 0; i < 10000; i++)
    {
        s.insert(b + i*a);
    }
    for (int i = 0; i < 10000; i++)
    {
        if (s.count(d + i*c))
        {
            cout << d + i*c << endl;
            exit(0);
        }
    }
    cout << -1 << endl;
}
