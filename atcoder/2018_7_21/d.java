import java.util.*;

class Demand implements Comparable {
    int from;
    int to;

    public int compareTo(Object other) {
        Demand otherDemand = (Demand) other;
        return to - otherDemand.to;
    }
}

public class d {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();

        Demand[] demands = new Demand[m];

        for (int i = 0; i < m; i++) {
            Demand demand = new Demand();
            demand.from = sc.nextInt();
            demand.to = sc.nextInt();
            demands[i] = demand;
        }

        Arrays.sort(demands);

        int ans = 0;
        int lastBridge = -1;

        for (int i = 0; i < m; i++) {
            if (demands[i].from > lastBridge) {
                lastBridge = demands[i].to - 1;
                ans++;
            }
        }

        System.out.println(ans);
    }

}
