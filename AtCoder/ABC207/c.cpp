#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<array<int, 3>> a;
    for (int i = 0; i < n; i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        a.push_back({x,y,z});
    }
    function<bool(array<int,3>, array<int,3>)> comp = [&] (array<int,3> x, array<int,3> y)
    {
        if (x[1] != y[1])
        {
            return x[1] < y[1];
        }
        else if (x[2] != y[2])
        {
            return x[2] < y[2];
        }
        else
        {
            return x[0] < y[0];
        }
    };
    sort(a.begin(), a.end(), comp);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (a[j][1] < a[i][2])
            {
                count++;
            }
            else if (a[j][1] == a[i][2])
            {
                if (a[j][0] == 3 || a[i][0] == 2 || a[j][0] == 4 || a[i][0] == 4)
                {
                    count += 0;
                }
                else
                {
                    count++;
                }
            }
        }
    }
    cout << count << endl;
}
