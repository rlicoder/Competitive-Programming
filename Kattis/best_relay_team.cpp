#include <bits/stdc++.h>

using namespace std;

bool second(pair<string,array<long double,2>> a, pair<string,array<long double,2>> b)
{
    return a.second[1] < b.second[1];
}
bool first(pair<string,array<long double,2>> a, pair<string,array<long double,2>> b)
{
    return a.second[0] < b.second[0];
}

int main()
{
    int n;
    cin >> n;
    vector<pair<string,array<long double,2>>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second[0] >> a[i].second[1];
    }
    sort(a.begin(), a.end(), first);
    set<pair<string,array<long double, 2>>> s;
    vector<pair<string,array<long double, 2>>> ans;
    vector<string> names;
    long double low = 1e8;
    for (int i = 0; i < a.size(); i++)
    {
        s.insert(a[i]);
        ans.push_back(a[i]);
        sort(a.begin(), a.end(), second);
        for (int j = 0; j < a.size() && s.size() < 4; j++)
        {
            if (s.count(a[j]) == 0)
            {
                ans.push_back(a[j]);
            }
            s.insert(a[j]);
        }
        long double test = ans[0].second[0] + ans[1].second[1] + ans[2].second[1] + ans[3].second[1];
        if (low > test)
        {
            low = test;
            names = vector<string>();
            names.push_back(ans[0].first);
            names.push_back(ans[1].first);
            names.push_back(ans[2].first);
            names.push_back(ans[3].first);
        }
        sort(a.begin(), a.end(), first);
        s = set<pair<string,array<long double,2>>>();
        ans = vector<pair<string,array<long double, 2>>>();
    }
    cout << fixed << setprecision(16);
    cout << low << endl;
    for (auto it : names)
    {
        cout << it << endl;
    }
}

