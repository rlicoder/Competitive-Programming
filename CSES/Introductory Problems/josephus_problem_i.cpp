#include <bits/stdc++.h>

using namespace std;

int josephus(int n, int k) {
    int res = 0;
    for (int i = 1; i <= n; ++i)
      res = (res + k) % i;
    return res + 1;
}

int main()
{
    int n;
    cin >> n;
    int k = 2;
	for (int i = k, count = 0; count < n; count++, i+=k)
    {
        cout << josephus(n, i) << " ";
    }
    cout << endl;

        


}



