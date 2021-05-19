#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> a(4);
    for (int i = 0; i < a.size(); i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < 3; i++)
    {
        cout << a.back() - a[i] << " \n"[i+1==3];
    }
}
