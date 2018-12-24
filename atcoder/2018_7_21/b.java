import java.util.*;

public class b {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    String s = sc.next();
    String t = sc.next();

    String ans = "No";

    for (int i=0; i < s.length(); i++) {
      int tmp_ans = 0;

      for (int j=0; j < s.length(); j++) {
        if (t.charAt(j) != s.charAt((i+j)%(s.length()))) {
          tmp_ans = 1;
        }
      }

      if (tmp_ans == 0) {
        ans = "Yes";
        break;
      }
    }

    System.out.println(ans);
  }
}
