#include <bits/stdc++.h>

using namespace std;

int main()
{
    long double r, h1, h2;
    while (cin >> r >> h1 >> h2)
    {
        //notice that the ans cannot be > r
        //also notice that if it works for a dist x, is can work for any dist < x
        //employ binary search
        //instead of doing math lmao
        function<bool(long double, long double)> valid = [&] (long double mid, long double r)
        {
            //tangent of theta = mid / radius?
            //find abs diff in y from end of adj to intersect of hyp
            //define center points
            long double a = 0;
            long double b = 0;

            long double x = a + r * cos(mid);
            long double y = b + r * sin(mid);

            if (r - y)
        };
        long double l = 0;
        long double r = r;
        int count = 0;
        long double ans;
        while (count < 100)
        {
            count++;
            long double mid = (l + (r-l)) / 2;
            if (valid(mid, r))
            {
                ans = mid;
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        cout << ans;
    }
}
