import java.util.*;

public class d {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] a = new int[n+1];
        for (int i=0; i < n; i++) a[i] = sc.nextInt();
        a[n] = k;

        Arrays.sort(a);

        int left = 0;
        int right = n;
        while (true) {
            int i = (left+right)/2;
            boolean[][] dp = new boolean[n+1][k+1];
            dp[0][0] = true;

            for (int j = 0; j < n; j++) {
                for (int l = 0; l <= k; l++) {
                    if (dp[j][l]) {
                        dp[j+1][l] = true;
                        if (i != j && l+a[j] <= k) {
                            dp[j+1][l+a[j]] = true;
                        }
                    }
                }
            }

            boolean f = false;
            for (int j = Math.max(k-a[i], 0); j < k; j++) {
                if (dp[n][j]) f = true;
            }

            if (right == left + 1) {
                if (f) System.out.println(i);
                else System.out.println(i+1);
                break;
            }

            if (f) right = i;
            else left = i;
        }
    }
}