#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<array<int,3>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i;
    }
    sort(a.begin(), a.end());
    vector<int> b(n), c(n);
    for (int i = 0; i < n; i++)
    {
        int j = i+1;
        for (; j < n; j++)
        {
            if (a[j][0] > a[i][1])
            {
                break;
            }
            else if (a[j][1] <= a[i][1])
            {
                b[a[i][2]] = 1;
                c[a[j][2]] = 1;
            }
        }
        i = j;
    }
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << c[i] << " ";
    }
    cout << endl;

}
