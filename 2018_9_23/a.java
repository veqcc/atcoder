import java.util.*;
import java.awt.*;

public class a {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int A = sc.nextInt();
    int B = sc.nextInt();
    int C = sc.nextInt();

    int max = Math.max(A, Math.max(B, C));

    System.out.println(A + B + C + 9 * max);
  }
}
