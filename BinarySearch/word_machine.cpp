int solve(vector<string>& a) {
    stack<int> s;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == "+")
        {
            if (s.size() >= 2)
            {
                int sum = 0;
                sum += s.top();
                s.pop();
                sum += s.top();
                s.pop();
                s.push(sum);
            }
            else
            {
                return -1;
            }
        }
        else if (a[i] == "-")
        {
            if (s.size() >= 2)
            {
                int sum = 0;
                sum += s.top();
                s.pop();
                sum -= s.top();
                s.pop();
                s.push(sum);
            }
            else
            {
                return -1;
            }
        }
        else if (a[i] == "POP")
        {
            if (s.size() > 0)
            {
                s.pop();
            }
            else
            {
                return -1;
            }
        }
        else if (a[i] == "DUP")
        {
            if (s.size() > 0)
            {
                int x = s.top();
                s.push(x);
            }
            else
            {
                return -1;
            }
        }
        else
        {
            s.push(stoi(a[i]));
        }
        
    }
    return s.top();
}
