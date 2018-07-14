import java.util.*;

public class b {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    long[] a = new long[n];
    long[] b = new long[n];
    long[] c = new long[n];
    long[] d = new long[n];

    for (int i = 0; i < n; i++) {
      a[i] = sc.nextLong();
      b[i] = sc.nextLong();
      c[i] = sc.nextLong();
      d[i] = sc.nextLong();
    }

    for (int i=0; i < n; i++) {
      int ans = 1; // true

      if (a[i] < b[i]) {
        ans = -1; // false
      } else if (d[i] < b[i]) {
        ans = -1; // false
      } else if ((a[i]%b[i]) > c[i]) {
        ans = -1; // false
      } else if (b[i] > c[i] + (long)1) {
        long tmp = d[i] % b[i];
        long init = a[i] % b[i];
        long diff = b[i] - c[i];
        if (diff > tmp && tmp != (long)0) {
          ans = -1; // false
        } else if (tmp != (long)0) {
          if (gcd(b[i], tmp) < diff) {
            ans = -1; // false
          }
        }
      }

      if (ans == 1) {
        System.out.println("Yes");
      } else {
        System.out.println("No");
      }
    }
  }

  private static long gcd(long m, long n) {
    if(m < n) return gcd(n, m);
    if(n == 0) return m;
    return gcd(n, m % n);
  }
}
