#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i+1;
    }
    int l = 0;
    int r = n-1;
    pair<int,int> ans = {0,0};
    sort(a.begin(), a.end());
    bool found = false;

    while (l < r)
    {
        if (a[l].first + a[r].first == x)
        {
            found = true;
            ans = {l,r};
            break;
        }
        else if (a[l].first+a[r].first > x)
        {
            r--;
        }
        else
        {
            l++;
        }
    }
    if (found)
    {
        cout << a[l].second << " " << a[r].second << endl;

    }
    else
    {
        cout << "IMPOSSIBLE";
    }
          
}
