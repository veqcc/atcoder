import java.util.*;

public class a {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int N = sc.nextInt();
    int x = sc.nextInt();
    int[] a = new int[N];

    for (int i = 0; i < N; i++) {
      a[i] = sc.nextInt();
    }

    Arrays.sort(a);
    int ans = 0;

    for (int i = 0; i < N; i++) {
      x -= a[i];

      if (x < 0) {
        ans = i;
        break;
      } else if (x == 0) {
        ans = i+1;
      }
    }

    if (x > 0) {
      ans = N - 1;
    }

    System.out.println(ans);
  }
}
