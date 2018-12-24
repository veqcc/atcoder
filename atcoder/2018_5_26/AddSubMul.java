import java.util.*;

public class AddSubMul {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int A = sc.nextInt();
    int B = sc.nextInt();

    int add = A + B;
    int sub = A - B;
    int mul = A * B;

    System.out.println(Math.max(add, Math.max(sub, mul)));
  }
}
