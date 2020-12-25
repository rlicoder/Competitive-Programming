#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> primes;
    primes.push_back(2);
    for (int i = 3; i <= 50; i++)
    {
        bool ok = true;
        for (int j = 2; j <= i; j++)
        {
            if (i%j == 0 && i != j)
            {
                ok = false;
            }
        }
        if (ok)
        {
            primes.push_back(i);
        }
    }
    int n,m;
    cin >> n >> m;
    if (primes[find(primes.begin(), primes.end(), n) - primes.begin() + 1] == m)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}


