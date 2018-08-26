import java.util.*;

public class d {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    int[] a = new int[n];
    long sum = 0;

    for (int i = 0; i < n; i++) {
      a[i] = sc.nextInt();
      sum += i+1;
    }

    sum = sum / 2 + 1;

    int[] count = new int[n];
    int tmp = 0;

    for (int i = 0; i < n; i++) {
      if (i % 2 != 0) {
        count[n-tmp-1] = i+1;
        tmp++;
      } else {
        count[tmp] = i+1;
      }
    }

    int[][] new_array = new int[n][2];
    for (int i = 0; i < n; i++) {
      new_array[i][0] = a[i];
      new_array[i][1] = count[i];
    }

    Arrays.sort(new_array, new Comparator<int[]>() {
        @Override
        public int compare(int[] o1, int[] o2) {
            return o1[0] - o2[0];
        }
    });

    long tmp_count = 0;
    int ans = 0;

    for (int i = 0; i < n; i++) {
      tmp_count += (long)new_array[i][1];

      if (tmp_count >= sum) {
        ans = new_array[i][0];
        break;
      }
    }

    System.out.println(ans);
  }
}
