#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> a, b;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x % 2 == 0)
            {
                a.push_back(x);
            }
            else
            {
                b.push_back(x);
            }
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        long long ax,bx;
        ax=bx=0;
        bool aturn = 1;
        while (a.size() > 0 || b.size() > 0)
        {
            if (aturn)
            {
                if (a.size() && b.size())
                {
                    if (a.back() > b.back())
                    {
                        ax += a.back();
                        a.pop_back();
                    }
                    else
                    {
                        b.pop_back();
                    }
                }
                else if (a.size() && !b.size())
                {
                    ax += a.back();
                    a.pop_back();
                }
                else
                {
                    b.pop_back();
                }
            }
            else
            {
                if (a.size() && b.size())
                {
                    if (b.back() > a.back())
                    {
                        bx += b.back();
                        b.pop_back();
                    }
                    else
                    {
                        a.pop_back();
                    }
                }
                else if (b.size() && !a.size())
                {
                    bx += b.back();
                    b.pop_back();
                }
                else
                {
                    a.pop_back();
                }
            }
            aturn = !aturn;
        }
        //cout << ax << " " << bx << endl;
        if (ax > bx)
        {
            cout << "Alice" << endl;
        }
        else if (bx > ax)
        {
            cout << "Bob" << endl;
        }
        else
        {
            cout << "Tie" << endl;
        }

    }
}
