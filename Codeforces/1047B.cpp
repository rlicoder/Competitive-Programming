#include <bits/stdc++.h>

using namespace std;

int main()
{
    unsigned long long n;
    cin >> n;
    unsigned long long high = 0;
    unsigned long long ans = 0;
    for (unsigned long long i = 0; i < n; i++)
    {
        unsigned long long a,b;
        cin >> a >> b;
        ans = max(ans, a+b);
    }
    cout << ans << endl;
}
