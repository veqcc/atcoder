import java.util.*;

public class b {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    int ans = 0;

    if (n >= 105 && n < 135) {
      ans = 1;
    } else if (n >= 135 && n < 165) {
      ans = 2;
    } else if (n >= 165 && n < 189) {
      ans = 3;
    } else if (n >= 189 && n < 195) {
      ans = 4;
    } else if (n >= 195) {
      ans = 5;
    }

    System.out.println(ans);
  }
}
