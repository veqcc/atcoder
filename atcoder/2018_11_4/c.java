import java.util.*;

class Pair implements Comparable {
    int p;
    int y;
    int shiIdx;

    Pair(int p, int y, int shiIdx) {
        this.p = p;
        this.y = y;
        this.shiIdx = shiIdx;
    }

    @Override
    public int compareTo(Object o) {
        Pair other = (Pair) o;
        return this.y - other.y;
    }
}


public class c {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int M = sc.nextInt();

        Pair[] pairs = new Pair[M];
        for (int i = 0; i < M; i++) {
            int p = sc.nextInt();
            int y = sc.nextInt();
            pairs[i] = new Pair(p, y, i);
        }

        Arrays.sort(pairs);

        int[] count = new int[N+1];
        String[] ids = new String[M];

        for (int i = 0; i < M; i++) {
            Pair pair = pairs[i];
            count[pair.p]++;
            int num = count[pair.p];

            // pair.pを6桁に変換 + numを6桁に変換 = id
            ids[pair.shiIdx] = String.format("%06d", pair.p) + String.format("%06d", num);
        }

        for (int i = 0; i < M; i++) {
            System.out.println(ids[i]);
        }
    }
}