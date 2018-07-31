import java.util.*;

public class b {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int N = sc.nextInt();
    int K = sc.nextInt();
    long[] b = new long[N];
    long[] sumB = new long[N-K+1];

    for (int i = 0; i < N; i++) {
      b[i] = sc.nextLong();
    }

    for (int i = 0; i < K; i++) {
      sumB[0] += b[i];
    }

    for (int i = 1; i < N-K+1; i++) {
      sumB[i] = sumB[i-1] - b[i-1] + b[i + K - 1];
    }

    int tmp = findMinIndex(sumB);

    while (sumB[tmp] < (long)0) {
      for (int i=0; i < K; i++) {
        b[tmp + i] = (long)0;
      }

      sumB[0] = (long)0;
      for (int i = 0; i < K; i++) {
        sumB[0] += b[i];
      }

      for (int i = 1; i < N-K+1; i++) {
        sumB[i] = sumB[i-1] - b[i-1] + b[i + K - 1];
      }

      tmp = findMinIndex(sumB);
    }

    long ans = 0;

    for (int i = 0; i < N; i++) {
      ans += b[i];
    }

    System.out.println(ans);
  }

  public static int findMinIndex(long a[]) {
    long min = Long.MAX_VALUE;
    int index = 0;

    for (int i = 0; i < a.length; i++) {
      if (a[i] < min) {
        index = i;
        min = a[i];
      }
    }

    return index;
  }
}
