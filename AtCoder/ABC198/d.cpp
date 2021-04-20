#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s1,s2,s3;
    cin >> s1 >> s2 >> s3;
    set<char> s;
    for (char c : s1)
    {
        s.insert(c);
    }
    for (char c : s2)
    {
        s.insert(c);
    }
    for (char c : s3)
    {
        s.insert(c);
    }
    bool found = false;
    if (s.size() > 10)
    {
        cout << "UNSOLVABLE" << endl;
    }
    else
    {
        string base = "0123456789";
        sort(base.begin(), base.end());
        do
        {
            string a = base.substr(0,(int)s.size());
            int i = 0;
            map<char,char> m;
            for (auto c : s)
            {
                m[c] = a[i];
                i++;
            }
            if (m[s1[0]] == '0' || m[s2[0]] == '0' || m[s3[0]] == '0')
            {
                continue;
            }
            else
            {
                string n1 = s1;
                string n2 = s2;
                string n3 = s3;
                for (int i = 0; i < n1.size(); i++)
                {
                    n1[i] = m[s1[i]];
                }
                for (int i = 0; i < n2.size(); i++)
                {
                    n2[i] = m[s2[i]];
                }
                for (int i = 0; i < n3.size(); i++)
                {
                    n3[i] = m[s3[i]];
                }
                if (stol(n1) + stol(n2) == stol(n3))
                {
                    cout << n1 << endl;
                    cout << n2 << endl;
                    cout << n3 << endl;
                    found = true;
                    break;
                }
            }
        }
        while (next_permutation(base.begin(), base.end()) && !found);
        if (!found)
        {
            cout << "UNSOLVABLE" << endl;
        }
    }
}
