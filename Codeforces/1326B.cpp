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
    int curr = 0;
    for (int i = 0; i < n; i++)
    {
        int x = curr + a[i];
        cout << x << " ";
        curr = max(x,curr);
    }
    cout << endl;
}
