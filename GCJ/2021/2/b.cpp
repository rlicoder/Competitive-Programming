#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    for (int i = 1; i <= tc; i++)
    {
        int n;
        cin >> n;
        int ans = 0;
        function <int(int,int)> recurse = [&] (int x, int y)
        {
            int ans = 0;
            //you selected the final polygon
            if (x == 0)
            {
                return -1;
            }
            bool found = false;
            //iterate from 3 sided polygon towards how many sides are left
            for (int i = 3; i < x-y; i++)
            {
                //if it is a proper divisor, try it
                if ((x-y) % i == 0)
                {
                    found = true;
                    int add = recurse(x-y, i);
                    if (add == -123456789)
                    {
                        ans--;
                    }
                    ans += max(1, add);
                }
            }
            //there were no proper divisors and you are left with extra sides
            if (!found && x-y > 0)
            {
                return -123456789;
            }
            return ans;
        };
        //pick and initial polygon
        for (int i = 3; i <= n; i++)
        {
            ans = max(ans, recurse(n, i));
        }
        cout << "Case #" << i << ans << endl;
    }
}
