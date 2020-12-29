#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    multiset<int, less<int>> stack;

    for (int i = 0; i < n; i++)
    {
        int x; 
        cin >> x;
        auto it = stack.upper_bound(x);
        if (it == stack.end())
        {
            stack.insert(x);
        }
        else
        {
            stack.erase(it);
            stack.insert(x);
        }
    }
    cout << stack.size() << endl;
}
                
                



