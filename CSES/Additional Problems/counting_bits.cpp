#include <bits/stdc++.h>

using namespace std;

int main()
{
    for (int i = 0; i < 100; i++)
    {
        bitset<32> a(i);
        cout << a.count() << endl;
    }
}
