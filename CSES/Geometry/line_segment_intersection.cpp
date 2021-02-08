#include <bits/stdc++.h>

using namespace std;

struct pt
{
    long long x,y;
};

struct seg
{
    pt a,b;
};

bool nlineint (long long aa, long long ab, long long ba, long long bb)
{
    //checking for one dimensional intersection
    if (aa > ab)
    {
        swap(aa,ab);
    }
    if (ba > bb)
    {
        swap(ba,bb);
    }
    //take the max of the beginning points and the min of the endpoints then compare for intersection
    return max(aa,ba) <= min(bb,ab);
};

long double cross(pt a, pt b, pt c)
{
    //2d cross product, negative indicates ccw, positive cw, 0 collinear
    return (b.x-a.x) * (c.y-b.y) - (c.x-b.x) * (b.y-a.y);
}

bool check(seg a, seg b)
{
//    cout << nlineint(a.a.x,a.b.x,b.a.x,b.b.x) << " " << nlineint(a.a.y,a.b.y,b.a.y,b.b.y) << endl;
//    cout << cross(a.a,a.b,b.a) << cross(a.a,a.b,b.b) << cross(b.a,b.b,a.a) << cross(b.a,b.b,a.b) << endl;
    //check if they're x and y projections intersect
    //then check if they are collinear or are opposite signs
    return
        nlineint(a.a.x,a.b.x,b.a.x,b.b.x) &&
        nlineint(a.a.y,a.b.y,b.a.y,b.b.y) &&
        cross(a.a,a.b,b.a) * cross(a.a,a.b,b.b) <= 0 &&
        cross(b.a,b.b,a.a) * cross(b.a,b.b,a.b) <= 0;
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        seg a,b;
        cin >> a.a.x >> a.a.y >> a.b.x >> a.b.y >> b.a.x >> b.a.y >> b.b.x >> b.b.y;
        cout << (check(a,b) ? "YES" : "NO") << endl;
    }
}
