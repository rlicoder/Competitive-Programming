#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    vector<int> a;
    int i = 1;
    int j = 2;

    while (i < (int)2e9+1)
    {
        a.push_back(i);
        i += j;
        j++;
    }

    map<pair<int,int>, string> m;
    while (tc--)
    {
        int n,k;
        cin >> n >> k;
        if (m.count({n,k}))
        {
            cout << m[{n,k}] << endl;
            continue;
        }
        if (k==1)
        {
            string s (n-2,'a');
            cout << s << "bb" << endl;
            continue;
        }
        auto low = upper_bound(a.begin(), a.end(), k);
        low--;
        int count = (low - a.begin());
        count++;
        string s = "";
        for (int i = 1; i < count; i++)
        {
            s+='a';
        }
        s+="bb";
        while (s.size() < n)
        {
            s+='a';
        }
        reverse(s.begin(), s.end());

        for (int l = 0; l < abs(*low-k); l++)
        {
            next_permutation(s.begin(), s.end());
        }
        m[{n,k}] = s;
        cout << s << endl;
    }
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}

