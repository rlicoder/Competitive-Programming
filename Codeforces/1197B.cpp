#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int highpos = max_element(a.begin(), a.end()) - a.begin();
    int high = a[highpos];
    bool good = true;
    for (int i = highpos + 1; i < n; i++)
    {
        if (a[i] > a[i-1])
        {
            good = false;
            break;
        }
    }
    for (int i = 1; i < highpos; i++)
    {
        if (a[i] < a[i-1])
        {
            good = false;
            break;
        }
    }
    if (good)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    cout << endl;
}
