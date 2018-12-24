import java.util.*;
import java.awt.*;

public class b {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int N = sc.nextInt();
    int M = sc.nextInt();
    int X = sc.nextInt();
    int Y = sc.nextInt();

    int x_max = Integer.MIN_VALUE;
    for (int i = 0; i < N; i++) {
      x_max = Math.max(x_max, sc.nextInt());
    }

    int y_min = Integer.MAX_VALUE;
    for (int i = 0; i < M; i++) {
      y_min = Math.min(y_min, sc.nextInt());
    }

    String ans = "No War";

    if (x_max >= y_min || x_max >= Y || y_min <= X) {
      ans = "War";
    }

    System.out.println(ans);
  }
}
