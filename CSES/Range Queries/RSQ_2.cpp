#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n,m;
    cin >> n >> m;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<long long> segtree(4*n, 0);

    function<long long(long long,long long,long long)> construct = [&] (long long curr, long long left, long long right)
    {
        //leaf node
        if (left == right)
        {
            segtree[curr] = a[left];
            return a[left];
        }
        //contructing the left and right side of the node, then returning the value recursively
        long long mid = (left+right)/2;
        segtree[curr]  = construct(2*curr+1,left,mid) + construct(2*curr+2,mid+1,right);
        return segtree[curr];
    };
    
    function<long long(long long, long long,long long,long long,long long)> range = [&] (long long curr, long long left, long long right, long long orileft, long long oriright)
    {
        if(orileft <= left && oriright >= right)
        {
            return segtree[curr];
        }
        if(right < orileft || left > oriright)
        {
            return (long long)0;
        }
        long long mid = (left + right) / 2;
        return (range(2*curr+1, left, mid, orileft, oriright) + range(2*curr+2, mid+1, right, orileft, oriright));
    };


    function<void(long long,long long,long long,long long,long long)> update = [&] (long long curr, long long diff, long long left, long long right, long long pos)
    {
        if(left > pos || right < pos)
        {
            return;
        }

        segtree[curr] += diff;
        if (left != right)
        {
            long long mid = (left+right) / 2;
            update(2*curr+1, diff, left, mid, pos);
            update(2*curr+2, diff, mid+1, right, pos);
        }
    };

    construct(0,0,n-1);

    //cout << segtree[0] << endl;
    //cout << segtree[1] << "  " << segtree[2] << endl;
    //cout << segtree[3] << "  " << segtree[4] << "  " << segtree[5] << "  " << segtree[6] << endl;
    for (long long i = 0; i < m; i++)
    {
        long long x,y,z;
        cin >> x >> y >> z;
        if (x == 1)
        {
            long long dif = z - a[y-1];
            a[y-1] = z;
            update(0,dif,0,n-1,y-1);
        }
        else
        {
            cout << range (0,0,n-1,y-1,z-1) << endl;
        }
    }
}


