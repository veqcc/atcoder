import java.util.*;

public class Main {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    int answer = Integer.MAX_VALUE;
    int count;
    long A;

    for (int i = 0; i < n; i++) {
      A = sc.nextInt();
      count = 0;

      while (A % 2 == 0) {
        A = A / 2;
        count += 1;
      }

      if (count < answer) {
        answer = count;
      }
    }

    System.out.println(answer);
  }
}
