#include <bits/stdc++.h>

using namespace std;

int main()
{
    //if congruent, must have same area + perimeter
    //if congruent + no reflections necessary, then it is possible
    int n;
    cin >> n;
    vector<pair<int,int>> a, b;
    for (int i = 0; i < n; i++)
    {
        int x,y;
        cin >> x >> y;
        a.push_back({x,y});
    }
    for (int i = 0; i < n; i++)
    {
        int x,y;
        cin >> x >> y;
        b.push_back({x,y});
    }
    long double pa, pb;
    long double aa, ab;
    pa = pb = aa = ab = 0;
    for (int i = 0; i < n-1; i++)
    {
        aa += (a[i].first * a[i+1].second) - (a[i+1].first * a[i].second);
    }
    aa += (a.back().first * a[0].second) - (a[0].first * a.back().second);
    aa = abs(aa / 2);

    for (int i = 0; i < n-1; i++)
    {
        ab += (b[i].first * b[i+1].second) - (b[i+1].first * b[i].second);
    }
    ab += (b.back().first * b[0].second) - (b[0].first * b.back().second);
    ab = abs(ab / 2);

    for (int i = 0; i < n-1; i++)
    {
        pa += sqrt(pow(a[i].first - a[i+1].first, 2) + pow(a[i].second + a[i+1].second, 2));
    }
    pa += sqrt(pow(a[0].first - a.back().first, 2) + pow(a[0].second - a.back().second, 2));

    for (int i = 0; i < n-1; i++)
    {
        pb += sqrt(pow(b[i].first - b[i+1].first, 2) + pow(b[i].second + b[i+1].second, 2));
    }
    pb += sqrt(pow(b[0].first - b.back().first, 2) + pow(b[0].second - b.back().second, 2));

    if (pa == pb && aa == ab)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    cout << endl;

}
