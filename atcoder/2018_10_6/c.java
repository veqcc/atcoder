import java.util.*;
import java.awt.*;

public class c {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] x = new int[n];
        int[] y = new int[n];
        int[] h = new int[n];

        for (int i = 0; i < n; i++) {
            x[i] = sc.nextInt();
            y[i] = sc.nextInt();
            h[i] = sc.nextInt();
        }

        int ans = 0;
        int tx = -1;
        int ty = -1;

        for (int px = 0; px <= 100; px++) {
            for (int py = 0; py <= 100; py++) {
                boolean f = true;
                int ph = 0;

                for (int i = 0; i < n; i++) {
                    if (h[i] > 0) {
                        ph = h[i] + Math.abs(x[i]-px) + Math.abs(y[i]-py);
                        break;
                    }
                }

                for (int i = 1; i < n; i++) {
                    int tmp = ph - h[i] - Math.abs(x[i]-px) - Math.abs(y[i]-py);
                    if (tmp > 0) {
                        f = false;
                    } else if (tmp < 0) {
                        if (h[i] != 0) {
                            f = false;
                        }
                    }
                }

                if (f == true) {
                   ans = ph;
                   tx = px;
                   ty = py;
                }
            }
        }

        System.out.println(tx + " " + ty + " " + ans);
    }
}