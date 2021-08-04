#include <bits/stdc++.h>

using namespace std;

struct Tree {
	typedef int T;
	static constexpr T unit = INT_MIN;
	T f(T a, T b) { return max(a, b); } // (any associative fn)
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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    Tree st(a.size(), 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        st.update(i, a[i]);
    }
    function<int(int,int,int)> find_least = [&] (int l, int r, int x)
    {
        int mid = (l + r) / 2;
        if (l == r && st.query(l,r+1) >= x)
        {
            return l;
        }
        else if (st.query(l, r+1) >= x)
        {
            if (st.query(l, mid+1) >= x)
            {
                return find_least(l, mid, x);
            }
            else
            {
                return find_least(mid+1, r, x);
            }
        }
        else
        {
            return (int) 1e9;
        }
    };
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        int pos = find_least(0,n-1, x);
        //cout << "pos is: " << pos << endl;
        if (pos == 1e9)
        {
            cout << 0 << " ";
        }
        else
        {
            cout << pos + 1 << " ";
            a[pos] -= x;
            st.update(pos,a[pos]);
        }
    }
}
