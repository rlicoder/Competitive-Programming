#include <bits/stdc++.h>
#include "../../CP-Book-Code/pt.hpp"

using namespace std;

int main()
{
    long double x1, y1, x2, y2, x3, y3;
    //create perpendicular bisectors B)
    while (cin >> x1)
    {
        cin >> y1 >> x2 >> y2 >> x3 >> y3;
        long double numerator = y2-y1;
        long double denominator = x2-x1;
        long double m1 = -denominator / numerator;
        pt<long double> midpoint1 = {(x2+x1)/2, (y2+y1)/2};

        numerator = y3-y2;
        denominator = x3-x2;
        long double m2 = -denominator / numerator;
        pt<long double> midpoint2 = {(x3+x2)/2, (y3+y2)/2};
        pt<long double> c;
        c.x = ( (-m1*midpoint1.x) + (m2*midpoint2.x) + midpoint1.y - midpoint2.y ) / (m2 - m1);
        c.y = m1 * c.x - m1 * midpoint1.x + midpoint1.y;
        long double rad = sqrt(pow(c.x-x1,2) + pow(c.y-y1,2));
        rad *= 2;
    }
}
