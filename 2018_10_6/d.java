import java.util.*;
import java.awt.*;

public class d {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();
        int ans = m;

        for (int i = m/n; i > 0; i--) {
            if (m%i == 0) {
                ans = i;
                break;
            }
        }

        System.out.println(ans);
    }
}