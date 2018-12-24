#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll ,int> P;
const ll inf=1e+18;

int N,M,T;
int A[100000];
ll D[100000],D2[100000];
vector<P> G[100000],rG[100000];

void dijkstra(ll *DD, vector<P> *GG){
    priority_queue < P, vector<P>, greater<P> > ue;
    for (int i = 0; i < N; i++) DD[i] = inf;
    DD[0]=0;
    ue.push(P(0,0));
    while (!ue.empty()) {
        P p = ue.top();
        ue.pop();
        int y = p.second;
        if (DD[y] != p.first) continue;
        for (int i = 0; i < GG[y].size(); i++) {
            int xx = GG[y].at(i).first;
            int yy = GG[y].at(i).second;
            if (DD[xx] > DD[y] + yy) {
                DD[xx] = DD[y] + yy;
                ue.push(P(DD[xx], xx));
            }
        }
    }
}

int main(){
    int a, b, c;
    cin >> N >> M >> T;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        a--,b--;
        G[a].push_back(P(b, c));
        rG[b].push_back(P(a, c));
    }

    dijkstra(D, G);
    dijkstra(D2, rG);

    ll sum, ans=0;
    for (int i = 0; i < N; i++) {
        sum = D[i] + D2[i];
        if (sum <= T) {
            ans = max(ans, (T - sum) * A[i]);
        }
    }

    cout << ans << endl;
    return 0;
}