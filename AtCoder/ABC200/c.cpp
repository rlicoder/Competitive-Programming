#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int,int> f;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        f[a[i]]++;
    }
    vector<int> b = a;
    sort(b.begin(), b.end());
    set<int> s (a.begin(), a.end());
    int ans = 0;
    for (auto it : s)
    {
        //cout << "i is: " << it << endl;
        for (int j = 0; j <= ceil(it/200); j++)
        {
            //cout << "looking for: " << abs((j*200)-it) << endl;
            int x = -1 * (j*200 - it);
            if (binary_search(b.begin(), b.end(), x))
            {
                //cerr << it << " " << abs((j*200)-it) << endl;
                if (it == x)
                {
                    ans += max(f[it], f[x]) / 2;
                    //cerr << max(f[it], f[abs((j*200)-it)]) / 2 << endl;
                }
                else
                {
                    ans += max(f[it], f[x]);
                    //cerr << max(f[it], f[abs((j*200)-it)]) << endl;
                }
            }
        }
    }
    cout << ans << endl;
}
