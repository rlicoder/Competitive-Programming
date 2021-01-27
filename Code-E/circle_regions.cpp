#include <iostream>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        long long n;
        cin >> n;
        cout << (n*n*n*n-6*n*n*n+23*n*n-18*n+24)/24 << endl;

    }
}