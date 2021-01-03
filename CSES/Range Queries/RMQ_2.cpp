#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<long long> segtree(4*n);

    function<long long(long long, long long, long long)> construct = [&] (long long curr, long long left, long long right)
    {
        if (left == right)
        {
            segtree[curr] = a[left];
            return segtree[curr];
        }
        long long mid = (left + right) / 2;
        segtree[curr] = min(construct(curr*2+1, left, mid), construct(curr*2+2, mid+1, right));
        return segtree[curr];
    };

    
    function<long long(long long,long long,long long,long long,long long)> minq = [&] (long long curr, long long left, long long right, long long ql, long long qr)
    {
        if(ql <= left && qr >= right)
        {
            return segtree[curr];
        }
        if(left > qr || right < ql)
        {
            return LLONG_MAX;
        }
        long long mid = (left + right) / 2;
        return min(minq(curr*2+1, left, mid, ql, qr),minq(curr*2+2, mid+1, right, ql, qr));
    };

    function<long long(long long, long long, long long, long long, long long)> update = [&] (long long pos, long long curr, long long val, long long left, long long right)
    {
        if (pos > right || pos < left)
        {
            return segtree[curr];
        }
        if (right == left)
        {
            segtree[curr] = val;
            return val;
        }
        long long mid = (left + right) / 2;
        segtree[curr] = min(update(pos, curr*2+1, val, left, mid), update(pos, curr*2+2, val, mid+1, right));
        return segtree[curr];
    };

    construct(0,0,n-1);
        
    for (long long i = 0; i < m; i++)
    {
        long long x,y,z;
        cin >> x >> y >> z;
        if (x == 1)
        {
            a[y-1] = z;
            update(y-1, 0, z, 0, n-1);
        }
        else
        {
            cout << minq(0,0,n-1,y-1,z-1) << endl;
        }
    }
}

