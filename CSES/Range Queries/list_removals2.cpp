#include <bits/stdc++.h>

using namespace std;

struct Tree {
	typedef int T;
	static constexpr T unit = 0;
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
    int n;
    cin >> n;
    vector<int> a(n);
    Tree st(n, 1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        st.update(i, 1);
    }
    function<int(int, int, int)> find_pos = [&] (int l, int r, int x)
    {
        int mid = (l + r) / 2;
        //cout << "currently at range " << l << " - " << r << " which contains: " << st.query(l, r+1) << " numbers" << endl;
        if (l == r)
        {
            return l;
        }
        else if (st.query(l, r+1) >= x)
        {
            if (st.query(l, mid+1) >= x)
            {
                return find_pos(l, mid, x);
            }
            else
            {
                return find_pos(mid+1 , r, x - st.query(l, mid+1));
            }
        }
        else
        {
            return (int)1e9;
        }
    };
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        //cout << "trying to find: " << x << endl;
        int pos = find_pos(0, n-1, x);
        //cout << "position is: " << pos << endl;
        cout << a[pos] << " ";
        st.update(pos, 0);
    }
}

