import java.util.*;
import java.awt.*;

public class No133 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] A = new int[n];
        int[] B = new int[n];

        for (int i = 0; i < n; i++) {
            A[i] = sc.nextInt();
        }
        for (int i = 0; i < n; i++) {
            B[i] = sc.nextInt();
        }

        int[][] one = {{1}};
        int[][] two = {
                {1, 2},
                {2, 1}
        };
        int[][] three = {
                {1,2,3},
                {1,3,2},
                {2,1,3},
                {2,3,1},
                {3,2,1},
                {3,1,2}
        };

        int[][] numbers = one;

        if (n == 1) {
            numbers = one;
        } else if (n == 2) {
            numbers = two;
        } else if (n == 3) {
            numbers = three;
        }

        int real_win_count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int tmp_win_count = 0;

                for (int k = 0; k < n; k++) {
                    if (A[numbers[i][k]] > B[numbers[j][k]]) {
                        tmp_win_count++;
                    }
                }

                if (tmp_win_count > n/2) {
                    real_win_count++;
                }
            }
        }

        System.out.println(real_win_count / n);
    }
}
