#include <bits/stdc++.h>

using namespace std;

const long long MAXN = 2e5;

vector<long long> ft(MAXN, 0);

void add(long long i, long long cnt)
{
    while (i < MAXN)
    {
        ft[i] += cnt;
        i += i&(-i);
    }
};

long long rsq(long long a)
{
    long long sum = 0;
    while (a != 0)
    {
        sum += ft[a];
        a -= a&(-a);
    }
    return sum;
};

long long rsq(long long a, long long b)
{
    return rsq(b) - rsq((a == 1 ? 0 : a-1));
};

long long findbyk(long long i)
{
    long long l = 1;
    long long r = MAXN;
    long long ans = 0;
    while (l <= r)
    {
        long long mid = l + (r-l) / 2;
        if (rsq(mid) >= i)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
};


int main()
{
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (long long i = 0; i < k; i++)
    {
        add(a[i], 1);
    }
    long long l = 0;
    long long r = k;
    long long m = (k % 2 == 0) ? k/2-1 : k/2;
    while (r != n)
    {
        cout << findbyk(m+1) << " ";
        add(a[l++], -1);
        add(a[r++], 1);
    }
    cout << findbyk(m+1);
    cout << endl;
}
