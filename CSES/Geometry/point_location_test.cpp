#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
		//use the cross product between two vectors
        pair<long long,long long> x,y,t;
        cin >> x.first >> x.second >> t.first >> t.second >> y.first >> y.second;
        pair<long long,long long> a,b;
        a.first = t.first - x.first;
        a.second = t.second - x.second;
        b.first = y.first - x.first;
        b.second = y.second - x.second;
        if ((a.first*b.second) - (a.second*b.first) < 0)
        {
            cout << "RIGHT";
        }
        else if ((a.first*b.second) - (a.second*b.first) > 0)
        {
            cout << "LEFT";
        }
        else
        {
            cout << "TOUCH";
        }
        cout << endl;
    }
}