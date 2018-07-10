import java.util.*;

public class d {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    int[] a = new int[n];
    int[] b = new int[n];
    int[] binary = new int[30];
    int ans = 0;

    for (int i=0; i<n; i++){
      a[i] = sc.nextInt();
    }

    for (int i=0; i<n; i++){
      b[i] = sc.nextInt();
    }

    for (int i=0; i<30; i++) {
      int T = (int)Math.pow(2, i+1);
      int count = 0;

      for (int j=0; j < n; j++) {
        a[j] = a[j] % T;
        b[j] = b[j] % T;
      }

      Arrays.sort(b);

      // このfor文の中身がバグってる。int配列の、特定の範囲にある要素数をどう出力するんじゃ。。。
      for (int j=0; j < n; j++) {
        int from = 0;
        int to = 0;

        from = Arrays.binarySearch(b, T-a[j]);
        to = Arrays.binarySearch(b, 2*T-a[j]);
        count += to - from;

        from = Arrays.binarySearch(b, 3*T-a[j]);
        to = Arrays.binarySearch(b, 4*T-a[j]);
        count += to - from;
      }

      binary[i] = count;
    }

    for (int i=0; i<30; i++) {
      ans += (binary[i] % 2) * Math.pow(2, i);
    }

    System.out.println(ans);
  }
}
