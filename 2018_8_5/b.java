import java.util.*;

public class b {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    String str = sc.next();
    boolean flag = true;

    if (!(String.valueOf(str.charAt(0)).equals("A"))) {
      flag = false;
    } else if (Character.isUpperCase(str.charAt(1)) || Character.isUpperCase(str.charAt(str.length()-1))) {
      flag = false;
    } else {
      int count = 0;

      for (int i = 2; i < str.length()-1; i++) {
        if (String.valueOf(str.charAt(i)).equals("C")) {
          count++;
        } else if (Character.isUpperCase(str.charAt(i))) {
          flag = false;
        }
      }

      if (count != 1) {
        flag = false;
      }
    }

    if (flag == true) {
      System.out.println("AC");
    } else {
      System.out.println("WA");
    }
  }
}
