#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m ;
    cin >> n >> m;
    int count = 1;
    while (true)
    {
        if (m-count < 0)
        {
            cout << m << endl;
            break;
        }
        m-=count;
        count++;
        if (count == n+1)
        {
            count = 1;
        }

    }
}
