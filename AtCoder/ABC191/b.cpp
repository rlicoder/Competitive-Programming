#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            a[i] = 0;
        }
    }
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == 0)
        {

        }
        else
        {
            cout << a[i] << " ";
        }
    }
}
