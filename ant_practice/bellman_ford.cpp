#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;
const int INF = 1000000007;

struct edge {
    int from;
    int to;
    int cost;
};

edge es[100000];
int d[100000];
int V, E;

void shortest_path(int s) {
    for (int i = 0; i < V; i++) d[i] = INF;
    d[s] = 0;

    while (true) {
        bool update = false;
        for (int i = 0; i < E; i++) {
            edge e = es[i];
            if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
                update = true;
            }
        }
        if (!update) break;
    }
}

bool find_negative_loop() {
    memset(d, 0, sizeof(d));
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < E; j++) {
            edge e = es[j];
            if (d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
                if (i == V - 1) return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> V >> E;

    for (int i = 0; i < E; i++) {
        cin >> es[i].from >> es[i].to >> es[i].cost;
    }

    shortest_path(0);

    for (int i = 0; i < V; i++) {
        cout << d[i] << endl;
    }

    cout << find_negative_loop() << endl;

    return 0;
}