#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

using namespace std;

struct Tree {
	typedef int T;
	static constexpr T unit = INT_MIN;
	T f(T a, T b) { return a + b; } // (any associative fn)
	vector<T> s; int n;
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    scanf("%i", &n);
    vector<int> a(n);
    Tree st(n, 0);
    for (int i = 0; i < n; i++)
    {
        scanf("%i", &a[i]);
        //st.update(i, 0);
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%i", &x);
        int l = 0;
        int r = x;
        int pos = x-1;
        while (st.query(l, r) >= 1)
        {
            int ol = pos + 1;
            pos += st.query(l, r);
            l = ol;
            r = min(pos + 1, n-1);
        }
        printf("%i ", a[pos]);
        //cout << a[pos] << " ";
        st.update(pos, 1);
    }
    //cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}
