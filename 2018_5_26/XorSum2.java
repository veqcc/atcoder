import java.util.*;

// TLEになってしまうのは解消されていない

public class XorSum2 {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int N = sc.nextInt();
    int count = 0;
    String[] bin;
    int[] nArray = new int[N];
    boolean f = true;

    for (int i=0; i < N; i++) {
      nArray[i] = sc.nextInt();
    }

    for (int i=0; i < N; i++) {
      int[] binary = new int[20];

      for (int j=i; j < N; j++) {
        bin = Integer.toBinaryString(nArray[j]).split("");

        for (int k=0; k < bin.length; k++) {
          binary[k] += Integer.parseInt(bin[bin.length-1-k]);

          if (binary[k] >= 2) {
            f = false;
            break;
          }
        }

        if (f == false) {
          f = true;
          break;
        }

        count++;
      }
    }

    System.out.println(count);
  }
}
