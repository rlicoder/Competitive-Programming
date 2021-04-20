#include <bits/stdc++.h>

using namespace std;

long double torad(double deg)
{
    return deg * (3.14159265) / 180.0;
}

int main()
{
    long double n;
    cin >> n;
    long double x0,y0,xn,yn;
    cin >> x0 >> y0 >> xn >> yn;
    double deg = 360.0 / n;
    long double rad = sqrt(pow(xn-x0,2) + pow(yn-y0,2))/2;
    long double opp = sin(torad(deg)) * rad;
    long double adj = cos(torad(deg)) * rad;
    cout << rad << " " << opp << " " << adj << endl;
    cout << x0 + opp << " " << y0 + adj << endl;
}
