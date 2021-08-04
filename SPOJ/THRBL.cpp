#include <bits/stdc++.h>

using namespace std;

template <typename T, class F = function<T(const T&, const T&)>>
class SparseTable {
 public:
  int n;
  vector<vector<T>> mat;
  F func;
 
  SparseTable(const vector<T>& a, const F& f) : func(f) {
    n = static_cast<int>(a.size());
    int max_log = 32 - __builtin_clz(n);
    mat.resize(max_log);
    mat[0] = a;
    for (int j = 1; j < max_log; j++) {
      mat[j].resize(n - (1 << j) + 1);
      for (int i = 0; i <= n - (1 << j); i++) {
        mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
      }
    }
  }
 
  T get(int from, int to) const {
    assert(0 <= from && from <= to && to <= n - 1);
    int lg = 32 - __builtin_clz(to - from + 1) - 1;
    return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
  }
};

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    SparseTable<int> st(a, [&] (int i, int j) { return max(i,j); });
    int ans = 0;
    for (int i = 0; i < q; i++)
    {
        int x,y;
        cin >> x >> y;
        bool badinput = false;
        if (x > y)
        {
            badinput = true;
            swap(x,y);
        }
        x--;y--;
        int ox = x;
        int oy = y;
        if (abs(x-y) < 2)
        {
            ans++;
        }
        else
        {
            x++;y--;
            if (st.get(x,y) <= a[badinput ? oy : ox])
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
