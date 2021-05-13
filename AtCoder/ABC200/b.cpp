#include <bits/stdc++.h>

using namespace std;

int main()
{
    unsigned long long n;
    cin >> n;
    int k;
    cin >> k;
    while (k--)
    {
        if (n % 200 == 0)
        {
            n /= 200;
        }
        else
        {
            string str = to_string(n);
            str += "200";
            n = stol(str);
        }
    }
    cout << n << endl;
}
