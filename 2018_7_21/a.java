import java.util.*;

public class a {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int x = sc.nextInt();
    int y = sc.nextInt();
    int z = sc.nextInt();

    int ans = 0;

    ans = Math.max(x, Math.max(y, z)) - Math.min(x, Math.min(y, z));

    System.out.println(ans);
  }
}
