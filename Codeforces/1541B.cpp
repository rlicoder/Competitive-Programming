#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long tc;
    cin >> tc;
    while (tc--)
    {
        long long n;
        cin >> n;
        vector<pair<long long,long long>> a(n);
        for (long long i = 0; i < n; i++)
        {
            cin >> a[i].first;
            a[i].second = i+1;
        }
        sort(a.begin(), a.end());
        long long count = 0;
        for (long long i = 0; i < n; i++)
        {
            for (long long j = i+1; j < n; j++)
            {
                if (a[i].first * a[j].first > n + (n-1))
                {
                    break;
                }
                else
                {
                    if (a[i].second + a[j].second == a[i].first * a[j].first)
                    {
                        count++;
                    }
                }
            }
        }
        cout << count << endl;
    }
}
