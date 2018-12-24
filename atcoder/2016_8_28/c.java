import java.util.*;

public class c {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int A = sc.nextInt();
        int[] x = new int[N];
        for (int i = 0; i < N; i++) {
            x[i] = sc.nextInt();
        }

        long[][] dp = new long[N][A*N+1];
        for (int i = 0; i < N; i++) {
            for (int j = i; j >= 1; j--) {
                for (int k = 0; k <= A*N; k++) {
                    if (dp[j-1][k] > 0 && k+x[i] <= A*N) {
                        dp[j][k + x[i]] += dp[j-1][k];
                    }
                }
            }
            if (x[i] <= A*N) dp[0][x[i]] += (long)1;
        }

        long ans = 0;
        for (int i = 0; i < N; i++) {
            ans += (long)dp[i][A*(i+1)];
        }

        System.out.println(ans);
    }
}
