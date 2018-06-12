import java.util.*;

public class b {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int a = sc.nextInt();
    int b = sc.nextInt();

    int c = b-a;
    int height = 0;

    for (int i=0; i < c; i++) {
      height += i;
    }

    System.out.println(height - a);
  }
}
