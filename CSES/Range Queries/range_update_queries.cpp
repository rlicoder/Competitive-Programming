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
    vector<long long> lazy(4*n, 0);
 
    function<long long(long long, long long, long long)> construct = [&] (long long curr, long long left, long long right)
    {
        if (left == right)
        {
            segtree[curr] = a[left];
            return segtree[curr];
        }
        long long mid = (left + right) / 2;
        segtree[curr] = construct(curr*2+1, left, mid) ^ construct(curr*2+2, mid+1, right);
        return segtree[curr];
    };
 
    
    function<long long(long long,long long,long long,long long,long long)> xorq = [&] (long long curr, long long left, long long right, long long ql, long long qr)
    {
        //if the current range needs to be updated
        if(lazy[curr] != 0)
        {
            //get the difference and range it represents and increment
            int dx = lazy[curr];
            lazy[curr] = 0;
            segtree[curr] += dx * (right - left + 1);
            //cout << "ranges " << left << " " << right << " are being added " << dx * (right-left + 1) << endl;
     
            //pass on the next updates to the children if not a leaf node
            if(left != right)
            {
                lazy[2*curr+1] += dx;
                lazy[2*curr+2] += dx;
            }
        }

        //range represented by node is completely inside the query range
        if(ql <= left && qr >= right)
        {
            return segtree[curr];
        }
        //range repsented by node is completely outside of the query range
        if(ql > right || qr < left)
        {
            return (long long)0;
        }
        //partial overlap, recursive calls to both children
        long long mid = (left + right) / 2;
        return xorq(curr*2+1, left, mid, ql, qr) + xorq(curr*2+2, mid+1, right, ql, qr);
    };
 
    function<void(long long, long long, long long, long long, long long, long long)> update = [&] (long long ql, long long qr, long long curr, long long val, long long left, long long right)
    {
        if(lazy[curr] != 0)
        {
            int dx = lazy[curr];
            lazy[curr] = 0;
            segtree[curr] += dx * (right - left + 1);
     
            if(left != right)
            {
                lazy[2*curr+1] += dx;
                lazy[2*curr+2] += dx;
            }
        }

        if (ql > right || qr < left)
        {
            return;
        }
        if (ql <= left && qr >= right)
        {
            int dx = (right - left + 1) * val;
            segtree[curr] += dx;

            if (left != right)
            {
                lazy[2*curr+1] = dx;
                lazy[2*curr+2] = dx;
            }
            return;
        }

        long long mid = (left + right) / 2;
        update(ql, qr, curr*2+1, val, left, mid) ;
        update(ql, qr, curr*2+2, val, mid+1, right);
        segtree[curr] = segtree[2*curr+1] + segtree[2*curr+2];
    };
 
    construct(0,0,n-1);

        
    for (long long i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int a,b,u;
            cin >> a >> b >> u;
            a--;b--;
            update(a,b,0,u,0,n-1);
        }
        else
        {
            int k;
            cin >> k;
            k--;
            cout << xorq(0,0,n-1,k,k) << endl;
        }
        for (int i = 7; i <= 14; i++)
        {
            cout << segtree[i] << " ";
        }
        cout << endl;
    }
}

 

