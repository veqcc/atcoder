#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

// edge class (for network-flow)
template<class FLOWTYPE, class COSTTYPE> struct Edge {
    int rev, from, to;
    FLOWTYPE cap, icap;
    COSTTYPE cost;
    Edge(int r, int f, int t, FLOWTYPE ca, COSTTYPE co) : rev(r), from(f), to(t), cap(ca), icap(ca), cost(co) {}
    friend ostream &operator<<(ostream &s, const Edge &E) {
        if (E.cap > 0) return s << E.from << "->" << E.to << '(' << E.cap << ',' << E.cost << ')';
        else return s;
    }
};

// graph class (for network-flow)
template<class FLOWTYPE, class COSTTYPE> struct Graph {
    vector<vector<Edge<FLOWTYPE, COSTTYPE> > > list;
    Graph(int n = 0) : list(n) { }
    void init(int n = 0) { list.clear(); list.resize(n); }
    void reset() { for (int i = 0; i < (int)list.size(); ++i) for (int j = 0; j < list[i].size(); ++j) list[i][j].cap = list[i][j].icap; }
    inline vector<Edge<FLOWTYPE, COSTTYPE> >& operator [] (int i) { return list[i]; }
    inline const size_t size() const { return list.size(); }
    inline Edge<FLOWTYPE, COSTTYPE> &redge(const Edge<FLOWTYPE, COSTTYPE> &e) {
        if (e.from != e.to) return list[e.to][e.rev];
        else return list[e.to][e.rev + 1];
    }
    void addedge(int from, int to, FLOWTYPE cap, COSTTYPE cost) {
        list[from].push_back(Edge<FLOWTYPE, COSTTYPE>((int)list[to].size(), from, to, cap, cost));
        list[to].push_back(Edge<FLOWTYPE, COSTTYPE>((int)list[from].size() - 1, to, from, 0, -cost));
    }
    void add_undirected_edge(int from, int to, FLOWTYPE cap, COSTTYPE cost) {
        list[from].push_back(Edge<FLOWTYPE, COSTTYPE>((int)list[to].size(), from, to, cap, cost));
        list[to].push_back(Edge<FLOWTYPE, COSTTYPE>((int)list[from].size() - 1, to, from, cap, cost));
    }
    friend ostream& operator << (ostream& s, const Graph& G) {
        s << endl; for (int i = 0; i < G.V; ++i) { s << i << " : " << G.list[i] << endl; }return s;
    }
};

template<class FLOWTYPE, class COSTTYPE> COSTTYPE MinCostFlow(Graph<FLOWTYPE, COSTTYPE> &G, int s, int t, FLOWTYPE f) {
    int n = (int)G.size();
    vector<COSTTYPE> dist(n, -1);
    vector<int> prevv(n), preve(n);
    COSTTYPE res = 0;
    while (f > 0) {
        dist.assign(n, -1);
        dist[s] = 0;
        while (true) {
            bool update = false;
            for (int v = 0; v < n; ++v) {
                if (dist[v] == -1) continue;
                for (int i = 0; i < G[v].size(); ++i) {
                    Edge<FLOWTYPE, COSTTYPE> &e = G[v][i];
                    if (e.cap > 0 && (dist[e.to] < 0 || dist[e.to] > dist[v] + e.cost)) {
                        dist[e.to] = dist[v] + e.cost;
                        prevv[e.to] = v;
                        preve[e.to] = i;
                        update = true;
                    }
                }
            }
            if (!update) break;
        }
        if (dist[t] < 0) return -1;
        FLOWTYPE d = f;
        for (int v = t; v != s; v = prevv[v]) d = min(d, G[prevv[v]][preve[v]].cap);
        f -= d;
        res += dist[t] * d;
        for (int v = t; v != s; v = prevv[v]) {
            Edge<FLOWTYPE, COSTTYPE> &e = G[prevv[v]][preve[v]];
            Edge<FLOWTYPE, COSTTYPE> &re = G.redge(e);
            e.cap -= d;
            re.cap += d;
        }
    }
    return res;
}



int main() {
    int V, E, F;
    cin >> V >> E >> F;
    Graph<int, int> G(V);
    for (int i = 0; i < E; ++i) {
        int u, v, cap, cost;
        cin >> u >> v >> cap >> cost;
        G.addedge(u, v, cap, cost);
    }
    cout << MinCostFlow(G, 0, V - 1, F) << '\n';
    return 0;
}