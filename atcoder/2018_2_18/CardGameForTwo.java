import java.util.*;

public class Main {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int N = sc.nextInt();
    int[] aArray = new int[N];

    for (int i=0; i < N; i++) {
      aArray[i] = sc.nextInt();
    }

    Arrays.sort(aArray);

    int sumAlice = 0;
    int sumBob = 0;

    for (int i=1; i <= N; i++) {
      if (i % 2 != 0) {
        sumAlice += aArray[N-i];
      } else {
        sumBob += aArray[N-i];
      }
    }

    System.out.println(sumAlice - sumBob);
  }
}
