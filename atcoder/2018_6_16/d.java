import java.util.*;

public class d {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    int m = sc.nextInt();
    int[][] mArray = new int[8][m];
    long[] mValueArray = new long[8];
    long[][] matrix = new long[n][3];
    long ans = 0;

    for (int i=0; i < n; i++) {
      matrix[i][0] = sc.nextInt();
      matrix[i][1] = sc.nextInt();
      matrix[i][2] = sc.nextInt();
    }

    for (int i=0; i < m; i++) {
      for (int j=0; j < 8; j++) {
        mArray[j][i] = i;
      }
    }

    for (int i=0; i < m; i++) {
      mValueArray[0] += matrix[mArray[0][i]][0] + matrix[mArray[0][i]][1] + matrix[mArray[0][i]][2];
      mValueArray[1] += -matrix[mArray[1][i]][0] + matrix[mArray[1][i]][1] + matrix[mArray[1][i]][2];
      mValueArray[2] += matrix[mArray[2][i]][0] - matrix[mArray[2][i]][1] + matrix[mArray[2][i]][2];
      mValueArray[3] += matrix[mArray[3][i]][0] + matrix[mArray[3][i]][1] - matrix[mArray[3][i]][2];
      mValueArray[4] += -matrix[mArray[4][i]][0] - matrix[mArray[4][i]][1] + matrix[mArray[4][i]][2];
      mValueArray[5] += -matrix[mArray[5][i]][0] + matrix[mArray[5][i]][1] - matrix[mArray[5][i]][2];
      mValueArray[6] += matrix[mArray[6][i]][0] - matrix[mArray[6][i]][1] - matrix[mArray[6][i]][2];
      mValueArray[7] += -matrix[mArray[7][i]][0] - matrix[mArray[7][i]][1] - matrix[mArray[7][i]][2];
    }

    for (int i=0; i < 8; i++) {
      System.out.println(mValueArray[i]);
    }

    for (int i=m; i < n; i++) {
      for (int j=0; j < m; j++) {
        if (mValueArray[0] < mValueArray[0]-matrix[mArray[0][j]][0]-matrix[mArray[0][j]][1]-matrix[mArray[0][j]][1]+matrix[i][0]+matrix[i][1]+matrix[i][1]) {
          mValueArray[0] = mValueArray[0]-matrix[mArray[0][j]][0]-matrix[mArray[0][j]][1]-matrix[mArray[0][j]][1]+matrix[i][0]+matrix[i][1]+matrix[i][1];
          mArray[0][j] = i;
        }

        if (mValueArray[1] > mValueArray[1]+matrix[mArray[1][j]][0]-matrix[mArray[1][j]][1]-matrix[mArray[1][j]][1]-matrix[i][0]+matrix[i][1]+matrix[i][1]) {
          mValueArray[1] = mValueArray[1]+matrix[mArray[1][j]][0]-matrix[mArray[1][j]][1]-matrix[mArray[1][j]][1]-matrix[i][0]+matrix[i][1]+matrix[i][1];
          mArray[1][j] = i;
        }

        if (mValueArray[2] > mValueArray[2]-matrix[mArray[2][j]][0]+matrix[mArray[2][j]][1]-matrix[mArray[2][j]][1]+matrix[i][0]-matrix[i][1]+matrix[i][1]) {
          mValueArray[2] = mValueArray[2]-matrix[mArray[2][j]][0]+matrix[mArray[2][j]][1]-matrix[mArray[2][j]][1]+matrix[i][0]-matrix[i][1]+matrix[i][1];
          mArray[2][j] = i;
        }

        if (mValueArray[3] > mValueArray[3]-matrix[mArray[3][j]][0]-matrix[mArray[3][j]][1]+matrix[mArray[3][j]][1]+matrix[i][0]+matrix[i][1]-matrix[i][1]) {
          mValueArray[3] = mValueArray[3]-matrix[mArray[3][j]][0]-matrix[mArray[3][j]][1]+matrix[mArray[3][j]][1]+matrix[i][0]+matrix[i][1]-matrix[i][1];
          mArray[3][j] = i;
        }

        if (mValueArray[4] > mValueArray[4]+matrix[mArray[4][j]][0]+matrix[mArray[4][j]][1]-matrix[mArray[4][j]][1]-matrix[i][0]-matrix[i][1]+matrix[i][1]) {
          mValueArray[4] = mValueArray[4]+matrix[mArray[4][j]][0]+matrix[mArray[4][j]][1]-matrix[mArray[4][j]][1]-matrix[i][0]-matrix[i][1]+matrix[i][1];
          mArray[4][j] = i;
        }

        if (mValueArray[5] > mValueArray[5]+matrix[mArray[5][j]][0]-matrix[mArray[5][j]][1]+matrix[mArray[5][j]][1]-matrix[i][0]+matrix[i][1]-matrix[i][1]) {
          mValueArray[5] = mValueArray[5]+matrix[mArray[5][j]][0]-matrix[mArray[5][j]][1]+matrix[mArray[5][j]][1]-matrix[i][0]+matrix[i][1]-matrix[i][1];
          mArray[5][j] = i;
        }

        if (mValueArray[6] > mValueArray[6]-matrix[mArray[6][j]][0]+matrix[mArray[6][j]][1]+matrix[mArray[6][j]][1]+matrix[i][0]-matrix[i][1]-matrix[i][1]) {
          mValueArray[6] = mValueArray[6]-matrix[mArray[6][j]][0]+matrix[mArray[6][j]][1]+matrix[mArray[6][j]][1]+matrix[i][0]-matrix[i][1]-matrix[i][1];
          mArray[6][j] = i;
        }

        if (mValueArray[7] > mValueArray[7]+matrix[mArray[7][j]][0]+matrix[mArray[7][j]][1]+matrix[mArray[7][j]][1]-matrix[i][0]-matrix[i][1]-matrix[i][1]) {
          mValueArray[7] = mValueArray[7]+matrix[mArray[7][j]][0]+matrix[mArray[7][j]][1]+matrix[mArray[7][j]][1]-matrix[i][0]-matrix[i][1]-matrix[i][1];
          mArray[7][j] = i;
        }
      }
    }

    for (int i=0; i < 8; i++) {
      System.out.println(mValueArray[i]);

      if (Math.abs(mValueArray[i]) > ans) {
        ans = Math.abs(mValueArray[i]);
      }
    }

    System.out.println(ans);
  }
}
