import java.util.*;

public class c {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    String s = sc.next();
    int K = sc.nextInt();

    int s_length = 0;
    for (int i=1; i <= s.length(); i++) {
      s_length += i;
    }

    String[] sArray = new String[s_length];

    int count = 0;

    for (int i=1; i <= s.length(); i++) {
      for (int j=0; j < s.length()-i+1; j++) {
        sArray[count] = s.substring(j, j+i);
        count++;
      }
    }

    // わからない

    System.out.println(sArray[0]);

  }
}
