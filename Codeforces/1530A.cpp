#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string n;
        cin >> n;
        cout << *max_element(n.begin(), n.end()) << endl;
    }
}
