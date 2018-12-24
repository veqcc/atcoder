import java.util.*;
import java.awt.*;

public class c {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    String s = sc.next();
    String t = sc.next();

    String ans = "Yes";

    for (char a = 'a'; a <= 'z'; a++) {
      char s_tmp = 'A';

      for (int i = 0; i < s.length(); i++) {
        if (s.charAt(i) == a) {
          if (s_tmp == 'A') {
            s_tmp = t.charAt(i);
          } else if (s_tmp == t.charAt(i)) {
            continue;
          } else {
            ans = "No";
            break;
          }
        }
      }

      char t_tmp = 'A';

      for (int i = 0; i < s.length(); i++) {
        if (t.charAt(i) == a) {
          if (t_tmp == 'A') {
            t_tmp = s.charAt(i);
          } else if (t_tmp == s.charAt(i)) {
            continue;
          } else {
            ans = "No";
            break;
          }
        }
      }
    }

    System.out.println(ans);
  }
}
