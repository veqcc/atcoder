import java.util.*;

public class d {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int H = sc.nextInt();
    int W = sc.nextInt();
    int Q = sc.nextInt();

    long[] a = new long[H+1];
    long[] b = new long[W+1];
    int[][] pq = new int[Q][4];

    for (int i = 1; i <= H; i++) {
      a[i] = a[i-1] + sc.nextInt() * (int)Math.pow(-1, i%2);
    }

    for (int i = 1; i <= W; i++) {
      b[i] = b[i-1] + sc.nextInt() * (int)Math.pow(-1, i%2);
    }

    for (int i = 0; i < Q; i++) {
      pq[i][0] = sc.nextInt();
      pq[i][1] = sc.nextInt();
      pq[i][2] = sc.nextInt();
      pq[i][3] = sc.nextInt();
    }

    for (int i = 0; i < Q; i++) {
      long ans = (a[pq[i][2]] - a[pq[i][0]-1]) * (b[pq[i][3]] - b[pq[i][1]-1]);
      System.out.println(ans);
    }
  }
}
