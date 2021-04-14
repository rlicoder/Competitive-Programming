#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<long long> dp(9000+1, -1);

    int i = 1;
    int j = 2;
    int k = 1;
    while (i < dp.size())
    {
        dp[i] = k++;
        i+=j;
        j++;
    }
    k = 0;
    for (int i = 0; i < dp.size(); i++)
    {
        dp[i] == -1 ? dp[i] = k : k++;
    }

    cout << dp[n] << endl;
    int x = n;

    for (int i = 0; i < dp[n]; i++)
    {
        if (i+1 == dp[n])
        {
            cout << x << endl;
            break;
        }
        cout << i+1 << " ";
        x-=i+1;
    }
}

    


    
