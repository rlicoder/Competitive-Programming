#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long a,b,c,d;
    cin >> a >> b >> c >> d;
    long long cyan = a;
    long long red = 0;
    long long count = -1;
    for (long long i = 0; i < 1e6; i++)
    {
        if (red * d >= cyan)
        {
            break;
        }
        cyan += b;
        red += c;
        count++;
    }
    if (red * d >= cyan)
    {
        cout << count+1 << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}
