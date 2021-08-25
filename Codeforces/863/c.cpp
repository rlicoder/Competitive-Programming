#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long k;
    int a, b;
    cin >> k >> a >> b;
    vector<vector<int>> al(4, vector<int>(4));
    vector<vector<int>> bo = al;
    function<bool(int,int)> alicewins = [&] (int alice, int bob)
    {
        if (alice == 3 && bob == 2 || alice == 2 && bob == 1 || alice == 1 && bob == 3)
        {
            return true;
        }
        return false;
    };
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            cin >> al[i][j];
        }
    }
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            cin >> bo[i][j];
        }
    }
    long long ap, bp;
    ap = bp = 0;
    if (k < 1e6)
    {
        for (int i = 0; i < k; i++)
        {
            if (alicewins(a,b))
            {
                ap++;
            }
            else if (!alicewins(a,b) && a != b)
            {
                bp++;
            }
            int oa = a;
            a = al[a][b];
            b = bo[oa][b];
        }
    }
    else
    {
        set<pair<int,int>> s;
        vector<array<int,3>> res;
        while (s.count({a,b}) == 0)
        {
            s.insert({a,b});
            if (alicewins(a,b))
            {
                ap++;
            }
            else if (!alicewins(a,b) && a != b)
            {
                bp++;
            }
            res.push_back({a,b,a == b ? -1 : alicewins(a,b)});
            int oa = a;
            a = al[a][b];
            b = bo[oa][b];
            k--;
        }
        reverse(res.begin(), res.end());
        int ca, cb;
        ca = cb = 0;
        if (alicewins(a,b))
        {
            ca++;
        }
        else if (a!=b && !alicewins(a,b))
        {
            cb++;
        }
        long long i;
        for (i = 0; true; i++)
        {
            if (a == res[i][0] && b == res[i][1])
            {
                break;
            }
            if (res[i][2] == 1)
            {
                ca++;
            }
            else if (res[i][2] == 0)
            {
                cb++;
            }
        }
        i += 1;
        long long mul = k / i;
        k %= (long long)i;
        ap += ca * mul;
        bp += cb * mul;
        for (int i = 0; i < k; i++)
        {
            if (alicewins(a,b))
            {
                ap++;
            }
            else if (!alicewins(a,b) && a != b)
            {
                bp++;
            }
            int oa = a;
            a = al[a][b];
            b = bo[oa][b];
        }

    }
    cout << ap << " " << bp << endl;

}

