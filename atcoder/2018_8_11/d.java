import java.util.*;

public class d {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    long m = sc.nextLong();
    long[] A = new long[n+1];

    for (int i = 1; i <= n; i++) {
      A[i] = (A[i-1] + sc.nextLong()) % m;
    }

    Arrays.sort(A);

    long tmp = 0;
    long tmp_count = 1;
    long ans = 0;

    for (int i = 1; i <= n; i++) {
      if (A[i] == tmp) {
        tmp_count++;
      } else {
        ans += tmp_count * (tmp_count - 1) / 2;
        tmp = A[i];
        tmp_count = 1;
      }
    }

    ans += tmp_count * (tmp_count - 1) / 2;

    System.out.println(ans);
  }
}
