import java.util.*;
import java.awt.*;

public class c {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int R = sc.nextInt();
    int C = sc.nextInt();
    int sy = sc.nextInt()-1;
    int sx = sc.nextInt()-1;
    int gy = sc.nextInt()-1;
    int gx = sc.nextInt()-1;
    char[][] field = new char[R][C];
    for (int i = 0; i < R; i++) {
      field[i] = sc.next().toCharArray();
    }

    int[][] count = new int[R][C];
    Queue<Point> queue = new ArrayDeque<>();
    queue.add(new Point(sy, sx));
    count[sy][sx] = -Integer.MIN_VALUE;
    int[] x_move = {1,-1,0,0};
    int[] y_move = {0,0,1,-1};

    while (true) {
      int e = queue.size();
      for (int x = 0; x < e; x++) {
        Point point = queue.poll();

        for (int i = 0; i < 4; i ++) {
          int next_y = point.x + y_move[i];
          int next_x = point.y + x_move[i];
          if (next_y >= 0 && next_y < R && next_x >= 0 && next_x < C) {
            if (field[next_y][next_x] == '.') {
              if (count[next_y][next_x] > count[point.x][point.y] + 1) {
                count[next_y][next_x] = count[point.x][point.y] + 1;
                queue.add(new Point(next_y, next_x));
              }
            }
          }
        }
      }

      if (e==0) break;
    }

    System.out.println(count[gy][gx] - count[sy][sx]);
  }
}
