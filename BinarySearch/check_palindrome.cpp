bool solve(string s) {
    string a = s;
    reverse(a.begin(), a.end());
    return a == s;
}
