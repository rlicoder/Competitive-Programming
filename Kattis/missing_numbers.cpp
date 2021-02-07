#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int max = 0;
    vector<int> vis(201, false);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        sum += x;
        vis[x] = true;
        max = x;
    }
    if (sum == max*(max+1)/2)
    {
        cout << "good job" << endl;
        return 0;
    }
    for (int i = 1; i <= max; i++)
    {
        if (vis[i] == false)
        {
            cout << i << endl;
        }
    }
}
