#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int N, K;
vector <int> G[2005];
int visited[2005];

void dfs(int x, int c) {
    if (visited[x] > 0 && visited[x] < c) {
        return;
    } else {
        visited[x] = c;
    }

    for (int i = 0; i < G[x].size(); i++) {
        dfs(G[x][i], c+1);
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int mn = N;
    if (K % 2 == 0) {
        for (int i = 1; i <= N; i++) {
            fill(visited, visited+2005, 0);
            dfs(i, 1);

            int tmp = N;
            for (int i = 1; i <= N; i++) {
                if (visited[i] <= K / 2 + 1) {
                    tmp--;
                }
            }
            mn = min(mn, tmp);
        }
    } else {
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < G[i].size(); j++) {
                fill(visited, visited+2005, 0);
                dfs(i, 1);
                dfs(G[i][j], 1);

                int tmp = N;
                for (int i = 1; i <= N; i++) {
                    if (visited[i] <= K / 2 + 1) {
                        tmp--;
                    }
                }
                mn = min(mn, tmp);
            }
        }
    }

    cout << mn << "\n";
    return 0;
}