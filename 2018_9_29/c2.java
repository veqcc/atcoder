import java.util.*;
import java.awt.*;

public class c2 {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    int[] even = new int[100000];
    int[] odd = new int[100000];

    for (int i = 0; i < n/2; i++) {
      odd[sc.nextInt()-1]++;
      even[sc.nextInt()-1]++;
    }

    int odd_max_index = maxIndex(odd);
    int even_max_index = maxIndex(even);
    int odd_max = odd[odd_max_index];
    int even_max = even[even_max_index];

    int ans = 0;
    if (odd_max_index != even_max_index) {
      ans = n - odd_max - even_max;
    } else {
      odd[odd_max_index] = 0;
      even[even_max_index] = 0;

      odd_max_index = maxIndex(odd);
      even_max_index = maxIndex(even);

      ans = Math.min(n-odd_max-even[even_max_index], n-even_max-odd[odd_max_index]);
    }

    System.out.println(ans);
  }

  public static int maxIndex(int[] x) {
    int tmp = -1;
    int max_index = 0;

    for (int i = 0; i < x.length; i++) {
      if (x[i] > tmp) {
        tmp = x[i];
        max_index = i;
      }
    }

    return max_index;
  }
}
