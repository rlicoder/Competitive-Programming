bool solve(string s, string ss) {
    sort(s.begin(), s.end());
    sort(ss.begin(),ss.end());
    return s == ss;
}
