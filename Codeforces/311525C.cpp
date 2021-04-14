#include <bits/stdc++.h>

using namespace std;

int win(long long a, long long b)
{
    long long res = 0;
    if (a == 3 && b == 2 || a == 2 && b == 1 || a == 1 && b == 3)
    {
        res = 1;
    }
    else if (b == 3 && a == 2 || b == 2 && a == 1 || b == 1 && a == 3)
    {
        res = -1;
    }
    else
    {
        res = 0;
    }
    return res;
}

int main()
{
    long long k,a,b;
    cin >> k >> a >> b;
    long long ascore, bscore;
    ascore = bscore = 0;
    vector<vector<long long>> ac(3, vector<long long>(3));
    vector<vector<long long>> bc(3, vector<long long>(3));
    for (long long i = 0; i < 3; i++)
    {
        for (long long j = 0; j < 3; j++)
        {
            cin >> ac[i][j];
        }
    }
    for (long long i = 0; i < 3; i++)
    {
        for (long long j = 0; j < 3; j++)
        {
            cin >> bc[i][j];
        }
    }
    set<pair<long long,long long>> s;
    vector<pair<long long,long long>> c;
    bool found = false;
    while (k--)
    {
        //cout << a << " " << b << endl;
        if (!s.count({a,b}))
        {
            c.push_back({a,b});
        }
        else if (s.count({a,b}) == 1 && !found && k > 1e7)
        {
            c.push_back({a,b});
            long long i;
            for (i = c.size()-2; i >= 0; i--)
            {
                if (c[i] == make_pair(a,b))
                {
                    cerr << "found at " << i << endl;
                    break;
                }
            }
            long long awin, bwin;
            awin = bwin = 0;
            for (long long j = i; j < (long long)c.size()-1; j++)
            {
                long long res = win(a,b);
                long long x = a;
                a = ac[a-1][b-1];
                b = bc[x-1][b-1];
                if (res == 1)
                {
                    awin++;
                }
                else if (res == -1)
                {
                    bwin++;
                }
                else
                {
                    //
                }
            }
            cerr << awin << " " << bwin << " << win" << endl;
            long long size = abs(i-((long long)c.size()-1));
            long long x = k / size;
            cerr << size << endl;
            for (auto it : c)
            {
                cerr << it.first << " " << it.second << endl;
            }
            k %= size;
            ascore += x*awin;
            bscore += x*bwin;
            found = true;
        }
        s.insert({a,b});
        long long res = win(a,b);
        if (res == 1)
        {
            ascore++;
        }
        else if (res == -1)
        {
            bscore++;
        }
        else
        {
            //
        }

        long long x = a;
        a = ac[a-1][b-1];
        b = bc[x-1][b-1];
    }
    cout << ascore << " " << bscore << endl;
}
