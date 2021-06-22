#include <bits/stdc++.h>

using namespace std;

int main()
{
    int v,t,s,d;
    cin >> v >> t >> s >> d;
    int a,b;
    a = v*t;
    b = v*s;
    if (d >= a && d <= b)
    {
        cout << "No";
    }
    else
    {
        cout << "Yes";
    }
}
