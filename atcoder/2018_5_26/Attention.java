import java.util.*;

// コメントした部分のコードでは、TLEになる。

// public class Attention {
//   public static void main(String args[]) {
//     Scanner sc = new Scanner(System.in);
//
//     int N = sc.nextInt();
//     String str = sc.next();
//
//     int min_count = N;
//     int count;
//
//     for (int i=0; i < N; i++) {
//       if (i == 0) {
//         String str1 = str.substring(1);
//         count = str1.length() - str1.replaceAll("E", "").length();
//         min_count = Math.min(min_count, count);
//       } else if (i == N-1) {
//         String str2 = str.substring(0, N-1);
//         count = str2.length() - str2.replaceAll("W", "").length();
//         min_count = Math.min(min_count, count);
//       } else {
//         count = 0;
//
//         String str1 = str.substring(0, i);
//         String str2 = str.substring(i+1);
//
//         count += str1.length() - str1.replaceAll("W", "").length();
//         count += str2.length() - str2.replaceAll("E", "").length();
//
//         min_count = Math.min(min_count, count);
//       }
//     }
//
//     System.out.println(min_count);
//   }
// }


public class Attention {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int N = sc.nextInt();
    String str = sc.next();
    int min_count = N;
    int count;

    String str1 = str.substring(1);
    count = str1.length() - str1.replaceAll("E", "").length();
    min_count = Math.min(min_count, count);

    for (int i=1; i < N; i++) {
      if (str.substring(i-1, i).equals("W") && str.substring(i, i+1).equals("W")) {
        count++;
      }

      if (str.substring(i-1, i).equals("E") && str.substring(i, i+1).equals("E")) {
        count--;
      }

      min_count = Math.min(min_count, count);
    }

    System.out.println(min_count);
  }
}
