import java.util.*;
import java.awt.*;

public class b {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] A = new int[n];
        int m = 100000007;

        for (int i = 0; i < n; i++) {
            A[i] = sc.nextInt();
        }

        int[] eye = new int[n+1];
        eye[0] = 1;
        for (int i = 1; i <= n; i++) {
            eye[i] = (eye[i-1] * i) % m;
        }

        int[] tmp = new int[n+1];
        for (int i = 1; i <= n; i++) {
           tmp[i] = (tmp[i-1] + eye[n] / i) % m;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = (ans + A[i] * (tmp[i+1] + tmp[n-i] - eye[n])) % m;
        }

        System.out.println(ans);
    }
}