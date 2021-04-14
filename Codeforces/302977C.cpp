#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a,b,c,ab,ac,bc,abc;
    for (int i = 0; i < n; i++)
    {
        int x;
        string str;
        cin >> x >> str;
        sort(str.begin(), str.end());
        if (str.size() == 1)
        {
            if (str[0] == 'A')
            {
                a.push_back(x);
            }
            else if (str[0] == 'B')
            {
                b.push_back(x);
            }
            else
            {
                c.push_back(x);
            }
        }
        else if (str.size() == 2)
        {
            if (str == "AB")
            {
                ab.push_back(x);
            }
            else if (str == "AC")
            {
                ac.push_back(x);
            }
            else if (str == "BC")
            {
                bc.push_back(x);
            }
        }
        else
        {
            abc.push_back(x);
        }
    }
    int mina,minb,minc,minab,minbc,minac,minabc;
    mina=minb=minc=minab=minbc=minac=minabc=0;

    mina = (min_element(a.begin(), a.end()) != a.end() ? *min_element(a.begin(), a.end()) : (int)1e8);
    minb = (min_element(b.begin(), b.end()) != b.end() ? *min_element(b.begin(), b.end()) : (int)1e8);
    minc = (min_element(c.begin(), c.end()) != c.end() ? *min_element(c.begin(), c.end()) : (int)1e8);
    minac = (min_element(ac.begin(), ac.end()) != ac.end() ? *min_element(ac.begin(), ac.end()) : (int)1e8);
    minab = (min_element(ab.begin(), ab.end()) != ab.end() ? *min_element(ab.begin(), ab.end()) : (int)1e8);
    minbc = (min_element(bc.begin(), bc.end()) != bc.end() ? *min_element(bc.begin(), bc.end()) : (int)1e8);
    minabc = (min_element(abc.begin(), abc.end()) != abc.end() ? *min_element(abc.begin(), abc.end()) : (int)1e8);
    int ans =  min(min(min(mina+minb+minc, min(minac + minb, minab + minc)),min(minbc+mina, minabc)), min(min(minab + minbc, minab + minac), min(min(minac + minab, minac + minbc), minac + minabc)));
    if (ans == (int)1e8)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
}



