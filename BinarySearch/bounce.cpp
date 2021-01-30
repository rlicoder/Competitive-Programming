bool solve(vector<int>& a, int k) {
    int n = a.size();
    vector<bool> vis(n, false);
    
    queue<int>q;
    q.push(k);
    while (!q.empty())
    {
        int cur = q.front();
        //cout << cur << ": " << cur + a[cur] << " " << cur-a[cur] << endl;
        q.pop();
        if (cur == n-1)
        {
            return true;
        }
        vis[cur] = true;
        if (cur+a[cur] < n)
        {
            if (!vis[cur+a[cur]])
            {
                vis[cur+a[cur]] = true;
                q.push(cur + a[cur]);
            }
        }
        if (cur - a[cur] >= 0)
        {
            if (!vis[cur-a[cur]])
            {
                vis[cur-a[cur]] = true;
                q.push(cur-a[cur]);
            }
        }
    }
    return false;
}

