import java.util.*;

public class a {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int a = sc.nextInt();
    int b = sc.nextInt();
    int c = sc.nextInt();
    int d = sc.nextInt();

    if (Math.abs(c-a) <= d) {
      System.out.println("Yes");
    } else if (Math.abs(b-c) <= d && Math.abs(b-a) <= d) {
      System.out.println("Yes");
    } else {
      System.out.println("No");
    }
  }
}