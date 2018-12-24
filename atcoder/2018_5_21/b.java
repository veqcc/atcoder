import java.util.*;

public class b {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int x = sc.nextInt();
    int tmp_p = x;
    int res = 0;

    for (int i = 0; i < x; i ++) {
      if (x==1) {
        res = 1;
        break;
      }
      
      for (int j = 2; j < tmp_p; j++) {
        if ((int)Math.pow(i, j) <= x) {
          res = Math.max(res, (int)Math.pow(i, j));
        } else {
          tmp_p = j;
          break;
        }
      }
    }

    System.out.println(res);
  }
}
