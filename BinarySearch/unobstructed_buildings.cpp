vector<int> solve(vector<int>& a) {
    
    int max = -1;
    vector<int>ans;
    for (int i = a.size()-1; i >= 0; i--)
    {
        if (a[i] > max)
        {
            ans.push_back(i);
            max = a[i];
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
