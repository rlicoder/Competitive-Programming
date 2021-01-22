#include <bits/stdc++.h>

using namespace std;

main() 
{
    int b, br, a, as, bs;
    cin >> b >> br >> bs >> a >> as;
    int bobbal = (br - b) * bs;
    int alicebal = 0;
    while (alicebal <= bobbal)
    {
        a++;
        alicebal += as;
    }
    cout << a;
}

