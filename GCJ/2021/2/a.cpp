#include <bits/stdc++.h>

using namespace std;

/*proof
 * #include <bits/stdc++.h>
 *
 * using namespace std;
 *
 * int main()
 * {
 *     int n = 100;
 *     for (int i = 1; i <= n; i++)
 *     {
 *         int sum = 0;
 *         for (int j = i; j <= n; j++)
 *         {
 *             sum += 1e8/(n-j);
 *         }
 *         cout << (sum < (int)6e8) << endl;
 *      }
 *  }
*/
int main()
{
    int t, n;
    cin >> t >> n;
    while (t--)
    {
        function <void(int,int)> q = [&] (int x, int j)
        {
            cout << "M " << x << " " << j << endl;
        };
        function <void(int,int)> s = [&] (int x, int j)
        {
            cout << "S " << x << " " << j << endl;
        };
        for (int i = 1; i < n; i++)
        {
            int res;
            //cout << "M " << i << " " << n << endl;
            q(i, n);
            cin >> res;
            if (res != i)
            {
                //cout << "S " << i << " " << res << endl;
                s(i, res);
                cin >> res;
                if (res == -1)
                {
                    exit(0);
                }
            }
        }
        cout << "D" << endl;
        int x;
        cin >> x;
        if (x == -1)
        {
            break;
        }
    }
    return 0;
}
