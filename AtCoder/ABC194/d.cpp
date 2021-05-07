#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long double ans = 1;
    for (int i = n-1; i > 0; i--)
    {
        ans *= i/(long double)n;
    }
    cout << fixed << setprecision(10);
    cout << 1/ans << endl;
}
