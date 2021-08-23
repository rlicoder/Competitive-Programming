#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (a[i] + a[j] == x)
            {
                count++;
                a[i] = -1;
                a[j] = -1;
            }
        }
    }
    sort(a.begin(), a.end());
    int l = upper_bound(a.begin(), a.end(), -1) - a.begin();
    int r = n-1;
    while (l <= r)
    {
        if (l == r)
        {
            count++;
            l++;
            r--;
        }
        if (a[l] + a[r] <= x)
        {
            count++;
            int rem = x - a[l] - a[r];
            l++;
            r--;
            while (a[l] <= rem)
            {
                l++;
                rem -= a[l];
            }
        }
        else if (a[l] + a[r] > x)
        {
            count++;
            r--;
        }
    }
    cout << count << endl;
}

