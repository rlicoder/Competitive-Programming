#include <bits/stdc++.h>

using namespace std;

bool comp(pair<string,int> a, pair<string,int> b)
{
    return a.second < b.second;
}

int main()
{
    int n;
    cin >> n;
    vector<int> order;
    vector<pair<string,int>> b;
    for(int i = 0; i < (1 << n); i++)
    {
        order.push_back(i ^ (i/2));
    }
    for (int i = 0; i < (1<<n); i++)
    {
        bitset<(16)>a(i);
        string str = a.to_string();
        str.erase(0, 16-n);
        b.push_back({str,i});
    }
    sort(b.begin(), b.end(), comp);
    for (int i = 0; i < (1 << n); i++)
    {
        cout << b[order[i]].first << endl;
    }
}
