import java.util.*;
import java.awt.*;

public class b {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    long[] A = new long[n];
    long[] B = new long[n];

    for (int i = 0; i < n; i++) {
      A[i] = sc.nextLong();
    }

    for (int i = 0; i < n; i++) {
      B[i] = sc.nextLong();
    }

    long big_b = 0;
    long big_a = 0;

    for (int i = 0; i < n; i++) {
      if (A[i] > B[i]) {
        big_a += A[i] - B[i];
      } else {
        big_b += (B[i] - A[i]) / 2;
      }
    }

    if (big_a > big_b) {
      System.out.println("No");
    } else {
      System.out.println("Yes");
    }
  }
}
