#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        bitset<30> x(str);
        a[i] = x.to_ulong();
    }
    int lo = 32;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = i+1; j < a.size(); j++)
        {
            lo = min(lo, __builtin_popcount(a[i]^a[j]));
        }
    }
    cout << lo << endl;
}
