import java.util.*;

public class d {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int N = sc.nextInt();
    int color = sc.nextInt();
    int[][] matrix = new int[N][N];
    int[][] penalty = new int[color][color];

    long min_penalty = Integer.MAX_VALUE;
    long tmp_penalty;
    int first_color;
    int second_color;
    int third_color;

    for (int i=0; i < color; i++) {
      for (int j=0; j < color; j++) {
        penalty[i][j] = sc.nextInt();
      }
    }

    for (int i=0; i < N; i++) {
      for (int j=0; j < N; j++) {
        matrix[i][j] = sc.nextInt();
      }
    }

    for (int i=0; i < color; i++) {
      first_color = i;

      for (int j=0; j < color; j++) {
        if (j == i) {
          continue;
        } else {
          second_color = j;

          for (int k=0; k < color; k++) {
            if (k == i || k == j) {
              continue;
            } else {
              third_color = k;
              tmp_penalty = 0;

              for (int l = 0; l <= N-1; l++) {
                for (int m = 0; m <= l; m++) {
                  if (l%3 == 0) {
                    tmp_penalty += penalty[matrix[m][l-m]-1][first_color];
                  } else if (l%3 == 1) {
                    tmp_penalty += penalty[matrix[m][l-m]-1][second_color];
                  } else {
                    tmp_penalty += penalty[matrix[m][l-m]-1][third_color];
                  }
                }
              }

              for (int l = 0; l < N-1; l++) {
                for (int m = 0; m <= l; m++) {
                  if ((2*N-2-l)%3 == 0) {
                    tmp_penalty += penalty[matrix[N-1-m][N-1-l+m]-1][first_color];
                  } else if ((2*N-2-l)%3 == 1) {
                    tmp_penalty += penalty[matrix[N-1-m][N-1-l+m]-1][second_color];
                  } else {
                    tmp_penalty += penalty[matrix[N-1-m][N-1-l+m]-1][third_color];
                  }
                }
              }

              if (tmp_penalty < min_penalty) {
                min_penalty = tmp_penalty;
              }
            }
          }
        }
      }
    }

    System.out.println(min_penalty);
  }
}
