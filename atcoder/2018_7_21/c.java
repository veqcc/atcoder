import java.util.*;

public class c {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    int ans = 0;

    for (int i=0; i < n; i++) {
      ans += sc.nextInt() - 1;
    }

    System.out.println(ans);
  }
}
