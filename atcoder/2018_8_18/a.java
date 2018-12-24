import java.util.*;

public class a {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int A = sc.nextInt();
    int B = sc.nextInt();

    int ans = A * B - A - B + 1;

    System.out.println(ans);
  }
}
