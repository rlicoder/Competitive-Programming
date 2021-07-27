#include <bits/stdc++.h>

using namespace std;

int maxn = 2e6;

vector<int> ft(maxn, 0);

void add(long long i, long long cnt)
{
    while (i < ft.size())
    {
        ft[i] += cnt;
        i += i&(-i);
    }
};

long long rsq(long long a)
{
    long long sum = 0;
    while (a > 0)
    {
        sum += ft[a];
        a -= a&(-a);
    }
    return sum;
};

long long rsq(long long a, long long b)
{
    return rsq(b) - rsq((a == 1 ? 0 : a-1));
};

long long findbyk(long long k)
{
    long long sum = 0;
    int pos = 0;
    int i = int(log2(ft.size() - 1));
    while (i >= 0) {
        if (pos + (1 << i) < ft.size() && sum + ft[pos + (1 << i)] < k) {
            sum += ft[pos + (1 << i)];
            pos += (1 << i);
        }
        i--;
    }
    return pos + 1;
};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        add(x, 1);
    }
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        if (x < 0)
        {
            add(findbyk(abs(x)), -1);
        }
        else if (x >= 1)
        {
            add(x, 1);
        }
    }
    if (findbyk(1) == maxn)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << findbyk(1) << endl;
    }
}
