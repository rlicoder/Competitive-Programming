#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int fuckyou;
        cin >> fuckyou;
        string str;
        cin >> str;
        string a = str;
        reverse(a.begin(), a.end());
        cout << (str == a ? "YES" : "NO") << endl;
    }
}
