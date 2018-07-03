import java.util.*;

public class c {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int H = sc.nextInt();
    int W = sc.nextInt();

    int[][] A = new int[H][W];

    for (int i=0; i < H; i++) {
      for (int j=0; j < W; j++) {
        A[i][j] = sc.nextInt();
      }
    }

    int ans = Integer.MAX_VALUE;

    for (int i=0; i < H; i++) {
      for (int j=0; j < W; j++) {
        int tmp_ans = 0;
        // 幹線道路はi, j番目
        for (int k=0; k < H; k++) {
          for (int l=0; l < W; l++) {
            tmp_ans += A[k][l] * Math.min(Math.abs(i-k), Math.abs(j-l));
          }
        }

        ans = Math.min(ans, tmp_ans);
      }
    }


    System.out.println(ans);
  }
}
