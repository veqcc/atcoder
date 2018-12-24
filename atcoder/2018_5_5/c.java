import java.util.*;

public class c {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int H = sc.nextInt();
    int W = sc.nextInt();

    boolean[][] grid = new boolean[H+2][W+2];
    boolean[][] plot = new boolean[H+2][W+2];

    for (int i=1; i <= H; i++) {
      String str = sc.next();

      for (int j=1; j <= W; j++) {
        char c = str.charAt(j-1);
        String strAt = String.valueOf(c);

        if (strAt.equals("#")) {
          grid[i-1][j] = true;
          grid[i+1][j] = true;
          grid[i][j-1] = true;
          grid[i][j+1] = true;

          plot[i][j] = true;
        }
      }
    }

    String ans = "Yes";

    for (int i=1; i <= H; i++) {
      for (int j=1; j <= W; j++) {
        if (plot[i][j] == true && grid[i][j] == false) {
          ans = "No";
        }
      }
    }

    System.out.println(ans);
  }
}
