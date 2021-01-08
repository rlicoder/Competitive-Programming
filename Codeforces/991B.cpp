#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int count = 0;
    sort(a.begin(), a.end());
    int i = 0;
    while ((long double)accumulate(a.begin(), a.end(), 0) < (long double)4.5*n)
    {
        count++;
        a[i] = 5;
        i++;
    }
    cout << count << endl;
}
