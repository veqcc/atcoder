import java.util.*;

public class b {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    boolean ans = false;

    for (int i = 0; i <= n/7; i++) {
      if ((n-7*i) % 4 == 0) {
        ans = true;
      }
    }

    if (ans == true) {
      System.out.println("Yes");
    } else {
      System.out.println("No");
    }
  }
}
