import java.util.*;

public class Main {
  public int LongestPath(String[] maze, int startRow, int startCol, int[] moveRow, int moveCol) {
    boolean[][] maze = {
      {true, true, true},
      {true, true, true},
      {true, true, true}
    };

    int mazeSize = 3;

    int[][] countGrid = {
      {-1, -1, -1},
      {-1, -1, -1},
      {-1, -1, -1}
    };

    void search(int row, int col, int count) {
      for (int i=0; i < moveRow.length; i++) {
        int nextRow = row + moveRow[i];
        int nextCol = col + moveCol[i];


        if (nextRow < 0 || nextRow >= mazeSize || nextCol < 0 || nextCol >= mazeSize) { // 枠からはみ出たらアウト
          continue;
        } else if (maze[nextRow][nextCol] == false) { //止まれなかったらアウト
          continue;
        } else if (countGrid[nextRow][nextCol] < count) { //今までの経路より長かったらアウト
          continue;
        } else {
          countGrid[nextRow][nextCol] = count+1;
          search(nextRow, nextCol, count+1);
        }
      }
    }

    search(startRow, startcol, 0);

    int ans = -1;

    for (int i=0; i < mazeSize; i++) {
      ans = Math.max(ans, countGrid[0][i]);
      ans = Math.max(ans, countGrid[mazeSize-1][i]);
      ans = Math.max(ans, countGrid[i][0]);
      ans = Math.max(ans, countGrid[i][mazeSize-1]);
    }

    return ans;
  }

  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int[] moveRow = {1,0,-1,0};
    int[] moveCol = {0,1,0,-1};

    int ans = LongestPath("a", 0, 1, moveRow, moveCol);

    System.out.println(ans);
  }
}
