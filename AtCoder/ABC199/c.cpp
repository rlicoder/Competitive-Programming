#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    int q;
    cin >> q;
    int count = 0;
    for (int i = 0; i < q; i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        switch (x)
        {
            case 1:
                {
                    if (count % 2 == 1)
                    {
                        string a = str;
                        str = "";
                        str += a.substr(n, n);
                        str += a.substr(0, n);
                    }
                    y--;z--;
                    swap(str[y],str[z]);
                    count = 0;
                    break;
                }
            case 2:
                {
                    count++;
                    break;
                }
        }
    }
    if (count % 2 == 1)
    {
        string a = str;
        str = "";
        str += a.substr(n, n);
        str += a.substr(0, n);
    }
    cout << str << endl;
}
