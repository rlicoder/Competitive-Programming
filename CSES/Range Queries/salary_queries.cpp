#include <bits/stdc++.h>

using namespace std;

struct Vertex {
    int left, right;
    int sum = 0;
    Vertex *left_child = nullptr, *right_child = nullptr;

    Vertex(int lb, int rb) {
        left = lb;
        right = rb;
    }

    void extend() {
        if (!left_child && left + 1 < right) {
            int t = (left + right) / 2;
            left_child = new Vertex(left, t);
            right_child = new Vertex(t, right);
        }
    }

    void add(int k, int x) {
        extend();
        sum += x;
        if (left_child) {
            if (k < left_child->right)
                left_child->add(k, x);
            else
                right_child->add(k, x);
        }
    }

    int get_sum(int lq, int rq) {
        if (lq <= left && right <= rq)
            return sum;
        if (max(left, lq) >= min(right, rq))
            return 0;
        extend();
        return left_child->get_sum(lq, rq) + right_child->get_sum(lq, rq);
    }
};

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    map<int,int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        m[a[i]]++;
    }
    Vertex st(0, 1e9);
    for (auto it : m)
    {
        st.add(it.first, it.second);
    }
    for (int i = 0; i < q; i++)
    {
        char x;
        cin >> x;
        if (x == '?')
        {
            int x,y;
            cin >> x >> y;
            cout << st.get_sum(x, y+1) << endl;
        }
        else
        {
            int x,y;
            cin >> x >> y;
            int old = a[x-1];
            m[old]--;
            st.add(old, -1);
            m[y]++;
            st.add(y, 1);
        }
    }

}
