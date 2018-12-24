import java.util.*;

public class c {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    long[] count = new long[5];

    for (int i = 0; i < n; i++) {
      String str = String.valueOf(sc.next().charAt(0));

      if (str.equals("M")) {
        count[0]++;
      } else if (str.equals("A")) {
        count[1]++;
      } else if (str.equals("R")) {
        count[2]++;
      } else if (str.equals("C")) {
        count[3]++;
      } else if (str.equals("H")) {
        count[4]++;
      }
    }

    long ans = 0;

    for (int i = 0; i < 3; i++) {
      for (int j = i+1; j < 4; j++) {
        for (int k = j+1; k < 5; k++) {
          ans += count[i] * count[j] * count[k];
        }
      }
    }

    System.out.println(ans);
  }
}
