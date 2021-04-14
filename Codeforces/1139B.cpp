#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    reverse(a.begin(), a.end());
    long long ans = a[0];
    long long prev = a[0];
    for (long long i = 1; i < n; i++)
    {
        long long add = min(a[i], prev-1);
        prev = add;
        ans += add;
        if (prev == 0)
        {
            break;
        }
    }
    cout << ans << endl;
}
