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
        vector<long double> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        set<long double>s;
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                s.insert(abs(a[i]-a[j])*.5);
            }
        }
        cout << s.size() << endl;
    }
}
                        

