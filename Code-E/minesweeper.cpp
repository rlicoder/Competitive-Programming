#include <iostream>
#include <vector>

using namespace std;


bool valid (int i, int j, int n, int m)
{
    return (i >= 0 && i < n) && (j < m && j >= 0);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char> > a(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '.')
            {
                int count = 0;
                for (int l = -1; l <= 1; l++)
                {
                    for (int k = -1; k <= 1; k++)
                    {
                        if (l == k && l == 0)
                        {
                            continue;
                        }
                        if (valid(i+l,j+k,n,m) && a[i+l][j+k] == '*')
                        {
                            count++;
                        }
                    }
                }
                cout << count;
            }
            else
            {
                cout << "*";
            }
        }
        cout << endl;
    }
}
