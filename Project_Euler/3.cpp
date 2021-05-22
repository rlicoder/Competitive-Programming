#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n = 600851475143;
    set<int> a;
    for (int i = 2; i <= sqrt(n); i++)
    {
        while (n % i == 0)
        {
            n /= i;
            a.insert(i);
        }
    }
    if (n != 1)
    {
        a.insert(n);
    }
    for (auto it : a)
    {
        cout << it << " ";
    }
}
