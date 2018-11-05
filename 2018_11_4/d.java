import java.util.*;
import java.awt.*;

public class d {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        int h = sc.nextInt();
        int w = sc.nextInt();
        int k = sc.nextInt();
        long e = 1000000007;

        long[][] dp = new long[h+1][w];
        dp[0][0] = 1;

        for (int i = 1; i <= h; i++) {
            for (int j = 0; j < w; j++) {
                dp[i][j] += (dp[i-1][j] * tmp(w-j-2) * tmp(j-1)) % e;
                if (j-1 >= 0) {
                    dp[i][j] += (dp[i-1][j-1] * tmp(w-j-2) * tmp(j-2)) % e;
                }
                if (j+1 < w) {
                    dp[i][j] += (dp[i-1][j+1] * tmp(w-j-3) * tmp(j-1)) % e;
                }
                dp[i][j] %= e;
            }
        }

        System.out.println(dp[h][k-1]);
    }

    public static long tmp(int x) {
        long ret = 1;

        if (x == 1) {
            ret = 2;
        } else if (x == 2) {
            ret = 3;
        } else if (x == 3) {
            ret = 5;
        } else if (x == 4) {
            ret = 8;
        } else if (x == 5) {
            ret = 13;
        } else if (x == 6) {
            ret = 21;
        }

        return ret;
    }
}
