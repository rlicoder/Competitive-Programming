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
    sort(a.begin(), a.end());
    long long sum = 0;
    for (long long i = 0; i < n; i++)
    {
        if (a[i] > sum + 1)
        {
            break;
        }
        sum += a[i];
    }
    cout << sum + 1 << endl;
}
