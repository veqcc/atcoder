#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;

    cout << n << endl;
    return 0;
}


// N×Nの隣接行列を作れないときは、
//   vector <int> vec[100005];
// などでNodeごとのvectorを作れば計算が間に合う。
void dfs(int v) {
    visited[v] = true;
    for (int i = 0; i < n; i++) {
        if (graph[v][i] == true && visited[i] == false) {
            dfs(i);
        }
    }
}


// gcd lcm
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    ll g = gcd(a, b);
    return a / g * b;
}


// Combination (n fixed)
ll M = 1000000007;
ll inv[100005], fac[100005], fiv[100005];
ll combination(ll k) {
    return fac[n] * fiv[k] % M * fiv[n-k] % M;
}
int main2() {
    inv[1]=fac[1]=fiv[1]=inv[0]=fac[0]=fiv[0]=1;
    for (ll i = 2; i <= n; i++) {
        fac[i] = fac[i-1] * i % M; // n!
        inv[i] = inv[M%i] * (M-M/i) % M; // n^-1
        fiv[i] = fiv[i-1] * inv[i] % M; // (n!)^-1
    }
    ll nCk = combination(k);
}


vector < pair<int,int> > vec;
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) {
    return (a.second < b.second);
}
int main3() {
    for (int i = 0; i < n; i++) {
        vec.push_back(make_pair(i, i+1));
    }
    // sort by first element asc
    sort(vec.begin(), vec.end());
    // sort desc ?
    sort(vec.begin(), vec.end(), greater<int>());
    // sort by second element asc by user defined function
    sort(vect.begin(), vect.end(), sortbysec);
}


// extended Euclid
// ap+bq=gcd(a,b) -> (p, q) & returns d=gcd(a, b)
ll extGCD(ll a, ll b, ll &p, ll &q) {
    if (b == 0) { p = 1; q = 0; return a; }
    ll d = extGCD(b, a%b, q, p);
    q -= a/b * p;
    return d;
}

// Chinese Remainder Theorem
// when x = b1 (mod m1)
//      x = b2 (mod m2)
//      m1 * p + m2 * q = d = gcd(m1, m2)
// then x = b1 + m1 * (b1 - b2) / d * p
// if x=r(mod m), returns (r, m)
pair<ll, ll> CRT(const vector<ll> &b, const vector<ll> &m) {
    ll r = 0, M = 1;
    for (int i = 0; i < (int) b.size(); i++) {
        ll p, q;
        ll d = extGCD(M, m[i], p, q);
        if ((b[i] - r) % d != 0) return make_pair(0, -1);
        ll tmp = (b[i] - r) / d * p % (m[i] / d);
        r += M * tmp;
        M *= m[i] / d;
    }
    return make_pair((r % M + M) % M, M);
}


// Bellman-Ford
// a -> b with cost c
// if undirected, a->b with c & b->a with c
void bellman_ford() {
    ll dist[N];
    fill(dist, dist+N, inf);
    dist[0] = 0;
    for (int loop = 0; loop < N; loop++) {
        for (int i = 0; i < M; i++) {
            if (dist[a[i]] == inf) continue;
            if (dist[b[i]] > dist[a[i]] + c[i]) {
                dist[b[i]] = dist[a[i]] + c[i];
            }
        }
    }

    // negative loop detection
    bool negative[N];
    fill(negative, negative+N, false);
    for (int loop = 0; loop < N; loop++) {
        for (int i = 0; i < M; i++) {
            if (dist[a[i]] == inf) continue;
            if (dist[b[i]] > dist[a[i]] + c[i]) {
                dist[b[i]] = dist[a[i]] + c[i];
                negative[b[i]] = true;
            }
            if (negative[a[i]] == true) {
                negative[b[i]] = true;
            }
        }
    }
}


// Warshall-Floyd
void warshall_floyd() {
    int dist[n][n];
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}


// Dijkstra
typedef pair<int ,int> P;
int D[100000]; // total cost
vector<P> G[100000]; // G[a] is vector of P(b,c) ( witch means [a->b with cost c] )
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
        int y = p.second; // p.second means current node position
        if (D[y] != p.first) continue;
        for (int i = 0; i < G[y].size(); i++) {
            int node = G[y].at(i).first; // edge y->node
            int cost = G[y].at(i).second; // cost of y->node
            if (D[node] > D[y] + cost) {
                D[node] = D[y] + cost;
                q.push(P(D[node], node)); // P(total cost, current node)
            }
        }
    }
}
int main4() {
    for (int i = 0; i < M; i++) {
        G[a].push_back(P(b, c));
    }
    dijkstra(D, G);
}