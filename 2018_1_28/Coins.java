import java.util.*;

public class Main {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int A = sc.nextInt();
    int B = sc.nextInt();
    int C = sc.nextInt();
    int N = sc.nextInt();
    int count = 0;

    for (int i = 0; i < A+1; i++) {
      if (N - i * 500 < 0) {
        break;
      }

      for (int j = 0; j < B+1; j++) {
        if (N - i * 500 - j * 100 < 0) {
          break;
        }

        for (int k = 0; k < C+1; k++) {
          if (N - i * 500 - j * 100 - k * 50 < 0) {
            break;
          } else if (N - i * 500 - j * 100 - k * 50 == 0) {
            count += 1;
          }
        }
      }
    }

    System.out.println(count);
  }
}
