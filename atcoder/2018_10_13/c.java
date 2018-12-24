import java.util.*;
import java.awt.*;

public class c {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] ab = new int[2 * n];

        for (int i = 0; i < n; i++) {
            ab[i*2] = sc.nextInt();
            ab[i*2 + 1] = sc.nextInt();
        }

        Arrays.sort(ab);

        long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += ab[i];
        }

        System.out.println(ans);
    }
}