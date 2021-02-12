#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string str = "";
        getline(cin, str);
        if (str.substr(0, 10) == "Simon says")
        {
            string s = str.substr(10, str.size()-10);
            cout << s << endl;
        }
    }
}

