#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<array<3,int>> a;
    for (int i = 0; i < n; i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        a.push_back({x,y,z});
    }
    function<bool(array<3,int>, array<3,int>)> comp = [&] (array<3,int> a, array<3,int> b)
    {
        
    };
}
