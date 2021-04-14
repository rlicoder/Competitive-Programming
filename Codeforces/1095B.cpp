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
    sort(a.begin(), a.end());
    int ins = a.back() - a[0];
    if (a.size() == 2)
    {
        cout << 0 << endl;
        return 0;
    }
    else 
    {
        cout << ins - max(a[1]-a[0], a.back() - a[a.size()-2]) << endl;
    }
}
