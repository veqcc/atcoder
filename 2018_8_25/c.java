import java.util.*;

public class c {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    int k = sc.nextInt();
    int[] x = new int[n];

    for (int i = 0; i < n; i++) {
      x[i] = sc.nextInt();
    }

    int ans = Integer.MAX_VALUE;

    for (int i = 0; i <= n-k; i++) {
      int start = x[i];
      int end = x[i+k-1];
      if ((start > 0 && end < 0) || (start < 0 && end > 0)) {
        start = Math.abs(start);
        end = Math.abs(end);
        ans = Math.min(ans, Math.min(start, end) * 2 + Math.max(start, end));
      } else {
        start = Math.abs(start);
        end = Math.abs(end);
        ans = Math.min(ans, Math.max(start, end));
      }
    }

    System.out.println(ans);
  }
}
