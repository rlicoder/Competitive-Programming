#include <bits/stdc++.h>

using namespace std;

const long long inf = 0;
struct Node {
	Node *l = 0, *r = 0;
	long long lo, hi, mset = inf, madd = 0, val = -inf;
	Node(long long lo,long long hi):lo(lo),hi(hi){} // Large long longerval of -inf
    long long f (long long a, long long b) { return a+b; }
	Node(vector<long long>& v, long long lo, long long hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			long long mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
			val = f(l->val, r->val);
		}
		else val = v[lo];
	}
	long long query(long long L, long long R) {
		if (R <= lo || hi <= L) return -inf;
		if (L <= lo && hi <= R) return val;
		push();
		return f(l->query(L, R), r->query(L, R));
	}
	void set(long long L, long long R, long long x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = val = x, madd = 0;
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = f(l->val, r->val);
		}
	}
	void add(long long L, long long R, long long x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			if (mset != inf) mset += x;
			else madd += x;
			val += x;
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			val = f(l->val, r->val);
		}
	}
	void push() {
		if (!l) {
			long long mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (mset != inf)
			l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
		else if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
	}
};

int main()
{
    long long n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    Node* tr = new Node(a, 0, n);
    for (long long i = 0; i < q; i++)
    {
        long long x;
        long long a,b,u;
        cin >> x;
        if (x == 1)
        {
            cin >> a >> b >> u;
            tr->add(a-1,b,u);
        }
        else if (x == 2)
        {
            cin >> a >> b >> u;
            tr->set(a-1,b,u);
        }
        else
        {
            cin >> a >> b;
            cout << tr->query(a-1,b) << endl;
        }
        for (int i = 0; i < n; i++)
        {
            cout << tr->query(i, i+1) << " ";
        }
        cout << endl;
    }
}
