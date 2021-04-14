#include <bits/stdc++.h>

using namespace std;

int main()
{
    unsigned long long n;
    cin >> n;
    vector<unsigned long long> a(n);
    unsigned long long total = 0;
    for (unsigned long long i = 0; i < n; i++)
    {
        cin >> a[i];
        total += a[i];
    }
    sort(a.begin(),a.end());
    unsigned long long s = 0;
    if (n%2)
    {
        reverse(a.begin(),a.end());
        s = accumulate(a.begin(), a.begin() + (n/2)+1, 0);
    }
    else
    {
        s = accumulate(a.begin(), a.begin() + n/2, 0);
    }
    cout << s*s + (total-s)*(total-s) << endl;
}
