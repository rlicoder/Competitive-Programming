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
    int l = 0;
    int r = n-1;
    while (l <= r)
    {
        cout << a[l] << " ";
        if (l >= r)
        {
            break;
        }
        cout << a[r] << " ";
        l++;r--;
    }
}
