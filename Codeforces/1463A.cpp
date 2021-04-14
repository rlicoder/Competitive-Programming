#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        if ((a+b+c)%9 == 0)
        {
            if ((a+b+c)/9 > min(min(a,b),c))
            {
                cout << "NO";
            }
            else
            {
                cout << "YES";
            }
        }
        else
        {
            cout << "NO";
        }
        cout << endl;
    }
}
