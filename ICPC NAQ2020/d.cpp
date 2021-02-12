#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w, p;
    cin >> w >> p;
    vector<int> a;
    a.push_back(0);
    for (int i = 0; i < p; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    a.push_back(w);
    set<int> s;
    for (int i = 0; i < a.size()-1; i++)
    {
        for (int j = i+1; j < a.size(); j++)
        {
            s.insert(abs(a[i]-a[j]));
        }
    }
    for (auto it : s)
    {
        cout << it << " ";
    }

}

