#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long on = n;
    map<long long, long long> map;
    for (int i = 2; i*i <= n; i++)
    {
        while (n % i == 0)
        {
            n /= i;
            map[i]++;
        }
    }
    if(map.size() > 1 || on == 1 || (map.size() == 1 && n != 1))
    {
        cout << "no";
    }
    else 
    {
        cout << "yes";
    }
}
