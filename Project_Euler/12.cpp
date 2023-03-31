#include <bits/stdc++.h>

using namespace std;

int main() {
    int cur = 1;
    while (true) {
        long long val = cur * (cur + 1) / 2;
        int numDivisors = 0;
        set<int> divisors;
        for (int i = 1; i <= sqrt(val); i++) {
            if (val % i == 0) {
                divisors.insert(i);
                divisors.insert(val/i);
            }
        }
        if (divisors.size() > 500) {
            cout << val << endl;
            exit(1);
        }
        cur++;
    }
}
