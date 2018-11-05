import java.util.*;
import java.awt.*;

public class b {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int t = sc.nextInt();
        int a = sc.nextInt();
        int[] h = new int[n];
        for (int i = 0; i < n; i++) {
            h[i] = sc.nextInt();
        }

        double ans = Math.abs(a - t + h[0]*0.006);
        int an = 1;
        for (int i = 1; i < n; i++) {
            if (Math.abs(a - t + h[i]*0.006) < ans) {
                ans = Math.abs(a - t + h[i]*0.006);
                an = i+1;
            }
        }

        System.out.println(an);
    }
}
