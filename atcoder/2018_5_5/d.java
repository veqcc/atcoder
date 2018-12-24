import java.util.*;

public class d {
  public static boolean prime(int num) {
    boolean res = true;
    for (int i=2; i < num; i++) {
      if (num % i == 0) {
        res = false;
        break;
      }
    }

    return res;
  }

  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    int[] ans = new int[n];
    int point = 0;

    for (int i=6; i < 55555; i+=5) {
      if (prime(i) == true) {
        ans[point] = i;
        point++;
      }

      if (point == n) {
        break;
      }
    }

    for (int i=0; i < n; i++) {
      System.out.println(ans[i] + " ");
    }
  }
}
