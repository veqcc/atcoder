import java.util.*;

public class d {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int N = sc.nextInt();
    int M = sc.nextInt();
    int Q = sc.nextInt();

    int[][] n_matrix = new int[N+1][N+1];

    for (int i = 0; i < M; i++) {
      n_matrix[sc.nextInt()][sc.nextInt()]++;
    }

    for (int i = N-1; i > 0; i--) {
      for (int j = 1; j <= N; j++) {
        n_matrix[i][j] += n_matrix[i+1][j] + n_matrix[i][j-1] - n_matrix[i+1][j-1];
      }
    }

    int[] answers = new int[Q];

    for (int i = 0; i < Q; i++) {
      int ans = n_matrix[sc.nextInt()][sc.nextInt()];
      answers[i] = ans;
    }

    for (int i = 0; i < Q; i++) {
      System.out.println(answers[i]);
    }
  }
}
