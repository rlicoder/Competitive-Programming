#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        vector<int> a(4);
        for (int i = 0; i < 4; i++)
        {
            cin >> a[i];
        }
        vector<int> b = a;
        sort(b.begin(), b.end());
        int h = max(a[0], a[1]);
        int l = max(a[2], a[3]);
        if (max(h,l) == b.back() && min(h,l) == b[2])
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
        cout << endl;

    }
}
