import java.util.*;

public class Traveling {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int N = sc.nextInt();
    boolean f = true;

    for (int i=0; i < N; i++) {
      int t = sc.nextInt();
      int x = sc.nextInt();
      int y = sc.nextInt();

      if (x+y <= t) {
        if (t%2 != (x+y)%2) {
          f = false;
        }
      } else {
        f = false;
      }
    }

    if (f == false) {
      System.out.println("No");
    } else {
      System.out.println("Yes");
    }
  }
}
