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
            cin >> a[i];
        }
        sort(a.begin(), a.end(), greater<int>());
        a[0]++;
        for (int i = 1; i < n-1; i++)
        {
            if (a[i] == a[i+1])
            {
                a[i]++;
            }
            else if (abs(a[i] - a[i-1]) >= 2)
            {
                a[i]++;
            }
        }
        set<int>s;
        for (int i = 0; i < (int)a.size(); i++)
        {
            s.insert(a[i]);
        }
        cout << s.size() << endl;
    }
}
