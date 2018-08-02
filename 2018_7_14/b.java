import java.util.*;

public class b {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    String N = sc.next();
    boolean baisuu2 = false;
    int baisuu3 = 0;
    int baisuu11 = 0;
    int inv = 1;

    if (Integer.parseInt(String.valueOf((N.charAt(N.length() - 1)))) % 2 == 0) {
      baisuu2 = true;
    }

    for (int i = 0; i < N.length(); i++) {
      baisuu3 += Integer.parseInt(String.valueOf(N.charAt(i))) % 3;
    }

    if (baisuu2 && (baisuu3 % 3 == 0)) {
      System.out.println("yES");
    } else {
      System.out.println("nO");
    }

    for (int i = 0; i < N.length(); i++) {
      baisuu11 += Integer.parseInt(String.valueOf(N.charAt(i))) * inv;
      inv *= -1;
    }

    if (baisuu11 % 11 == 0) {
      System.out.println("yES");
    } else {
      System.out.println("nO");
    }
  }
}
