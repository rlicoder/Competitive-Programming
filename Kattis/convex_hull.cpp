#include <bits/stdc++.h>

using namespace std;

long double cross (pair<int,int> a, pair<int,int> b, pair<int,int> c)
{
    pair<long double, long double> fi = {(long double)(b.first - a.first), (long double)(b.second - a.second)};
    pair<long double, long double> se = {(long double)(c.first - b.first), (long double)(c.second - b.second)};
 
    return (fi.first * se.second) - (fi.second * se.first);
}

int main()
{
    int n;
    cin >> n;
    while (n!=0)
    {
        vector<pair<int,int>> a(n);
        for (int i = 0 ; i < n; i++)
        {
            cin >> a[i].first >> a[i].second;
        }

        sort(a.begin(), a.end());
        vector<pair<int,int>> lower;
        pair<int,int> start = {a[0].first, a[0].second};
        pair<int,int> end = a.back();
        lower.push_back(start);
     
        for (int i = 1; i < n; i++)
        {
            lower.push_back(a[i]);
            if (lower.size() >= 3)
            {
                pair<int,int> last;
                pair<int,int> second;
                pair<int,int> third;
                last = lower.back();
                second = *(lower.end()-2);
                third = *(lower.end()-3);
                while (cross(third, second, last) <= 0 && lower.size() >= 3)
                {
                    lower.erase(lower.end()-2);
                    last = lower.back();
                    second = *(lower.end()-2);
                    third = *(lower.end()-3);
                }
            }
        }
        
        vector<pair<int,int>> upper;
        upper.push_back(start);

        for (int i = 1; i < n; i++)
        {
            upper.push_back({a[i].first, a[i].second});
            if (upper.size() >= 3)
            {
                pair<int,int> last;
                pair<int,int> second;
                pair<int,int> third;
                last = upper.back();
                second = *(upper.end()-2);
                third = *(upper.end()-3);
                while (cross(third, second, last) >= 0 && upper.size() >= 3)
                {
                    upper.erase(upper.end()-2);
                    last = upper.back();
                    second = *(upper.end()-2);
                    third = *(upper.end()-3);
                }
            }
        } 
        //cout << "upper:" << endl;
        //for (auto it: upper)
        //{
        //    cout << it.first << " " << it.second << endl;
        //}
        //cout << endl;
        //cout << "lower: " << endl;
        //for (auto it: lower)
        //{
        //    cout << it.first << " " << it.second << endl;
        //}
        //cout << endl;

        set<pair<int,int>> s;
        vector<pair<int,int>> ans;
        for (auto it : lower)
        {
            if (s.count(it) == 0)
            {
                ans.push_back(it);
            }
            s.insert(it);
        }
        for (int it = upper.size()-1; it >= 0; it--)
        {
            if (s.count(upper[it]) == 0)
            {
                ans.push_back(upper[it]);
            }
            s.insert(upper[it]);
        }
        cout << ans.size() << endl;
        for (auto it : ans)
        {
            cout << it.first << " " << it.second << endl;
        }
        cin >> n;
    }
}
