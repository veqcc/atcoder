import java.util.*;
import java.awt.*;

public class c {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextLong();
        }

        Arrays.sort(a);

        long ans = 0;
        if (n % 2 == 0) {
           for (int i = 0; i < n/2 - 1; i++) {
               ans = ans + a[n/2 + i] + a[n/2 + i + 1] - 2*a[i];
           }
           ans = ans + a[n-1] - a[n/2 -1];
        } else {
            for (int i = 0; i < n/2 - 1; i++) {
                ans = ans + a[n/2 + i + 1] + a[n/2 + i + 2] - 2*a[i];
            }
            ans = ans + a[n-1] - a[n/2 -1];
            ans += Math.max(a[n/2 + 1] - a[n/2], a[n/2] - a[n/2 - 1]);
        }

        System.out.println(ans);
    }
}
