import java.util.*;

public class b {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    String str = sc.next();
    int w = sc.nextInt();

    for (int i=0; i < str.length(); i+=w) {
      System.out.print(str.charAt(i));
    }
  }
}
