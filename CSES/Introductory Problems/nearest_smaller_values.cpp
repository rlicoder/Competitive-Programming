#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    stack<pair<int,int>> s;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        bool found = false;
        while (!s.empty() && !found)
        {
            if (s.top().first < x)
            {
                found = true;
            }
            else
            {
                s.pop();
            }
        }
        if (found)
        {
            cout << s.top().second+1 << " ";
            //s.pop();
        }
        else
        {
            cout << 0 << " ";
        }
        s.push({x, i});
    }
}
