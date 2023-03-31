#include <bits/stdc++.h>

using namespace std;

vector<int> getPrimes(int n) {
    vector<int> ret;
    ret.push_back(1);
    for (int i = 2; i <= sqrt(n); i++) {
        while (n % i == 0) {
            n /= i;
            ret.push_back(i);
        }
    }
    if (n != 1) {
        ret.push_back(n);
    }
    return ret;
}

int main()
{
    //for (int i = 0; i <= 20; i++) {
    //    vector<int> ans = getPrimes(i);
    //    cout << i << ": ";
    //    for (auto it : ans) {
    //        cout << it << " ";
    //    }
    //    cout << endl;
    //}
    int cur = 2;
    long long ans = 0;
    while (cur < 2e6) {
        if (getPrimes(cur).size() == 2) {
            ans += cur;
        }
        cur++;
    }
    cout << ans << endl;
}


