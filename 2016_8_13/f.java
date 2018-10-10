import java.util.*;
import java.awt.*;

public class f {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        String s = sc.next();

        long[][] dp = new long[n+1][n+1];
        final long f = 1000000007;

        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % f;

            for (int j = 1; j < i; j++) {
                dp[i][j] = (dp[i-1][j-1] * 2 + dp[i-1][j+1]) % f;
            }

            dp[i][i] = (dp[i-1][i-1] * 2) % f;
        }

        int s_len = s.length();
        long pattern = 1;

        for (int i = 0; i < s_len; i++) {
            pattern = (pattern * 2) % f;
        }

        long reverse_pattern = power(pattern, f-2);
        System.out.println(power(2, f-2));

        System.out.println(dp[n][s_len] * 500000004 % f);
    }

    public static long power(long x, long y) {
        final long f = 1000000007;

        if (y == 0) {
            return 1;
        }
        else if (y == 1) {
            return x % f;
        }
        else if (y % 2 == 0) {
            return (long)Math.pow(power(x, y/2), 2) % f;
        }
        else {
            return ((long)Math.pow(power(x, (y-1)/2), 2) * x) % f;
        }
    }
}
