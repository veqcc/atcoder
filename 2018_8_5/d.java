import java.util.*;

public class d {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    String str = sc.next();
    int length = str.length();

    long A = 0;
    long AB = 0;
    long ABC = 0;
    long Qcount = 0;

    for (int i = 0; i < length; i++) {
      String currentStr = String.valueOf(str.charAt(i));

      if (currentStr.equals("A")) {
        A += (long)Math.pow(3, Qcount);
      } else if (currentStr.equals("B")) {
        AB += A;
      } else if (currentStr.equals("C")) {
        ABC +=  AB;
      } else if (currentStr.equals("?")) {
        ABC = ABC * 3 + AB;
        AB = AB * 3 + A;
        A = A * 3 + (long)Math.pow(3, Qcount);
        Qcount++;
      }
    }

    System.out.println(ABC % 1000000007);
  }
}
