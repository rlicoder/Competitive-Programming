#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    set<int> s;
    int l = 0;
    //line sweep cringe, actually based (kinda geo), but im too lazy)
    s.insert(a[l].first);

}
