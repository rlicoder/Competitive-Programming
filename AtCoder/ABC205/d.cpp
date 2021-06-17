#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int q;
    cin >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> before(n);
    for (int i = 0; i < n; i++)
    {
        before[i] = before[i] - (i == 0 ? 0 : a[i-1]) - 1;
    }
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        

    }
    

}
