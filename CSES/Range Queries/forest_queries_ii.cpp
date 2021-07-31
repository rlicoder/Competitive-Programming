#include <bits/stdc++.h>

using namespace std;

struct FT {
	vector<long long> s;
	FT(int n) : s(n) {}
	void update(int pos, long long dif) { // a[pos] += dif
		for (; pos < s.size(); pos |= pos + 1) s[pos] += dif;
	}
	long long query(int pos) { // sum of values in [0, pos)
		long long res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
	int lower_bound(long long sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= s.size() && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};

struct FT2 {
	vector<vector<int>> ys; vector<FT> ft;
	FT2(int limx) : ys(limx) {}
	void fakeUpdate(int x, int y) {
		for (; x < ys.size(); x |= x + 1) ys[x].push_back(y);
	}
	void init() {
		for (vector<int>& v : ys) sort(v.begin(), v.end()), ft.emplace_back(v.size());
	}
	int ind(int x, int y) {
		return (int)(lower_bound(ys[x].begin(), ys[x].end(), y) - ys[x].begin()); }
	void update(int x, int y, long long dif) {
		for (; x < ys.size(); x |= x + 1)
			ft[x].update(ind(x, y), dif);
	}
	long long query(int x, int y) {
		long long sum = 0;
		for (; x; x &= x - 1)
			sum += ft[x-1].query(ind(x-1, y));
		return sum;
	}
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> a(n, vector<int>(n));
    FT2 ft(n+1);
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            //ft.fakeUpdate(i,j);
        }
    }
    ft.init();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char x;
            cin >> x;
            if (x == '*')
            {
                a[i][j] = 1;
                ft.update(i,j,1);
            }
            else
            {
                a[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int y, x;
            cin >> y >> x;
            y--;x--;
            if (a[y][x] == 1)
            {
                a[y][x] = 0;
                ft.update(y,x,-1);
            }
            else
            {
                a[y][x] = 1;
                ft.update(y,x,1);
            }
        }
        else
        {
            int y1,x1,y2,x2;
            cin >> y1 >> x1 >> y2 >> x2;
            cout << ft.query(y2,x2) - ft.query(y2,x1-1) - ft.query(y1-1, x2) + ft.query(y1-1,x1-1) << endl;
        }
    }
}
