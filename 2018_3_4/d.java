import java.util.*;

public class d {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int H = sc.nextInt();
    int W = sc.nextInt();
    int D = sc.nextInt();
    int[] x = new int[H*W+1];
    int[] y = new int[H*W+1];

    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        int tmp = sc.nextInt();
        x[tmp] = i;
        y[tmp] = j;
      }
    }

    int[] cost = new int[H*W+1];
    for (int i = D+1; i < H*W+1; i++) {
      cost[i] = cost[i-D] + Math.abs(x[i] - x[i-D]) + Math.abs(y[i] - y[i-D]);
    }

    int Q = sc.nextInt();
    int[] L = new int[Q];
    int[] R = new int[Q];

    for (int i = 0; i < Q; i++) {
      L[i] = sc.nextInt();
      R[i] = sc.nextInt();
    }

    for (int i = 0; i < Q; i++) {
      System.out.println(cost[R[i]] - cost[L[i]]);
    }
  }
}
