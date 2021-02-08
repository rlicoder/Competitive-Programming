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

ostream& operator<< (ostream& out, pt& a)
{
    out << a.x << " " << a.y;
    return out;
}
ostream& operator<< (ostream& out, seg& a)
{
    out << a.a.x << " " << a.a.y << " " << a.b.x << " " << a.b.y;
    return out;
}

long long dist (pt a, pt b)
{
    return (b.x-a.x) * (b.x-a.x) + (b.y-a.y) * (b.y-a.y);
}

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

bool inside(pt a, seg b)
{
    seg ab;
    ab.a = b.a;
    ab.b = a;
    //cout << a << " " << b << endl;
    //cout << cross(b.a,a,b.b) << " " << dist(a,b.a) << " " << dist(b.b,a) << " " << dist(b.a,b.b) << endl;
    return cross(b.a,a,b.b) == 0 && sqrt(dist(a, b.a)) + sqrt(dist(b.b, a)) == sqrt(dist(b.a,b.b));
};


int main()
{
    int n,m;
    cin >> n >> m;
    vector<seg> a(n);
    vector<pt> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i].x >> b[i].y;
    }
    for (int i = 0; i < n; i++)
    {
        a[i].a = b[i];
        a[i].b = b[i+1==n?0:i+1];
    }
    for (int i = 0; i < m; i++)
    {
        long long x,y;
        int hrcount, hlcount, vdcount, vucount;
        hrcount = hlcount = vdcount = vucount = 0;
        cin >> x >> y;
        pt s; s.x = x; s.y =y;
        seg hr;
        hr.a.x = -34987263; hr.a.y = -102931047; hr.b.x = x; hr.b.y = y;
        //cout << "checking " << hr << endl;
        bool boundary = false;
        for (int j = 0; j < (int)a.size(); j++)
        {
            //cout << a[j] << endl;
            if (check(hr, a[j]))
            {
                hrcount++;
            }
            if (inside(s, a[j]))
            {
                //cout << s << endl;
                //cout << a[j] << endl;
                boundary = true;
                break;
            }
        }
        if (boundary)
        {
            cout << "BOUNDARY";
        }
        else if (hrcount % 2)
        {
            cout << "INSIDE";
        }
        else
        {
            cout << "OUTSIDE";
        }
        cout << endl;
    }
}
