#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            a[i] = i+1;
        }
        for (int i = 0; i < n-1; i+=2)
        {
            swap(a[i], a[i+1]);
        }
        if (a.size() % 2 == 1)
        {
            swap(a[n-1], a[n-2]);
        }
        for (auto it : a)
        {
            cout << it << " ";
        }
        cout << endl;
    }
}
