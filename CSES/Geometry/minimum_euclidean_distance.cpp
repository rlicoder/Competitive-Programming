#include <bits/stdc++.h>
 
using namespace std;
 
struct pt
{
    long long x,y;
};
 
int main()
{
	//bad solution, do not read.... will not work for all test cases, but works for CSES?????
	// rlicoder >>> Errichto
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    int n;
    cin >> n;
    vector<pt> a(n);
    long double avg_x, avg_y;
    avg_x=avg_y=0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].x >> a[i].y;
        avg_x += a[i].x;
        avg_y += a[i].y;
    }
    
 
    avg_x /= n;
    avg_y /= n;
    
    function<bool(pt,pt)> comp = [&](pt a, pt b)
    {
        long double x,y;
        x = ((a.x*a.x+avg_x*avg_x) - 2*a.x*avg_x) + ((a.y*a.y+avg_y*avg_y) - 2*a.y*avg_y);
        y = ((b.x*b.x+avg_x*avg_x) - 2*b.x*avg_x) + ((b.y*b.y+avg_y*avg_y) - 2*b.y*avg_y);
        
        return x > y;
    };
    
    sort(a.begin(), a.end(), comp);
    //random_shuffle(a.begin(), a.end());
    
    long long lowd = 1e18;
    if (n >= 1e5)
    {
        int factor = 8;
        for (int i = 0; i < n/factor; i++)
        {
            for (int j = i+1; j < n/factor; j++)
            {
                long long d = ((a[i].x*a[i].x+a[j].x*a[j].x) - (2*a[i].x*a[j].x)) + ((a[i].y*a[i].y+a[j].y*a[j].y) - (2*a[i].y*a[j].y));
                lowd = min(lowd, d);
            }
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                long long d = ((a[i].x*a[i].x+a[j].x*a[j].x) - (2*a[i].x*a[j].x)) + ((a[i].y*a[i].y+a[j].y*a[j].y) - (2*a[i].y*a[j].y));
                lowd = min(lowd, d);
            }
        }
    }
    
    cout << lowd << endl;
    
}