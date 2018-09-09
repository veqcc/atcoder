import java.util.*;
import java.awt.*;

public class d {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int H = sc.nextInt();
    int W = sc.nextInt();
    int[][] a = new int[H][W];
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) a[i][j] = sc.nextInt();
    }

    int prev_h = 0;
    int prev_w = 0;
    int flag = 1;
    int[][] ans = new int[H*W][4];
    int count = 0;

    for (int h = 0; i < H; h++) {
      for (int tmp_w = 0; tmp_w < W; tmp_w++) {
        int w = tmp_w + (W-1-2*tmp_w) * (h%2);

        if (flag == -1) {
          ans[count][0] = prev_h+1;
          ans[count][1] = prev_w+1;
          ans[count][2] = h+1;
          ans[count][3] = w+1;
          count++;
        }

        prev_h = h;
        prev_w = w;
        
        if (a[h][w] % 2 == 1) flag *= -1;
      }
    }

    System.out.println(count);

    for (int i = 0; i < count; i++) {
      System.out.println(ans[i][0]+" "+ans[i][1]+" "+ans[i][2]+" "+ans[i][3]);
    }
  }
}
