import java.util.*;

public class a {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    long C = sc.nextLong();
    long D = sc.nextLong();
    long ans = 0;

    long n = 0;

    while (true) {
      if (C / (140 * Math.pow(2, n)) < 2) {
        break;
      } else {
        n++;
      }
    }

    long m = 0;

    while (true) {
      if (D / (140 * Math.pow(2, m)) < 2) {
        break;
      } else {
        m++;
      }
    }

    if (m-n >= 1) {
      ans += Math.max(0, 30 * Math.pow(2, n) - C % (140 * Math.pow(2, n)));
      ans += Math.min(30 * Math.pow(2, m), D - 140 * Math.pow(2, m));
      for (long i = n+1; i < m; i++) {
        ans += 30 * Math.pow(2, i);
      }
    } else {
      ans += Math.max(0, Math.min(D-C, 170*Math.pow(2, n) - C));
    }

    System.out.println(ans);
  }
}
