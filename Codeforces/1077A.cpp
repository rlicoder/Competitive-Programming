#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        long long a,b,k;
        cin >> a >> b >> k;
        long long ans = (a*((k+1)/2)) - (b*(k/2));
        cout << ans << endl;
    }
}
