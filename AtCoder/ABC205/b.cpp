#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> b(n);
    iota(b.begin(), b.end(), 1);
    if (a == b)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}
