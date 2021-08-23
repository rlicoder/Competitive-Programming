#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<array<int,3>> q;
    set<int> roomsavail;
    for (int i = 0; i < n; i++)
    {
        roomsavail.insert(i+1);
        int x,y;
        cin >> x >> y;
        q.push_back({x,1,i+1});
        q.push_back({y,2,i+1});
    }
    sort(q.begin(), q.end());
    vector<int> a(n+1, -1);
    vector<pair<int,int>> ans;
    int hi = 0;
    for (int i = 0; i < q.size(); i++)
    {
        //cout << q[i][0] << " " << q[i][1] << " " << q[i][2] << endl;
        if (q[i][1] == 1)
        {
            int room = *roomsavail.begin();
            roomsavail.erase(roomsavail.begin());
            //cout << "room " << room << " is taken" << endl;
            hi = max(hi, room);
            ans.push_back({q[i][2], room});
            a[q[i][2]] = room;
        }
        else
        {
            //cout << "room " << a[q[i][2]] << " is now empty " << endl;
            roomsavail.insert(a[q[i][2]]);
            a[q[i][2]] = -1;
        }
    }
    cout << hi << endl;
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].second << " ";
    }
}