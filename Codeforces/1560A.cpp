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
        int l = 1;
        int r = 2000;
        while (l <= r)
        {
            int mid = (l+r)/2;
            int k = 0;
            k += mid / 3;
            if (mid % 3 == 0)
            {
                k--;
            }
            k += (mid-3) / 10;
            k -= (mid-3) / 10 / 3;
            if (mid - k == n)
            {
                cout << mid << endl;
                break;
            }
            else if (mid-k > n)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
    }
}
