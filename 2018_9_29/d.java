import java.util.*;
import java.awt.*;

public class d {
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
    long odds = (Math.abs(X[0]) + Math.abs(Y[0])) % 2;

    for (int i = 0; i < n; i++) {
      if ((Math.abs(X[i]) + Math.abs(Y[i])) % 2 != odds) {
        ans = -1;
        System.out.println(ans);
        break;
      }
    }

    if (ans != -1) {
      long max = 0;
      for (int i = 0; i < n; i++) {
        if (Math.abs(X[i]) + Math.abs(Y[i]) > max) {
          max = X[i]+Y[i];
        }
      }

      if (max == 0) {
        System.out.println("2");
        System.out.println("1 1");
        System.out.println("UD");
      } else {
        System.out.println(max);
      }

      for (long i = 0; i < max; i++) {
        System.out.print("1 ");
      }
      System.out.print("\n");

      for (int i = 0; i < n; i++) {
        for (long j = 0; j < Math.abs(X[i]); j++) {
          if (X[i] >= 0) {
            System.out.print("R");
          } else {
            System.out.print("L");
          }
        }

        for (long j = 0; j < Math.abs(Y[i]); j++) {
          if (Y[i] >= 0) {
            System.out.print("U");
          } else {
            System.out.print("D");
          }
        }

        for (int j = 0; j < (max-Math.abs(X[i])-Math.abs(Y[i]))/2; j++) {
          System.out.print("U");
          System.out.print("D");
        }
        System.out.print("\n");
      }
    }
  }
}
