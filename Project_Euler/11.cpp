#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<vector<int>> a(20, vector<int>(20));
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            cin >> a[i][j];
        }
    }
    function<bool(int,int,pair<int,int>)> valid = [=] (int x, int y, pair<int,int> dir) {
        x += dir.first * 4;
        y += dir.second * 4;
        return (x >= 0 && x < 20 && y >= 0 && y < 20);
    };
    long long ans = 0;
    vector<pair<int,int>> dir {{1,0}, {0,1}, {1,1}, {-1,1}};
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[i].size(); j++) {
            for (int k = 0; k < dir.size(); k++) {
                if (valid(i,j,dir[k])) {
                    long long test = 1;
                    for (int l = 1; l <= 4; l++) {
                        test *= a[i+dir[k].first*l][j+dir[k].second*l];
                    }
                    ans = max(ans, test);
                }
            }
        }
    }
    cout << ans << endl;
}
