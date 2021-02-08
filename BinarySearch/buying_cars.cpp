int solve(vector<int>& prices, int k) {
    sort(prices.begin(), prices.end());
    int count = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        if (k - prices[i] >= 0)
        {
            count++;
            k -= prices[i];
        }
    }
    return count;
}
