#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n;
    cin >> n;
	//use determinants to solve for area. Keep in mind that you need to keep the negative values for determinants
	//at the end, take the abs
	//dont forget det(n-1,0) case
	//usually divide by two, but not necessary per problem desc
	//check out PatrickJMT video
    vector<pair<long long, long long>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    long long sum = 0;
    for (int i = 0; i < n-1; i++)
    {
        sum += (a[i].first * a[i+1].second) - (a[i+1].first * a[i].second);
    }
    sum += (a.back().first * a[0].second) - (a[0].first * a.back().second);
    cout << abs(sum) << endl;
}