#include <bits/stdc++.h>

using namespace std;

int main() {
    for (int a = 1; a <= 998; a++) {
        for (int b = a+1; b <= 1000-a; b++) {
            for (int c = b+1; c <= 1000-a-b; c++) {
                if (a+b+c == 1000 && (a*a+b*b == c*c)) {
                    cout << a << " "  << b << " " <<  c << endl;
                    cout << a * b * c << endl;
                    exit(1);
                }
            }
        }
    }
}
