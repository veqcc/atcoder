import java.util.*;
import java.awt.*;

public class a {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();
        String s = sc.next();
        String t = sc.next();

        int l = gcd(m, n);
        int nl = m / l;
        int ml = n / l;
        long ans = (long)nl * (long)n;
        long np = 0;
        int ni = 0;
        long mp = 0;
        int mi = 0;
        while (true) {
            if (np == mp) {
                if (s.charAt(ni) != t.charAt(mi)) {
                    ans = -1;
                    break;
                }
                np += nl;
                ni++;
            } else if (np > mp) {
                mp += ml;
                mi++;
            } else if (np < mp) {
                np += nl;
                ni++;
            }

            if (ni >= n || mi >= m) {
                break;
            }
        }

        System.out.println(ans);
    }

    public static int gcd(int m, int n) {
        if(m < n) return gcd(n, m);
        if(n == 0) return m;
        return gcd(n, m % n);
    }
}