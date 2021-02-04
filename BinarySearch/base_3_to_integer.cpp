int solve(string s) {
    int ans = 0;
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++)
    {
        ans += (s[i]-'0') * (int) pow(3,i);
    }
    return ans;
}
