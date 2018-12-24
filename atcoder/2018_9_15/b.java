import java.util.*;

public class b {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int N = sc.nextInt();
    int X = sc.nextInt();
    long[] x = new long[N+1];
    for (int i = 0; i < N; i++) x[i+1] = sc.nextLong();

    boolean flag = false;
    long[] dp = new long[N];
    dp[0] = x[1] + X + (x[1] * (long)Math.pow(2, 2)) + X;

    for (int i = 1; i < N; i++) {
      long seperate_pattern = dp[i-1] + x[i+1] + X + (x[i+1] * (long)Math.pow(2, 2)) + X;

      if (flag == false) {
        long tmp = 0;
        for (int j = i; j >= 0; j--) tmp += (x[j+1] - x[j]) * (long)Math.pow(i-j+2, 2);
        long include_pattern = x[i+1] + (long)(2+i)*(long)X + tmp;

        if (include_pattern >= seperate_pattern) {
          flag = true;
          dp[i] = seperate_pattern;
        } else dp[i] = include_pattern;
      } else dp[i] = seperate_pattern;
    }

    System.out.println(dp[N-1]);
  }
}
