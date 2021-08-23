#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag,
tree_order_statistics_node_update> T;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < k; i++){
        cin >> a[i];
        T.insert({a[i],i});
    }
    int med = (k-1) / 2;
    cout << (*T.find_by_order(med)).first << " ";
    for (int i = k; i < n; i++)
    {
        cin >> a[i];
        T.erase({a[i-k], i-k});
        T.insert({a[i], i});
        cout << (*T.find_by_order(med)).first << " ";
    }
}
