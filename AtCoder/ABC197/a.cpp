#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    cin >> str;
    for (int i = 0; i < 3; i++)
    {
        cout << str[(1+i)%3];
    }
    cout << endl;
}
