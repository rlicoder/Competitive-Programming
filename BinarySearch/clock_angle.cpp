int solve(int hour, int minutes) {

    if (hour >= 12)
    {
        hour -= 12;
    }
    double h = (double)hour;
    double m = (double)minutes;
    h *= 30;
    h += (m*6)/12;
    m *= 6;
    if (m == 360)
    {
        m = 0;
    }
    if (m > h)
    {
        swap(m,h);
    }
    if (h - m > 180)
    {
        return 360 - (h-m);
    }
    return h-m;
}
