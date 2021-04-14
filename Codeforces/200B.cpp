#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long double x;
    long double total = 0.0;
    for (int i = 0; i < n ; i++)
    {
        cin >> x;
        total += x;
    }
    cout << fixed << setprecision(20);
    cout << total / (long double)n << endl;


}
