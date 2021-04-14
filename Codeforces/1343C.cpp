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
        //int start = a[0]/abs(a[0]);
        //int count = 1;
        //for (int i = 1; i < n; i++)
        //{
        //    if (a[i]/abs(a[i]) != start)
        //    {
        //        count++;
        //        start = a[i]/abs(a[i]);
        //    }
        //}
        //cout << count << endl;
        vector<int> b;
        long long ans = 0;
        int start = a[0]/abs(a[0]);
        b.push_back(a[0]);
        for (int i = 1; i < n; i++)
        {
            if (a[i]/abs(a[i]) == start)
            {
                b.push_back(a[i]);
            }
            else
            {
                int add = *max_element(b.begin(), b.end());
                //cerr << "add: " << add << endl;
                ans += add;
                start *= -1;
                b = vector<int>();
                b.push_back(a[i]);
            }
        }
        int add = *max_element(b.begin(), b.end());
        //cerr << "add: " << add << endl;
        ans += add;
        cout << ans << endl;
    }

}
