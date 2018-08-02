import java.util.*;

public class a {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    String C1 = sc.next();
    int A = sc.nextInt();
    String C2 = sc.next();
    int B = sc.nextInt();

    if (C1.equals("W")) {
      A = 12 - A/15;
    } else if (C1.equals("E")) {
      A = 12 + A/15;
    }

    if (C2.equals("W")) {
      B = 12 - B/15;
    } else if (C2.equals("E")) {
      B = 12 + B/15;
    }

    System.out.println(Math.abs(A - B));
  }
}
