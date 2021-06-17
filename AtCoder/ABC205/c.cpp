#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;

    if (c % 2 == 0)
    {
        if (abs(a) > abs(b))
        {
            cout << '>' << endl;
        }
        else if (abs(b) > abs(a))
        {
            cout << "<" << endl;
        }
        else
        {
            cout << "=" << endl;
        }
    }
    else
    {
        if (a > b)
        {
            cout << ">";
        }
        else if (b > a)
        {
            cout << "<";
        }
        else
        {
            cout << "=";
        }
    }
}
