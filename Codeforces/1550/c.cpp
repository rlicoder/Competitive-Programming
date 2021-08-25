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
        vector<int> good(n, true);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int count = 0;
        for (int i = 0; i <= n-3; i++)
        {
            int lowerx = min(a[i], a[i+2]);
            int upperx = max(a[i], a[i+2]);
            if (!(a[i+1] >= lowerx && a[i+1] <= upperx))
            {
                count++;
            }
        }
        for (int i = 0; i <= n-4; i++)
        {
            int lowerx = min(a[i], a[i+3]);
            int upperx = max(a[i], a[i+3]);
            bool found = false;
            if (a[i+1] >= lowerx && a[i+1] <= upperx)
            {
                found = true;
            }
            else if (a[i+2] >= lowerx && a[i+2] <= upperx)
            {
                found = true;
            }
            if (!found) count++;
        }
        count += a.size();
        count += a.size()-1;
        cout << count << endl;
    }
}
