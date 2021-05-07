#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    while (k--)
    {
        string str = to_string(n);
        sort(str.begin(), str.end());
        int a = stoi(str);
        reverse(str.begin(), str.end());
        int b = stoi(str);
        n = b-a;
    }
    cout << n;
}
