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
                    y--;z--;
                    //0 1 2 3 4 5 6 7
                    //0 1 2 3 4 5 6 7
                    if (count % 2 == 1)
                    {
                        swap(str[(y>=n ? y-n : y+n)], str[(z>=n ? z-n : z+n)]);
                    }
                    else
                    {
                        swap(str[y],str[z]);
                    }
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
