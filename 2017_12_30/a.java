import java.util.*;
import java.awt.*;

public class a {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        int q = sc.nextInt();
        int m = 100000;
        boolean[] isPrime = new boolean[m+1];
        boolean[] nextPrime = new boolean[m+1];
        for (int i = 1; i <= m; i++) {
            if (prime(i)) {
                isPrime[i] = true;

                int tmp = i * 2 - 1;
                if (tmp <= m && prime(tmp)) {
                    nextPrime[tmp] = true;
                }
            }
        }

        int[] sum_count = new int[m+1];
        for (int i = 1; i <= m; i++) {
            sum_count[i] = sum_count[i-1];

            if (isPrime[i] && nextPrime[i]) {
                sum_count[i] += 1;
            }
        }

        int[] l = new int[q];
        int[] r = new int[q];
        for (int i = 0; i < q; i++) {
            l[i] = sc.nextInt();
            r[i] = sc.nextInt();
        }

        for (int i = 0; i < q; i++) {
            if (l[i] == 1) {
                System.out.println(sum_count[r[i]]);
            } else {
                System.out.println(sum_count[r[i]] - sum_count[l[i]-1]);
            }
        }
    }

    public static boolean prime(int x) {
        if (x == 1) return false;
        if (x == 2) return true;

        for (int i = 2; i <= (int)Math.sqrt(x) + 1; i++) {
            if (x % i == 0) return false;
        }
        return true;
    }
}