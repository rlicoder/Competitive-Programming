import java.math.*;
import java.util.*;

public class dice
{
    public static void main(String[] args)
    {
        Scanner s = new Scanner(System.in);
        int n, a, b;
        //cin >> n >> a >> b;
        n = s.nextInt();
        a = s.nextInt();
        b = s.nextInt();
        //long double total = pow(6, n);
        BigDecimal total = new BigDecimal("0");
        //long double ways = 0;
        BigDecimal ways = new BigDecimal("0");
        //vector<vector<long long>> dp(6*n+1, vector<long long>(n+1, 0));
        Vector<Vector<BigDecimal>> dp = new Vector<>();
        for (int i = 0; i <= 6*n; i++)
        {
            Vector<BigDecimal>row = new Vector<>();
            dp.add(row);
            for (int j = 0; j <= n; j++)
            {
                BigDecimal x = new BigDecimal("0");
                row.add(x);
            }
        }
        //for (long long i = 1; i <= 6; i++)
        //{
        //    dp[i][1] = 1;
        //}
        for (int i = 1; i <= 6; i++)
        {
            BigDecimal one = new BigDecimal("1");
            dp.get(i).set(1, one);
        }
        //for (long long j = 2; j <= n; j++)
        //{
        //    for (long long i = 1; i <= 6*n; i++)
        //    {
        //        for (long long x = 1; x <= 6; x++)
        //        {
        //            if (i - x >= 0)
        //            {
        //                dp[i][j] += dp[i-x][j-1];
        //            }
        //        }
        //    }
        //}
        for (int j = 2; j <= n; j++)
        {
            for (int i = 1; i <= 6*n; i++)
            {
                for (int x = 1; x <= 6; x++)
                {
                    if (i - x >= 0)
                    {
                        BigDecimal res = dp.get(i).get(j).add(dp.get(i-x).get(j-1));
                        dp.get(i).set(j, res);
                        //dp.get(i).set(j, dp.get(i).get(j).add(dp.get(i-x).get(j-1)));
                    }
                }
            }
        }
        //for (long long i = a; i <= b; i++)
        //{
        //    ways += dp[i][n];
        //}
        for (int i = a; i <= b; i++)
        {
            ways = ways.add(dp.get(i).get(n));
        }
        //cout << fixed << setprecision(6);
        BigDecimal ans = new BigDecimal("0");
        ans = ans.setScale(6);
        total = new BigDecimal("6").pow(n);
        ans = ways.divide(total, 6, RoundingMode.HALF_UP);
        //cout << ways << " / " << total << endl;
        System.out.println(ans);
    }
}
