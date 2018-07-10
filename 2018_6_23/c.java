import java.util.*;

public class c {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int N = sc.nextInt() - 1;
    int K = sc.nextInt() - 1;
    int ans = 0;

    for (int i=0; i < N; i++) {
      int num = sc.nextInt();
    }

    while (N > 0) {
      N = N - K;
      ans++;
    }

    System.out.println(ans);

  }
}
