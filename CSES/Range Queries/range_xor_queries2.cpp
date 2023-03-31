#include <bits/stdc++.h>

using namespace std;

struct Tree {
	typedef int T;
	static constexpr T unit = INT_MIN;
	T f(T a, T b) { return a ^ b; } // (any associative fn)
	vector<T> s; int n;
    //Tree(size, set everything equal to)
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    Tree segtree(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        segtree.update(i, a[i]);
    }
    for (int i = 0; i < q; i++)
    {
        int x,y;
        cin >> x >> y;
        cout << segtree.query(x-1, y) << endl;

    }
}