import java.util.*;

public class a {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    int k = sc.nextInt();
    int ans = 0;

    if (n % k != 0) {
      ans = 1;
    }

    System.out.println(ans);
  }
}
