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
        if (n == 2)
        {
            cout << 2 << endl;
            cout << "1 2";
            cout << endl;
            continue;
        }
        
        else if (n == 3)
        {
            cout << 2 << endl;
            cout << "1 3" << endl;
            cout << "2 2" << endl;
            continue;
        }
        multiset<int> a;
        for (int i = 1; i <= n; i++)
        {
            a.insert(i);
        }
        cout << 2 << endl;
        while (a.size() > 3)
        {
            auto it = a.end();
            it--;

        int x = *(it);
        it--;
        
        int y = *(it);
        cout << x << " " << y << endl;
        a.erase(x);
        a.erase(y);
        a.insert((x+y+1)/2);

        }
        cout << 2 << " " << 4 << endl;
        cout << "1 3" << endl;

    }


}
