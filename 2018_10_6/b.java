import java.util.*;
import java.awt.*;

public class b {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int T = sc.nextInt();
        int ans = 1001;

        for (int i = 0; i < N; i++) {
            int c = sc.nextInt();
            int t = sc.nextInt();

            if (t <= T) {
                ans = Math.min(ans, c);
            }
        }

        if (ans == 1001) {
            System.out.println("TLE");
        } else {
            System.out.println(ans);
        }
    }
}