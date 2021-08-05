#include <bits/stdc++.h>

using namespace std;

long long pown(long long a, long long b)
{
    if (b == 0)
    {
        return 1;
    }
    else
    {
        return a * pown(a,b-1);
    }
}

int main()
{
    int q;
    cin >> q;
    vector<long long> a;
    //a[1] = {0-9} = 1*(9-1+1)l
    //a[2] = {10-99} = 2*(99-10+1);
    a.push_back(0);
    for (long long i = 0; i < 17; i++)
    {
        a.push_back((i+1) * (9 * pown(10, i)));
    }
    while (q--)
    {
        long long k;
        cin >> k;
        int pos = lower_bound(a.begin(), a.end(), k) - a.begin() - 1;
        cout << "we know that the number is a " << pos + 1 << " digit number" << endl;
    }
}
