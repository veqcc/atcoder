#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int N, A[100005];
vector <int> G[100005];
bool visited[100005];

int dfs(int x) {
    visited[x] = true;
    if (G[x].size() == 1) return A[x];

    int cost=0, mx=0;
    for (int i = 0; i < G[x].size(); i++) {
        if (visited[G[x][i]]) continue;
        int d = dfs(G[x][i]);
        if (d == -1) return -1;
        cost += d;
        mx = max(d, mx);
    }

    if (A[x] > cost) return -1;
    if (2 * mx < cost && A[x] < cost - (cost/2)) return -1;
    if (2 * mx >= cost && A[x] < mx) return -1;
    return 2 * A[x] - cost;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> N;

    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int max_A=0, max_i=1;
    for (int i = 1; i <= N; i++) {
        if (max_A < A[i] && G[i].size() > 1) {
            max_A = A[i];
            max_i = i;
        }
    }

    if (N == 2) {
        if (A[1] == A[2]) cout << "YES";
        else cout << "NO";
    } else {
        if (dfs(max_i) == 0) cout << "YES";
        else cout << "NO";
    }

    return 0;
}