#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;

int main()
{
    long long n;
    cin >> n;
    n--;
    long long x = 0;
    long long y = 1;
    vector<vector<long long>> a { {0,1}, {1,1} };
    //                                       \
    //coded this all myself cause im not bad B^)
    //                                       /
    function<vector<vector<long long>>(vector<vector<long long>>, vector<vector<long long>>)> matmul = [&] (vector<vector<long long>> a, vector<vector<long long>> b)
    {
        vector<vector<long long>> ret(a.size(), vector<long long>(b[0].size(), 0));
        for (long long i = 0; i < ret.size(); i++)
        {
            for (long long j = 0; j < ret[0].size(); j++)
            {
                for (long long x = 0, y = 0; x < a[i].size(); x++,y++)
                {
                    ret[i][j] += a[i][x] * b[y][j];
                    ret[i][j] %= MOD;
                }
            }
        }
        return ret;
    };
    function<vector<vector<long long>>(vector<vector<long long>>, long long)> matbinexpo = [&] (vector<vector<long long>> a, long long n)
    {
        if (n == 0)
        {
            vector<vector<long long>> identity (a.size(), vector<long long>(a[0].size(), 0));
            for (long long i = 0, j = 0; i < a.size(); i++, j++)
            {
                identity[i][j] = 1;
            }
            return identity;
        }
        vector<vector<long long>> res = matbinexpo(a, n / 2);
        if (n % 2 == 0)
        {
            return matmul(res, res);
        }
        else
        {
            return matmul(a, matmul(res, res));
        }
    };
    vector<vector<long long>> res = matbinexpo(a, n);
    vector<vector<long long>> b (2, vector<long long>(1));
    b[0][0] = x;
    b[1][0] = y;
    if (n == -1)
    {
        cout << x << endl;
    }
    else
        cout << matmul(res, b)[1][0] << endl;
}
