#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n,k;
    cin >> n >> k;
    vector<long long> a(n);
    for (long long i = 0 ; i < n; i++)
    {
        cin >> a[i];
    }
    function<bool(long long)> valid  = [&] (long long x)
    {
        unsigned long long ans = 0;
        for (long long i = 0; i < n; i++)
        {
            ans += x/a[i];
        }
        return ans >= k;
        
    };
    function<long long(long long,long long)> search = [&] (long long l, long long r)
    {
        long long ans = 0;
        while (l <= r)
        {
            long long mid = (l+r)/2;
            if (valid(mid))
            {
                ans = mid;
                r = mid -1;
            }
            else
            {
                l = mid+1;
            }
        }
        return ans;
    };
    cout << search(0,(long long)1e18) << endl;
}
