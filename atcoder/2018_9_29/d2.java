import java.util.*;
import java.awt.*;

public class d2 {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    long[] X = new long[n];
    long[] Y = new long[n];

    for (int i = 0; i < n; i++) {
      X[i] = sc.nextLong();
      Y[i] = sc.nextLong();
    }

    int ans = 0;
    int odds = (Math.abs(X[0]) + Math.abs(Y[0])) % 2;

    for (int i = 0; i < n; i++) {
      if ((Math.abs(X[i]) + Math.abs(Y[i])) % 2 != odds) {
        ans = -1;
        System.out.println(ans);
        break;
      }
    }

    System.out.println(39);
    if (odds == 0) System.out.print("1 ");

    long tmp = 1;
    for (long i = 0; i < max; i++) {
      System.out.print(tmp);
      System.out.print(" ");
      tmp *= 2;
    }
  }
}
