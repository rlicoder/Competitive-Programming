#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<array<3,int>> a,b,c,d;
    for (int i = 0; i < n; i++)
    {
        int w,x,y,z;
        cin >> w >> x >> y >> z;
        a.push_back({w,i,1});
        b.push_back({x,i,2});
        c.push_back({y,i,3});
        d.push_back({z,i,4});
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());

    vector<pair<int,int>> ans;

    function <int(vector<pair<int,int>>)> valid = [&] (vector<pair<int,int>> a)
    {
        set<int> s;
        for (int i = 0; i < a.size(); i++)
        {
            s.insert(a[i].second);
        }
        return s.size() == 4;
    };

    while (!valid(a))
    {
        a.push_back()
    }

}
