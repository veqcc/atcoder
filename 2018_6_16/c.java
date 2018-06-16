import java.util.*;

public class c {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int N = sc.nextInt();
    int count = 0;
    int number;

    for (int i=0; i < N; i++) {
      number = sc.nextInt();

      while (number%2 == 0) {
        count++;
        number = number / 2;
      }
    }

    System.out.println(count);
  }
}
