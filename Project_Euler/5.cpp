#include <bits/stdc++.h>

using namespace std;

map<int,int> getPrimes(int n) {
    map<int,int> ret;
    ret[1]++;
    for (int i = 2; i <= sqrt(n); i++) {
        while (n % i == 0) {
            n /= i;
            ret[i]++;
        }
    }
    if (n != 1) {
        ret[n]++;
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
    map<int,int> factors;
    for (int i = 1; i <= 20; i++) {
        map<int,int> ans = getPrimes(i);
        for (auto it : ans) {
            if (factors[it.first] < it.second) {
                factors[it.first] = it.second;
            }
        }
    }
    int ans = 1;
    for (auto it : factors) {
        ans *= pow(it.first, it.second);
    }
    cout << ans << endl;
}


