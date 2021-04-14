#include <bits/stdc++.h>

//https://math.stackexchange.com/questions/628117/how-to-count-lattice-points-on-a-line
//^ use this for boundary points, then use pick's theorem and some (linear) algebra
using namespace std;

struct pt
{
    long long x,y;
};

long long gcd(long long a, long long b)
{
    a = abs(a);
    b = abs(b);
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<pt> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].x >> a[i].y;
    }
    long long B = 0;
    long long A = 0;
    for (int i = 0; i < n-1; i++)
    {
        //cout << a[i].x << " " << a[i].y << " " << a[i+1].x << " " << a[i+1].y << endl;
        //cout << gcd(a[i+1].x - a[i].x, a[i+1].y - a[i].y) - 1 << endl;
        B += gcd(a[i+1].x - a[i].x, a[i+1].y - a[i].y) - 1;
        A += (a[i].x * a[i+1].y) - (a[i+1].x * a[i].y);
    }
    B += gcd(a[0].x - a.back().x, a[0].y - a.back().y) - 1;
    B += n;
    A += (a.back().x * a[0].y) - (a[0].x * a.back().y);
    A = abs(A);
    long long I = (A/2) + 1 - (B/2);
    //cout << A << endl;
    cout << I << " " << B << endl;
}
