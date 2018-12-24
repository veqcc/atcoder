import java.util.*;

public class b {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int D = sc.nextInt();
    int N = sc.nextInt();
    int ans;

    if (N < 100) {
      ans = (int)(N * Math.pow(100, D));
    } else {
      ans = (int)((N+1) * Math.pow(100, D));
    }

    System.out.println(ans);
  }
}
