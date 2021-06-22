#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n, k;
        cin >> n >> k;
        string a,b;
        cin >> a >> b;
        //adjacent swaps probably means you can do all perms/comb
        //you cannot go backwards in alphabet
        //maybe count how many "letter upgrades" you need, and then check if it is a multiple of k;

        int dif = 0;
        for (int i = 0; i < a.size(); i++)
        {
            int inc = b[i] - a[i];
            inc = (inc < 0 ? 0 : inc);
            dif += b[i] - a[i];
        }
        cout << dif << endl;
        if (dif % k == 0)
        {
            cout << "Yes";
        }
        else
        {
            cout << "No";
        }
        cout << endl;

    }
}
