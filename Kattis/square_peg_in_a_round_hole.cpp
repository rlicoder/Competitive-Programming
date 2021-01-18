#include <bits/stdc++.h>

using namespace std;

main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<long double> plots(n);
    vector<long double> houses(m);
    for (int i = 0; i < n; i++)
    {
        cin >> plots[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> houses[i];
    }
    for (int i = 0; i < k; i++)
    {
        long double x;
        cin >> x;
        houses.push_back(x*sqrt(2.0)/2);
    }
    sort(houses.begin(), houses.end());
    sort(plots.begin(), plots.end());

    int j = 0;
    int ans = 0;
    for (int i = 0; i < houses.size(); i++)
    {
        if (j == plots.size())
        {
            break;
        }
        while(houses[i] >= plots[j])
        {
            j++;
        }
        if (houses[i] < plots[j])
        {
            j++;
            ans++;
        }
        
    }
    cout << ans;
}
