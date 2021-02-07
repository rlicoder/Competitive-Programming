bool solve(string str) {
    set<char> s;
    for (int i = 0; i < str.size(); i++)
    {
        s.insert(str[i]);
    }
    return s.size() == str.size();
}
