#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x;
    cin >> x >> n;
    set<int> s;
    s.insert(0);
    s.insert(x);
    map<int,int>m;
    m[x]++;
    for (int i = 0; i < n; i++)
    {
        int y;
        cin >> y;
        auto it = s.upper_bound(y);
        int r = *it;
        it--;
        int l = *it;
        m[r-l]--;
        if (m[r-l] == 0)
        {
            m.erase(r-l);
        }
        m[r-y]++;
        m[y-l]++;
        s.insert(y);

        cout << (--(m.end()))->first << " ";
        
    }
    
}

