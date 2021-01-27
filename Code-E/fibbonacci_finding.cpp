#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    vector<long long> dp(70+1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i < dp.size(); i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    while (tc--)
    {
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }
}
