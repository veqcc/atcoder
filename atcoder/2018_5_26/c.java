import java.util.*;

public class c {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    int k = sc.nextInt();
    int q = sc.nextInt();
    int[] a = new int[n];

    for(int i=0; i<n; i++){
      a[i] = sc.nextInt();
    }

    int ans = (int)1e9;
    int count;
    int y;
    PriorityQueue<Integer> que = new PriorityQueue<>();
    PriorityQueue<Integer> ya = new PriorityQueue<>();

    for(int x : a) {
      count = 0;
      que.clear();
      ya.clear();

      for(int i=0; i<n; i++){
        que.add(a[i]);

        if(a[i] < x){
          que.clear();
        }

        if(k <= que.size()){
          count++;
          ya.add(que.poll());
        }
      }

      if(q <= count){
        y = 0;
        
        for(int i=0; i<q; i++){
          y = ya.poll();
        }

        ans = Math.min(ans, y-x);
      }
    }

    System.out.println(ans);
  }
}
