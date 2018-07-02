import java.util.*;

public class d {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    long[] A = new long[n];

    for (int i=0; i < n; i++) {
      A[i] = sc.nextLong();
    }

    long ans = Long.MAX_VALUE;

    for (int c=1; c < n-2; c++) {
      long p = 0;
      long q = 0;
      long r = 0;
      long s = 0;
      long first_sum = 0;
      long second_sum = 0;
      long tmp = 0;
      int b=0;
      int true_b = 0;
      int d = n-1;
      int true_d = n-1;

      for (int i=0; i <= c; i++) {
        first_sum += A[i];
      }

      for (int i=c+1; i < n; i++) {
        second_sum += A[i];
      }

      long diff = Long.MAX_VALUE;

      while (true) {
        tmp += A[b];
        if (diff > Math.abs(first_sum - 2 * tmp)) {
          diff = Math.abs(first_sum - 2 * tmp);
          true_b = b;
        }
        b++;
        if (b == c) {
          break;
        }
      }

      tmp = 0;
      diff = Long.MAX_VALUE;

      while (true) {
        tmp += A[d];
        if (diff > Math.abs(second_sum - 2 * tmp)) {
          diff = Math.abs(second_sum - 2 * tmp);
          true_d = d;
        }
        d--;
        if (d == c+1) {
          break;
        }
      }

      for (int i=0; i <= true_b; i++) {
        p += A[i];
      }

      for (int i=true_b+1; i <= c; i++) {
        q += A[i];
      }

      for (int i=c+1; i < true_d; i++) {
        r += A[i];
      }

      for (int i=true_d; i <= n-1; i++) {
        s += A[i];
      }

      long max = Math.max(Math.max(p,q), Math.max(r,s));
      long min = Math.min(Math.min(p,q), Math.min(r,s));

      if (ans > max - min) {
        ans = max - min;
      }

      // System.out.println("c=" + c);
      // System.out.println("p=" + p);
      // System.out.println("q=" + q);
      // System.out.println("r=" + r);
      // System.out.println("s=" + s);
      // System.out.println("------------------");
    }

    System.out.println(ans);
  }
}
