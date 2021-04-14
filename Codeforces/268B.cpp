#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long on = n;
    long long ans = 0;
    int i = 1;
    while (n > 1)
    {
        ans += (n-1)*i;
        i++;
        n--;
    }
    cout << ans + on << endl;
}


