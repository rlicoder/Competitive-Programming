#include <bits/stdc++.h>

using namespace std;

int find(int,vector<int>&);
void unite(int,int,vector<int>&);

int find (int x, vector<int>& par)
{
    return (x == par[x] ? x : par[x] = find(par[x], par));
}

void unite(int x, int y, vector<int>& par, int& count)
{
    x = find(x, par);
    y = find(y, par);
    if (x!=y)
    {
        par[x] = y;
    }
}

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int>par(n+1);
    iota(par.begin(), par.end(),0);
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin >> x >> y;
        unite(x,y,par,count);
    }
    set<int>s;
    for (int i = 1; i < par.size(); i++)
    {
        //cout << find(par[i], par) << endl;
        s.insert(find(par[i], par));
    }
    vector<int> ans(s.begin(), s.end());
    cout << ans.size()-1 << endl;
    for(int i = 0; i < ans.size()-1; i++)
    {
        cout << ans[i] << " " << ans[i+1] << endl;
    }

}
