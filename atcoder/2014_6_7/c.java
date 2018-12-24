import java.util.*;
import java.awt.*;

public class c {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int txa = sc.nextInt();
    int tya = sc.nextInt();
    int txb = sc.nextInt();
    int tyb = sc.nextInt();
    int T = sc.nextInt();
    int V = sc.nextInt();
    int n = sc.nextInt();
    int[] x = new int[n];
    int[] y = new int[n];

    for (int i = 0; i < n; i++) {
      x[i] = sc.nextInt();
      y[i] = sc.nextInt();
    }

    String ans = "NO";

    double length = T * V;

    for (int i = 0; i < n; i++) {
      double total_length = 0;
      total_length += Math.pow(Math.pow(x[i] - txa, 2) + Math.pow(y[i] - tya, 2), 0.5);
      total_length += Math.pow(Math.pow(x[i] - txb, 2) + Math.pow(y[i] - tyb, 2), 0.5);

      if (total_length <= length) {
        ans = "YES";
        break;
      }
    }

    System.out.println(ans);
  }
}
