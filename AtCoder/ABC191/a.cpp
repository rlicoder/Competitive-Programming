#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n == 0)
    {
        n = 200;
    }
    if (n > 100)
    {
        string str = to_string(n);
        n = stoi(str.substr(str.size()-2, 2));
    }
    cout << 100 - n;
}
