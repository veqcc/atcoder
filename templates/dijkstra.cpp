#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int N, M;
ll inf = 1e18;
typedef pair<int, ll> P;
ll cost[100000]; // total cost
vector<P> edge[100000]; // edge[a] is vector of P(b,c) ( witch means [a->b with cost c] )

// Dijkstra
void dijkstra(ll *D, vector<P> *G){
    // max priority queue ordered by first element
    // priority_queue < P > q;
    // min priority queue ordered by first element
    priority_queue < P, vector<P>, greater<P> > q;
    for (int i = 0; i < N; i++) D[i] = inf;
    D[0]=0;
    q.push(P(0,0));
    while (!q.empty()) {
        P p = q.top();
        q.pop();
        ll y = p.second; // p.second means current node position
        if (D[y] != p.first) continue;
        for (int i = 0; i < G[y].size(); i++) {
            int node = G[y].at(i).first; // edge y->node
            ll cost = G[y].at(i).second; // cost of y->node
            if (D[node] > D[y] + cost) {
                D[node] = D[y] + cost;
                q.push(P(D[node], node)); // P(total cost, current node)
            }
        }
    }
}

int main() {
    N = 3;
    M = 3;

    for (int i = 0; i < M; i++) {
        edge[i%2].push_back(P(i, 1));
    }

    dijkstra(cost, edge);

    cout << cost[2] << "\n"; // 1
    return 0;
}