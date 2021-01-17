#include <bits/stdc++.h>
 
using namespace std;
 
 //cross product, negative indicates right, positive indicates left, zero means they're collinear
long double cross (pair<int,int> a, pair<int,int> b, pair<int,int> c)
{
    pair<long double, long double> fi = {(long double)(b.first - a.first), (long double)(b.second - a.second)};
    pair<long double, long double> se = {(long double)(c.first - b.first), (long double)(c.second - b.second)};
 //this can be a one liner. my peanut brain cant handle thinking about it though.
    return (fi.first * se.second) - (fi.second * se.first);
}
 
int main()
{
    int n;
    cin >> n;
	//using a pair here but the point struct is much easier
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    //sort the points by the leftmost
    sort(a.begin(), a.end());
    vector<pair<int,int>> lower;
    //the start is the leftmost point, the end is the rightmost point
    pair<int,int> start = {a[0].first, a[0].second};
    pair<int,int> end = a.back();
    //the lower hull starts with the leftmost point
    lower.push_back(start);
 
	//left turn is for the lower hull
    for (int i = 1; i < n; i++)
    {
		//idea is to push the last point, then check if you made a left turn
        lower.push_back(a[i]);
        if (lower.size() >= 3)
        {
			//only works if there are at least 3 points
			//declare the last three points
            pair<int,int> last;
            pair<int,int> second;
            pair<int,int> third;
            last = lower.back();
            second = *(lower.end()-2);
            third = *(lower.end()-3);
			
			//check if its a left turn based on the cross product
            while (cross(third, second, last) < 0 && lower.size() >= 3)
            {
				//erase, then declare the last 3 pts.
                lower.erase(lower.end()-2);
                last = lower.back();
                second = *(lower.end()-2);
                third = *(lower.end()-3);
            }
        }
    }
    
	//upper hull, same starting point, you just need the same thing but right turns
    vector<pair<int,int>> upper;
	//push the starting leftmost point
    upper.push_back(start);
 
    for (int i = 1; i < n; i++)
    {
		//literally the same as before
        upper.push_back({a[i].first, a[i].second});
        if (upper.size() >= 3)
        {
            pair<int,int> last;
            pair<int,int> second;
            pair<int,int> third;
            last = upper.back();
            second = *(upper.end()-2);
            third = *(upper.end()-3);
            while (cross(third, second, last) > 0 && upper.size() >= 3)
            {
                upper.erase(upper.end()-2);
                last = upper.back();
                second = *(upper.end()-2);
                third = *(upper.end()-3);
            }
        }
 
    }
	//push the ending point, rightmost point.
	//not sure if this is necessary...just to be safe i guess
    upper.push_back(end);
    set<pair<int,int>> s (upper.begin(), upper.end());
    for (auto it : lower)
    {
        s.insert(it);
    }
    cout << s.size() << endl;
    for (auto it : s)
    {
        cout << it.first << " " << it.second << endl;
    }
}