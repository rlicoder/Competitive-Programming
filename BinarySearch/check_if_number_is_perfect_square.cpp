bool solve(int n) {
    for (int i = 0; i*i <= INT_MAX; i++)
    {
        if (i*i == n)
        {
            return true;
        }
        if (i*i > n)
        {
            return false;
        }
    }
}
