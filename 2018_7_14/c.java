import java.util.*;

public class c {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int N = sc.nextInt();
    long P = sc.nextLong();
    int[] A = new int[N];

    for (int i = 0; i < N; i++) {
      A[i] = sc.nextInt();
    }

    int start = 0;
    int goal = 0;
    long tmp = A[0];
    boolean flag = false;

    while (start < N) {
      if (tmp < P) {
        if (goal == N-1) break;

        goal++;
        tmp *= (long)A[goal];
      } else if (tmp > P) {
        tmp /= (long)A[start];
        start++;
      } else {
        flag = true;
        break;
      }
    }

    if (flag) {
      System.out.println("Yay!");
    } else {
      System.out.println(":(");
    }
  }
}
