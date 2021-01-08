#include <bits/stdc++.h>

using namespace std;

int main()
{
    string x,y;
    cin >> x >> y;
    bool good = true;
    string z = "";
    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] < y[i])
        {
            //cout << x[i] << y[i] << endl;
            good = false;
            break;
        }
        else
        {
            z += y[i];
        }
    }
    if (good)
    {
        cout << z << endl;
    }
    else 
    {
        cout << -1 << endl;
    }
}
