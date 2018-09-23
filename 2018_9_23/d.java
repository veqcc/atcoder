import java.util.*;
import java.awt.*;

public class d {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int N = sc.nextInt();
    long M = sc.nextLong();
    long tmp_M = M;
    final long MOD = 1000000007;
    Queue<Integer> queue = new ArrayDeque<Integer>();

    for (long i = 1; i*i < M; i++) {
      int tmp_count = 0;

      while(tmp_M % (i+1) == 0) {
        tmp_count++;
        tmp_M /= (i+1);
      }

      if (tmp_count > 0) {
        queue.add(tmp_count);
      }
    }

    if (queue.peek() == null) {
      queue.add(1);
    }

    long ans = 1;

    while(true) {
      if (queue.peek() == null) break;
      int a = queue.poll();
      ans *= comb((long)(N+a-1), (long)(a));
      ans %= MOD;
    }

    System.out.println(ans);
  }

  public static long comb(long sum, long a) {
    final long MOD = 1000000007;
    long ans = 1;

    for (int i = 0 ; i < a; i++) {
      ans *= (sum - i);
    }

    for (int i = 0 ; i < a; i++) {
      ans /= (a - i);
    }

    return ans % MOD;
  }
}
