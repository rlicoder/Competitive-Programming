#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n,m;
        cin >> n >> m;
        vector<vector<char>> a(n, vector<char>(m));
        bool atleast = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
                if (a[i][j] != '.')
                {
                    atleast = true;
                }
            }
        }
        if (!atleast)
        {
            a[0][0] = 'R';
        }
        bool ok = true;
        function<bool(int,int)> valid = [&] (int i, int j)
        {
            return i >= 0 && i < n && j >= 0 && j < m;
        };
        function<bool()> finished = [&] ()
        {
            for (auto it : a)
            {
                for (auto x : it)
                {
                    if (x == '.')
                    {
                        return false;
                    }
                }
            }
            return true;
        };
        while (!finished())
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (a[i][j] == 'R')
                    {
                        if (valid(i+1,j))
                        {
                            if (a[i+1][j] == 'R')
                            {
                                ok = false;
                            }
                            a[i+1][j] = 'W';
                        }
                        if (valid(i-1,j))
                        {
                            if (a[i-1][j] == 'R')
                            {
                                ok = false;
                            }
                            a[i-1][j] = 'W';
                        }
                        if (valid(i,j+1))
                        {
                            if (a[i][j+1] == 'R')
                            {
                                ok = false;
                            }
                            a[i][j+1] = 'W';
                        }
                        if (valid(i,j-1))
                        {
                            if (a[i][j-1] == 'R')
                            {
                                ok = false;
                            }
                            a[i][j-1] = 'W';
                        }
                    }
                    else if (a[i][j] == 'W')
                    {
                        if (valid(i+1,j))
                        {
                            if (a[i+1][j] == 'W')
                            {
                                ok = false;
                            }
                            a[i+1][j] = 'R';
                        }
                        if (valid(i-1,j))
                        {
                            if (a[i-1][j] == 'W')
                            {
                                ok = false;
                            }
                            a[i-1][j] = 'R';
                        }
                        if (valid(i,j+1))
                        {
                            if (a[i][j+1] == 'W')
                            {
                                ok = false;
                            }
                            a[i][j+1] = 'R';
                        }
                        if (valid(i,j-1))
                        {
                            if (a[i][j-1] == 'W')
                            {
                                ok = false;
                            }
                            a[i][j-1] = 'R';
                        }
                    }
                }
            }
        }
        function<bool(int,int)> cvalid = [&] (int i, int j)
        {
            char base = a[i][j];
            bool ok = true;
            if (valid(i+1, j))
            {
                if(a[i+1][j] == base)
                {
                    return false;
                }
            }
            if (valid(i-1, j))
            {
                if(a[i-1][j] == base)
                {
                    return false;
                }
            }
            if (valid(i, j-1))
            {
                if(a[i][j-1] == base)
                {
                    return false;
                }
            }
            if (valid(i, j+1))
            {
                if(a[i][j+1] == base)
                {
                    return false;
                }
            }
            return ok;
        };
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(!cvalid(i,j))
                {
                    ok = false;
                }
            }
        };
        if (ok)
        {
            cout << "YES" << endl;
            for (auto it : a)
            {
                for (auto x : it)
                {
                    cout << x;
                }
                cout << endl;
            }
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
