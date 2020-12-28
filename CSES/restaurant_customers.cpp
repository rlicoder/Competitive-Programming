#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    vector<pair<int,int>> a(2*n);
    
    for (int i = 0; i < 2*n; i+=2)
    {
        int x, b;
        cin >> x >> b;
        a[i].first = x;
        a[i].second = 1;
        a[i+1].first = b;
        a[i+1].second = -1;
    }
    sort(a.begin(), a.end());
    int count = 0;
    for (int i = 0; i < a.size(); i++)
    {
        count += a[i].second;
        ans = max(ans, count);
    }
    cout << ans << endl;

}
