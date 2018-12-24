import java.util.*;

public class c {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    String S = sc.next();
    long K = sc.nextLong();

    int one_length = 0;
    String next_string = "1";

    for (int i = 0; i < S.length(); i++) {
      if (S.charAt(i) != '1') {
        one_length = i;
        next_string = String.valueOf(S.charAt(i));
        break;
      }
    }

    String ans = "";

    if (K <= (long)one_length) {
      ans = "1";
    } else {
      ans = next_string;
    }

    System.out.println(ans);
  }
}
