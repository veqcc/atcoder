import java.util.*;

public class c {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    long[] A = new long[n];

    for (int i=0; i < n; i++) {
      A[i] = sc.nextLong() - i - 1;
    }

    Arrays.sort(A);

    long b = A[n/2];
    long ans = 0;

    for (int i=0; i < n; i++) {
      ans += Math.abs(A[i] - b);
    }

    System.out.println(ans);
  }
}
