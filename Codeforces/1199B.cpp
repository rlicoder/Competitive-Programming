#include <bits/stdc++.h>

using namespace std;

int main()
{
    long double h,l;
    cin >> h >> l;
    //observation: the stem will stay at a constant length
    //therefore the diagonal is depth + H
    //so l^2 + x^2 = (h+x)^2
    //where x is what we want to find
    cout << fixed << setprecision(17);
    cout << (l*l-h*h)/(2*h) << endl;
}
