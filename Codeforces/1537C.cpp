#include <bits/stdc++.h>

using namespace std;

int score (vector<int> a)
{
    int s = 0;
    for (int i = 0; i < a.size()-1; i++)
    {
        if (a[i+1] >= a[i])
        {
            s++;
        }
    }
    return s;
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        bool found = false;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        if (a.size() == 2)
        {
            for (auto it : a)
            {
                cout << it << " ";
            }
            cout << endl;
        }
        else
        {
            int lo = 1e9;
            for (int i = 0; i < n-1; i++)
            {
                lo = min(lo, a[i+1] - a[i]);
            }

            vector<pair<int,int>> canidates;
            for (int i = 0; i < n-1; i++)
            {
                if (a[i+1] - a[i] == lo)
                {
                    canidates.push_back({a[i+1], a[i]});
                }
            }
            sort(canidates.begin(), canidates.end());

            vector<int> b = a;
            vector<int> x;
            x.push_back(canidates[0].first);
            b.erase(lower_bound(b.begin(), b.end(), canidates[0].first));
            b.erase(lower_bound(b.begin(), b.end(), canidates[0].second));
            for (auto it : b)
            {
                x.push_back(it);
            }
            x.push_back(canidates[0].second);


            b = a;
            vector<int> y;
            y.push_back(canidates.back().first);
            b.erase(lower_bound(b.begin(), b.end(), canidates.back().first));
            b.erase(lower_bound(b.begin(), b.end(), canidates.back().second));
            for (auto it : b)
            {
                y.push_back(it);
            }
            y.push_back(canidates.back().second);


            if (score(x) < score(y))
            {
                if (n == 4)
                {
                    vector<int> z = y;
                    reverse(z.begin()+1, z.end()-1);
                    if (score(z) > score(y))
                    {
                        for (auto it : z)
                        {
                            cout << it << " ";
                        }
                    }
                    else
                    {
                        for (auto it : x)
                        {
                            cout << it << " ";
                        }
                    }
                }
                else
                {
                    for (auto it : x)
                    {
                        cout << it << " ";
                    }
                }
            }
            else
            {
                if (n == 4)
                {
                    vector<int> z = x;
                    reverse(z.begin()+1, z.end()-1);
                    if (score(z) > score(y))
                    {
                        for (auto it : z)
                        {
                            cout << it << " ";
                        }
                    }
                    else
                    {
                        for (auto it : x)
                        {
                            cout << it << " ";
                        }
                    }
                }
                else
                {
                    for (auto it : y)
                    {
                        cout << it << " ";
                    }
                }
            }
            cout << endl;
        }
    }
}
