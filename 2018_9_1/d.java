import java.util.*;

public class d {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int l = sc.nextInt();
    int node = 3;

    while (true) {
      if ((int)Math.pow(2, node-2) > l) {
        break;
      } else {
        node++;
      }
    }

    int[] a = new int[node-1];
    int tmp_node = node - 1;
    int count = 0;

    while (true) {
      if (l - (int)Math.pow(2, tmp_node-2) >= 0) {
        System.out.println(tmp_node);
        l -= (int)Math.pow(2, tmp_node-2);
        a[tmp_node-1] = 1;
        tmp_node--;
        count++;
      }

      if (l == 0) {
        break;
      }
    }

    System.out.println(node + " " + (count + (int)Math.pow(2, node-3)));
  }
}
