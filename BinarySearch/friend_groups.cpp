int solve(vector<vector<int>>& a) 
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << i << " ";
        for (int j = 0; j < a[i].size(); j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    vector<int> par(a.size());
    iota(par.begin(), par.end(), 0);
    function<int(int)> find = [&] (int x)
    {
        return x == par[x] ? x : par[x] = find(par[x]);
    };

    function<void(int, int)> unite = [&] (int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x != y)
        {
            cout << "unite: " << x << " " << y << endl;
            par[x] = y;
        }
    };
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            unite(i, a[i][j]);
        }
    }
    for (int i = 0; i < par.size(); i++)
    {
        cout << par[i] << " ";
    }
    cout << endl;
    map<int,int>m;
    for (auto it : par)
    {
        m[find(it)]++;
    }
    int ans = 0;
    // for (auto it : m)
    // {
    //     cout << it.first << " " << it.second << endl;
    //     if (it.second > 1)
    //     {
    //         ans++;
    //     }
    // }
    return m.size();
}
