#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int s;
    cin >> s;
    vector<array<int, 3>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    long double ep = 1e-6;
    long double l = 0;
    long double r = 1e7;
    function<bool(long double)> valid = [&] (long double r)
    {
        int pop = s;
        for (int i = 0; i < n; i++)
        {
            if (sqrt(pow(a[i][0], 2) + pow(a[i][1], 2)) <= r)
            {
                pop += a[i][2];
            }
        }
        return pop >= (int)1e6;
    };
    long double mid;
    int count = 0;
    while (l < r)
    {
        mid = (l + r) / 2.0;
        if (valid(mid))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
        count++;
        if (count == 100)
        {
            break;
        }
    }
    if (abs(mid - 1e7) <= ep)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << setprecision(10) << endl;
        cout << mid << endl;
    }
}
