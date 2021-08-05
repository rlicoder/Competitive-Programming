#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, a, b;
    cin >> n >> a >> b;
    long double ways = 0;
    vector<vector<long double>> dp(6*n+1, vector<long double>(n+1, 0));
    for (long long i = 1; i <= 6; i++)
    {
        dp[i][1] = 1 / 6.0;
    }
    //for each successive dice roll, the # of ways to reach i (the sum) is dp[i-{1,2,3,4,5,6}][j-1];
    for (long long j = 2; j <= n; j++)
    {
        for (long long i = 1; i <= 6*n; i++)
        {
            for (long long x = 1; x <= 6; x++)
            {
                if (i - x >= 0)
                {
                    dp[i][j] += dp[i-x][j-1] / (long double)6;
                }
            }
        }       
    }
    //for (long long i = 0; i < dp.size(); i++)
    //{
    //    for (long long j = 1; j < dp[i].size(); j++)
    //    {
    //        cout << dp[i][j] << " ";
    //    }
    //    cout << endl;
    //}
    //cout << endl;
    for (long long i = a; i <= b; i++)
    {
        ways += dp[i][n];
    }
    cout << fixed << setprecision(6);
    cout << ways << endl;
}
