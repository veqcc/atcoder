import java.util.*;

public class d {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    int m = sc.nextInt();
    int s = sc.nextInt();
    int t = sc.nextInt();

    Long[][] amap = new Long[n][n];
    Long[][] bmap = new Long[n][n];
    int u, v;
    Long a, b;

    for (int i=0; i < m; i++) {
      u = sc.nextInt();
      v = sc.nextInt();
      a = sc.nextLong();
      b = sc.nextLong();

      amap[u-1][v-1] = a;
      amap[v-1][u-1] = a;
      bmap[u-1][v-1] = b;
      bmap[v-1][u-1] = b;
    }

    System.out.println("------");

    Long[] yenCost = new Long[n];
    boolean[] fixed = new boolean[n];
    for (int i=0; i < n; i++) {
      yenCost[i] = Long.MAX_VALUE;
      fixed[i] = false;
    }
    yenCost[s-1] = (long)0;
    fixed[s-1] = true;

    while (true) {
      int min_num = -1;
      Long min_cost = Long.MAX_VALUE;
      for (int i=0; i < n; i++) {
        if (fixed[i] == true && yenCost[i] < min_cost) {
          min_num = i;
          min_cost = yenCost[i];
        }
      }

      for (int i=0; i < n; i++) {
        yenCost[i] += amap[min_num][i];
        fixed[min_num] = true;
      }

      boolean res = true;
      for (int i=0; i < n; i++) {
        if (fixed[i] == false) {
          res = false;
        }
      }

      if (res == false) {
        break;
      }
    }

    Long[] snuukCost = new Long[n];
    boolean[] snuukfixed = new boolean[n];
    for (int i=0; i < n; i++) {
      snuukCost[i] = Long.MAX_VALUE;
      snuukfixed[i] = false;
    }
    snuukCost[t-1] = (long)0;

    while (true) {
      int min_num = -1;
      Long min_cost = Long.MAX_VALUE;
      for (int i=0; i < n; i++) {
        if (snuukfixed[i] == false && snuukCost[i] < min_cost) {
          min_num = i;
          min_cost = snuukCost[i];
        }
      }

      for (int i=0; i < n; i++) {
        snuukCost[i] += bmap[min_num][i];
        snuukfixed[i] = true;
      }

      boolean res = true;
      for (int i=0; i < n; i++) {
        if (snuukfixed[i] == false) {
          res = false;
        }
      }

      if (res == false) {
        break;
      }
    }

    Long[] ans = new Long[n];
    Long min = Long.MAX_VALUE;

    ans[n-1] = yenCost[n-1] + snuukCost[n-1];

    for (int i=n-2; i > 0; i--) {
      if (yenCost[i] + snuukCost[i] < ans[i+1]) {
        ans[i] = yenCost[i] + snuukCost[i];
      } else {
        ans[i] = ans[i=1];
      }
    }

    for (int i=0; i < n; i++) {
      System.out.println(ans[i]);
    }
  }
}
