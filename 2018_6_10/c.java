import java.util.*;

public class c {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int N = sc.nextInt();
    int[] count_array = new int[N+1];
    int[] coins = {1, 6, 9, 36, 81, 216, 729, 1296, 6561, 7776, 46656, 59049, 279936, 531441};
    int tmp;

    for (int i=0; i <= N; i++) {
      count_array[i] = i;
    }

    for (int i=1; i < coins.length; i++) {
      for (int j=0; j <= N-coins[i]; j++) {
        if (count_array[j+coins[i]] > count_array[j] + 1) {
          count_array[j+coins[i]] = count_array[j] + 1;
        }
      }
    }

    System.out.println(count_array[N]);
  }
}
