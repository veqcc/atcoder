import java.util.*;
import java.awt.*;

public class d {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int H = sc.nextInt();
    int W = sc.nextInt();
    int possible_field_count = 0;
    char[][] field = new char[H][W];
    for (int i = 0; i < H; i++) {
      field[i] = sc.next().toCharArray();
      for (int j = 0; j < W; j++) {
        if (field[i][j] == '.') possible_field_count++;
      }
    }

    Queue<Point> q = new ArrayDeque<>();
    q.add(new Point(0, 0));

    int[][] count = new int[H][W];
    count[0][0] = Integer.MIN_VALUE;

    int[] h_move = {1,-1,0,0};
    int[] w_move = {0,0,1,-1};

    while (true) {
      int e = q.size();
      if (e == 0) break;

      for (int x = 0; x < e; x++) {
        Point point = q.poll();

        for (int i = 0; i < 4; i++) {
          int next_h = point.x + h_move[i];
          int next_w = point.y + w_move[i];

          if (next_h >= 0 && next_h < H && next_w >= 0 && next_w < W) {
            if (field[next_h][next_w] == '.') {
              if (count[next_h][next_w] > count[point.x][point.y] + 1) {
                count[next_h][next_w] = count[point.x][point.y] + 1;
                q.add(new Point(next_h, next_w));
              }
            }
          }
        }
      }
    }

    if (count[H-1][W-1] == 0) {
      System.out.println(-1);
    } else {
      System.out.println(possible_field_count - (count[H-1][W-1] - count[0][0] + 1));
    }
  }
}
