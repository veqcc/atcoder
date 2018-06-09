import java.util.*;

public class SomeSums {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int N = sc.nextInt();
    int A = sc.nextInt();
    int B = sc.nextInt();
    int count = 0;
    int sum;

    for (int i=1; i <= N; i++) {
      String stringN = String.valueOf(i);
      String[] nArray = stringN.split("");

      sum = 0;
      for (int j=0; j < nArray.length; j++) {
        sum += Integer.parseInt(nArray[j]);
      }

      if (sum >= A && sum <= B) {
        count += i;
      }
    }

    System.out.println(count);
  }
}
