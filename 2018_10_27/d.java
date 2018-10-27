import java.util.*;
import java.awt.*;

public class d {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int k = -1;
        for (int i = 1; i < N; i++) {
            if (i * (i+1) == 2 * N) {
                k = i;
            }
        }
        if (N == 1) k=1;
        if (k == -1) {
            System.out.println("No");
        } else {
            System.out.println("Yes");

            int[][] ans = new int[k+1][k];
            int count = 1;

            for (int i = 0; i < k+1; i++) {
                for (int j = 0; j < k; j++) {
                    if (i == j+1) {
                        ans[i][j] = ans[i-1][j];
                    } else if ( i > j + 1) {
                        ans[i][j] = ans[i-1][j] + 1;
                    } else {
                        ans[i][j] = count;
                        count++;
                    }
                }
            }

            System.out.println(k+1);
            for (int i = 0; i < k+1; i++) {
                System.out.print(k);
                for (int j = 0; j < k; j++) {
                    System.out.print(' ');
                    System.out.print(ans[i][j]);
                }
                System.out.println("");
            }
        }
    }
}
