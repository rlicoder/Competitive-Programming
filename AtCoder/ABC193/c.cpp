#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = n;
    for (int i = 2; i <= sqrt(n); i++)
    {
        cerr << "max " << i << "^";
        cerr << floor(log(n) / log(i)) << endl;
        int x = floor(log(n) / log(i));
        ans -= (x < 2 ? 0 : x-1);
    }
    cout << ans;
}
