import java.util.*;

public class c {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    long A = sc.nextLong();
    long B = sc.nextLong();
    int N = sc.nextInt();
    long A1 = 0;
    long B1 = 0;

    for (long i=0; i < A; i++) {
      A1 += Math.pow(10, i);
    }

    for (long i=0; i < B; i++) {
      B1 += Math.pow(10, i);
    }

    System.out.println((A1*B1)%N);
  }
}
