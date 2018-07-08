import java.util.*;

public class c {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    Long n = sc.nextLong();
    Long m = sc.nextLong();
    Long d = sc.nextLong();

    double ans = 2 * (n-d) * (m-1) / Math.pow(n, 2);

    if (d==0) {
      ans /= 2.0;
    }

    System.out.println(ans);
  }
}
