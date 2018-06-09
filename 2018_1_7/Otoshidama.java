import java.util.*;

public class Otoshidama {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int N = sc.nextInt();
    int Y = sc.nextInt();
    boolean f = false;

    for (int i=0; i <= N; i++) {
      if (Y < i * 10000 || f == true) {
        break;
      }

      for (int j=0; j <= N-i; j++) {
        if (Y < i * 10000 + j * 5000  || f == true) {
          break;
        }

        if (i * 10000 + j * 5000 + (N-i-j) * 1000 == Y) {
          System.out.println(i + " " + j + " " + (N-i-j));
          f = true;
          break;
        }
      }
    }

    if (f == false) {
      System.out.println("-1 -1 -1");
    }
  }
}
