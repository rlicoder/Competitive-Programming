#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int neg, pos, zero;
    neg=pos=zero=0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > 0)
        {
            pos++;
        }
        else if (a[i] < 0)
        {
            neg++;
        }
        else
        {
            zero++;
        }
    }
    long long ans = 0;
    if (neg % 2 == 1)
    {
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] < 0)
            {
                ans += abs(a[i]+1);
            }
            else if (a[i] > 0)
            {
                ans += abs(1-a[i]);
            }
        }
        if (zero > 0)
        {
            ans += zero;
        }
        else 
        {
            ans += 2;
        }
    }
    else if (neg % 2 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] < 0)
            {
                ans += abs(a[i] + 1);
            }
            else
            {
                ans += abs(1-a[i]);
            }
        }
    }
    cout << ans << endl;



}
