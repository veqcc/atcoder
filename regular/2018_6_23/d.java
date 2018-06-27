import java.util.*;

public class d {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int k = sc.nextInt();

    for (int i=1; i <= k; i++) {
      if (i==10) {
        break;
      }
      System.out.println(i);
    }

    if (k >= 10) {
      k = k-9;

      for (int i=1; i <= k; i++) {
        if (i==10) {
          break;
        }
        System.out.println(i*10 + 9);
      }

      if (k >= 10) {
        k = k-9;

        for (int i=1; i <= k; i++) {
          if (i==10) {
            break;
          }
          System.out.println(i*100 + 99);
        }

        if (k >= 10) {
          k = k - 9;

          for (long i=1; i <= k; i++) {
            System.out.println((i+9)*100 + 99);
          }
        }
      }
    }
  }
}
