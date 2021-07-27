#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

/*** Needs C++11 or C++14 ***/

/// Treap supporting duplicating values in set
/// Maximum value of treap * ADD must fit in long long

struct Treap{ /// hash = 96814
    int len;
    const int ADD = 1000010;
    const int MAXVAL = 1000000010;
    tr1::unordered_map <long long, int> mp; /// Change to int if only int in treap
    tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> T;

    Treap(){
        len = 0;
        T.clear(), mp.clear();
    }

    inline void clear(){
        len = 0;
        T.clear(), mp.clear();
    }

    inline void insert(long long x){
        len++, x += MAXVAL;
        int c = mp[x]++;
        T.insert((x * ADD) + c);
    }

    inline void erase(long long x){
        x += MAXVAL;
        int c = mp[x];
        if (c){
            c--, mp[x]--, len--;
            T.erase((x * ADD) + c);
        }
    }

    /// 1-based index, returns the K'th element in the treap, -1 if none exists
    inline long long kth(int k){
        if (k < 1 || k > len) return -1;
        auto it = T.find_by_order(--k);
        return ((*it) / ADD) - MAXVAL;
    }

    /// Count of value < x in treap
    inline int count(long long x){
        x += MAXVAL;
        int c = mp[--x];
        return (T.order_of_key((x * ADD) + c));
    }

    /// Number of elements in treap
    inline int size(){
        return len;
    }
};

using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    Treap ost;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (long long i = 0; i < k; i++)
    {
        ost.insert(a[i]);
    }
    long long l = 0;
    long long r = k;
    long long m = (k % 2 == 0) ? k/2-1 : k/2;
    while (r != n)
    {
        cout << ost.kth(m+1) << " ";
        ost.erase(a[l++]);
        ost.insert(a[r++]);
    }
    cout << ost.kth(m+1);
    cout << endl;
}
