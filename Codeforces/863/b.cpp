#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    n *= 2;
    vector<int>a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int lo = 2e9;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            int t,t1;
            t = a[i];
            t1 = a[j];
            a.erase(a.begin()+i);
            a.erase(a.begin()+j-1);
            int count = 0;
            for (int k = 1; k < a.size(); k+=2)
            {
                count += a[k] - a[k-1];
            }
            lo = min(lo, count);
            a.push_back(t);
            a.push_back(t1);
            sort(a.begin(), a.end());
        }
    }
    cout << lo << endl;
}
