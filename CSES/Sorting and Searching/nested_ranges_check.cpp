#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<array<int,3>> a;
    vector<array<int,3>> b;
    for (int i = 0; i < n; i++)
    {
        int x,y;
        cin >> x >> y;
        a.push_back({x,y,i});
        b.push_back({x,y,i});
    }
    sort(b.begin(), b.end());
    vector<bool> found (n, false);
    function<int(int,int,int)> bs = [&] (int x, int y, int z)
    {
        int l = 0;
        int r = n-1;
        int pos = -1;
        array<int,2> ans;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (b[mid][0] > x || (b[mid][0] == x && b[mid][1] >= y))
            {
                r = mid - 1;
                ans[0] = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        l = 0;
        r = n-1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (b[mid][0] < x || (b[mid][0] == x && b[mid][1] <= y))
            {
                ans[1] = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        for (int i = ans[0]; i <= ans[1]; i++)
        {
            if (b[i][2] == z)
            {
                return i;
            }
        }
        assert(false);
        return -1;
    };
    vector<bool> contained(n, false);
    for (int i = 0; i < n; i++)
    {
        int pos = bs(a[i][0], a[i][1], a[i][2]);
        for (int j = pos; j >= 0; j--)
        {
            if (b[j][0] < a[i][0]) break;
            if (b[j][1] <= a[i][1])
            {
                found[i] = true;
                contained[b[j][2]] = true;
            }

        }
        for (int j = pos; j < n; j++)
        {
            if (b[j][1] > a[i][1]) break;
            if (b[j][0] >= a[i][0])
            {
                found[i] = true;
                contained[b[j][2]] = true;
            }
        }
    }
    for (int i = 0; i < found.size(); i++)
    {
        cout << found[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < contained.size(); i++)
    {
        cout << contained[i] << " ";
    }
    cout << endl;
}
