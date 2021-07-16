#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> b(1e5 + log2(1e5), 0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        b[x]++;
        if (b[x] == 2)
        {
            b[x] = 0;
            b[x+1]++;
            for (int j = x+1; j < b.size(); j++)
            {
                if (b[j] == 2)
                {
                    b[j] = 0;
                    b[j+1]++;
                }
                else
                {
                    break;
                }
            }
        }
    }
    int count = 0;
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i] == 1)
        {
            count++;
        }
    }
    cout << (count <= 2 && n >= 2 ? "Y" : "N") << endl;
}
