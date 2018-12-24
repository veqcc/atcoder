import java.util.*;
import java.awt.*;

public class c {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    int X = sc.nextInt();
    int ans = Math.abs(sc.nextInt() - X);

    for (int i = 1; i < n; i++) {
      int diff = Math.abs(sc.nextInt() - X);
      ans = gcd(ans, diff);
    }

    System.out.println(ans);
  }

  public static int gcd(int m, int n) {
      if(m < n) return gcd(n, m);
      if(n == 0) return m;

      return gcd(n, m % n);
  }
}
