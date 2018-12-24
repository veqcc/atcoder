import java.util.*;
import java.awt.*;

public class c {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    int[] even = new int[n/2];
    int[] odd = new int[n/2];

    for (int i = 0; i < n/2; i++) {
      odd[i] = sc.nextInt();
      even[i] = sc.nextInt();
    }

    Arrays.sort(odd);
    Arrays.sort(even);

    int odd_first = odd[0];
    int even_first = even[0];
    int odd_second = -1;
    int even_second = -1;

    int odd_first_count = 0;
    int even_first_count = 0;
    int odd_second_count = 0;
    int even_second_count = 0;

    for (int i = 0; i < n/2; i++) {
      if (odd[i] == odd_first) {
        odd_first_count++;
      } else {
        break;
      }
    }
    for (int i = 0; i < n/2; i++) {
      if (even[i] == even_first) {
        even_first_count++;
      } else {
        break;
      }
    }

    int ans = 0;

    if (odd_first != even_first) {
      ans = n - odd_first_count - even_first_count;
    } else {
      if (odd_first_count < n/2) {
        odd_second = odd[odd_first_count];

        for (int i = 0; i < n/2; i++) {
          if (odd[i] == odd_first) {
            continue;
          } else if  (odd[i] == odd_second) {
            odd_second_count++;
          } else {
            break;
          }
        }
      }

      if (even_first_count < n/2) {
        even_second = even[even_first_count];

        for (int i = 0; i < n/2; i++) {
          if (even[i] == even_first) {
            continue;
          } else if  (even[i] == even_second) {
            even_second_count++;
          } else {
            break;
          }
        }
      }

      ans = Math.min(n - odd_first_count - even_second_count, n - odd_second_count - even_first_count);
    }

    System.out.println(ans);
  }
}
