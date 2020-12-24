#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
const ll mod = 1000000007;
 
using namespace std;
 
main()
{
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int count = 0;
		for (int j = 0; j < 3; j++)
		{
			int x;
			cin >> x;
			if (x)
			{
				count++;
			}
			
		}
		if (count >= 2)
		{
			ans++;
		}
	}
	cout << ans;
}
 