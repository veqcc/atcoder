import java.util.*;
import java.io.*;

public class c {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    long n = sc.nextLong();
    long tmp = 1;
    String ans = "";

    while (true) {
      if ((n-tmp) % (tmp*(-2)) == 0) {
        ans += "1";
        n -= tmp;
      } else {
        ans += "0";
      }

      if (n == 0) break;
      tmp *= -2;
    }

    StringBuffer sb = new StringBuffer(ans);
		String dst = sb.reverse().toString();
		System.out.println(""+dst);
  }
}
