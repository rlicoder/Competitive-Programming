#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int a,b;
        cin >> a >> b;
        if (b > a)
        {
            swap(a,b);
        }
        if (a == 0)
        {
            cout << "YES" << endl;
            continue;
        }
        cout << ((a+b)%3==0 && ((float)a/(float)b) <= (float)2 ? "YES" : "NO") << endl;
    }

}
