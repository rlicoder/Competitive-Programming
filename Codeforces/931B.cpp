#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a,b;
    cin >> a >> b;
    vector<int> c(n);
    iota(c.begin(), c.end(), 1);
    vector<int> d = c;
    int j = 1;
    vector<int> e = d;
    do
    {
        d = e;
        for (int i = 0; i < d.size(); i+=2)
        {
            if ((d[i] == a && d[i+1] == b) || (d[i] == b && d[i+1] == a))
            {
                if (j == floor((log2(n))))
                {
                    cout << "Final!" << endl;
                }
                else
                {
                    cout << j << endl;
                }
                exit(0);
            }
            if (d[i] == a || d[i] == b)
            {
                e.push_back(d[i]);
            }
            else if (d[i+1] == a || d[i+1] == b)
            {
                e.push_back(d[i+1]);
            }
            else
            {
                e.push_back(d[i]);
            }
        }
        j++;
    }
    while(e.size());
}
