#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long tc;
    cin >> tc;
    while (tc--)
    {
        long long n, k;
        cin >> n >> k;
        vector<long long> a(n);
        for (long long i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int hi = *max_element(a.begin(), a.end());
        int lo = *min_element(a.begin(), a.end());
        cout << hi  - lo << endl;


    }
}
