import java.util.*;
import java.awt.*;

public class b {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    String[] words = new String[n];
    String ans = "Yes";

    for (int i = 0; i < n; i++) {
      words[i] = sc.next();

      for (int j = 0; j < i; j++) {
        if (words[j].equals(words[i])) {
          ans = "No";
        }
      }
    }

    for (int i = 0; i < n-1; i++) {
      if (words[i].charAt(words[i].length()-1) != words[i+1].charAt(0)) {
        ans = "No";
      }
    }

    System.out.println(ans);
  }
}
