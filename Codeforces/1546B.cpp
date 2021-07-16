#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<string> original(n);
        map<char,int> o;
        map<string,string> ans;
        for (int i = 0; i < n; i++)
        {
            cin >> original[i];
            for (int j = 0; j < m; j++)
            {
                o[original[i][j]]++;
            }
            string str = original[i];
            sort(str.begin(), str.end());
            ans[str] = original[i];
        }
        vector<string> newstr(n-1);
        map<char,int> f;
        for (int i = 0; i < n-1; i++)
        {
            cin >> newstr[i];
            for (int j = 0; j < m; j++)
            {
                f[newstr[i][j]]++;
            }
        }
        for (auto [x,y] : f)
        {
            o[x] -= y;
            if (o[x] == 0)
            {
                o.erase(x);
            }
        }
        string rle = "";
        for (auto it : o)
        {
            string s(it.second, it.first);
            rle += s;
            //cout << it.first << " " << it.second << endl;
        }
        //yes, I know this TLE's n*m can be up to 1e10, please stop bothering me
        cout << ans[rle] << endl;
    }
}
