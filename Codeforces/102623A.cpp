#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        long long n,m,x,y;
        cin >> n >> m >> x >> y;
        cout << min(m,(n+(m-1)*y)/x) << endl;
    }
}
