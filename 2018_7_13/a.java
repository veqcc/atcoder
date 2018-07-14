import java.util.*;

public class a {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    int count = 0;
    int tmpColor = -1;
    int ans = 0;

    for (int i=0; i < n; i++) {
      int color = sc.nextInt();

      if (color == tmpColor) {
        count++;
      } else {
        count = 0;
      }

      if (count % 2 == 1) {
        ans++;
      }

      tmpColor = color;
    }

    System.out.println(ans);
  }
}
