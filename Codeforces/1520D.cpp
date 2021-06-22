#include <bit/stdc++.h>

using namespace std;

main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        map<int,int> m;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            m[a[i]]++;
        }
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += 
        }
        cout << ans / 2 << endl;

    }
}
