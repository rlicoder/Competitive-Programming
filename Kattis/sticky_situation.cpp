#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long high, low;
    high = low = 0;
    bool flag = false;
    for (int i = 2; i < n; i++)
    {
        if (a[i-1] + a[i-2] > a[i])
        {
            flag = true;
        }
    }
    cout << (flag ? "possible" : "impossible");
}
