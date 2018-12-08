#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;
const int INF=1000000007;

struct edge {
    int to;
    int cost;
};

typedef pair <int, int> P;
int V, E;
vector <edge> G[100000];
int d[100000];

void dijkstra(int s) {
    priority_queue<P, vector<P>, greater<P>> q;
    fill(d, d+V, INF);
    d[s] = 0;
    q.push(P(0, s));

    while (!q.empty()) {
        P p = q.top();
        q.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (int i = 0; i < G[v].size(); i++) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                q.push(P(d[e.to], e.to));
            }
        }
    }
}

int main() {
    return 0;
}