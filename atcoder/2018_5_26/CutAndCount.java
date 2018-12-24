import java.util.*;

public class CutAndCount {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int N = sc.nextInt();
    String str = sc.next();
    int max_count = 0;
    int count;
    char alphabet;

    for (int i = 0; i <= N; i++) {
      count = 0;
      alphabet = 'a';

      String str1 = str.substring(0, i);
      String str2 = str.substring(i, N);

      for (int j = 0; j <= 25; j++) {
        char tmp_alpha = alphabet++;
        if (str1.contains(String.valueOf(tmp_alpha)) && str2.contains(String.valueOf(tmp_alpha))) {
          count += 1;
        }
      }

      max_count = Math.max(max_count, count);
    }

    System.out.println(max_count);
  }
}
