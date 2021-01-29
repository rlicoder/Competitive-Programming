#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n,k;
    cin >> n >> k;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long i = 0;
    while (k-i > i)
    {
        k -= i+1;
        i++;
    }
    if (k==0)
    {
        k++;
    }
    cout << a[k-1];
}
