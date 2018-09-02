import java.util.*;

public class c {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    int k = sc.nextInt();
    long ans = 0;
    if (k <= 2 * n) {
      ans = (long)Math.pow(n/k, 3);
      if (k % 2 == 0) {
        ans += (long)Math.pow((n-k/2)/k+1, 3);
      }
    }

    System.out.println(ans);
  }
}
