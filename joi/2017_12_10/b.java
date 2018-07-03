import java.util.*;

public class b {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    int[] a = new int[n];

    for (int i=0; i < n; i++) {
      a[i] = sc.nextInt();
    }

    int ans = 1;
    int count = 1;

    for (int i=0; i < n; i++) {
      if (a[i] == 1) {
        count++;
      } else {
        ans = Math.max(ans, count);
        count = 1;
      }
    }


    System.out.println(Math.max(ans, count));
  }
}
