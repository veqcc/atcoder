import java.util.*;

public class a {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int N = sc.nextInt();
    int A = sc.nextInt();
    int B = sc.nextInt();
    int C = sc.nextInt();
    int D = sc.nextInt();

    int aCost = 0;
    int cCost = 0;

    int tmpN = N;

    while (tmpN > 0) {
      tmpN -= A;
      aCost += B;
    }

    tmpN = N;

    while (tmpN > 0) {
      tmpN -= C;
      cCost += D;
    }

    System.out.println(Math.min(aCost, cCost));
  }
}
