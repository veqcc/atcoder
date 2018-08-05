import java.util.*;

public class c {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int D = sc.nextInt();
    int G = sc.nextInt();
    int[] p = new int[D];
    int[] c = new int[D];
    int count = 0;

    for (int i =0; i < D; i++) {
      p[i] = sc.nextInt();
      c[i] = sc.nextInt();
      count += p[i];
    }

    int[] dp = new int[count+1];
    int point = 0;

    for (int i = 0; i < D; i++) {
      for (int j = point; j >= 0; j--) {
        for (int k = 0; k < p[i]; k++) {
          int tmp = dp[j] + (1 + i) * 100 * (k + 1);
          if (k == p[i]-1) {
            tmp += c[i];
          }

          if (tmp > dp[j+k+1]) {
            dp[j+k+1] = tmp;
          }
        }
      }
      point += p[i];
    }

    int ans = count;

    for (int i = 0; i <= count; i++) {
      if (dp[i] >= G) {
        ans = i;
        break;
      }
    }

    System.out.println(ans);
  }
}
