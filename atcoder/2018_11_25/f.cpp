#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int N, M, K, root;
vector<int> child[300];
bool used[300];
int step[300];
vector<int> vst;

void dfs(int i, int cand, int st) {
    step[i] = st;
    if (i == cand || used[i]) return;
    vst.push_back(st);
    for (int j : child[i]) {
        dfs(j, cand, st + 1);
    }
}

bool check(int i, int j) {
    fill(step, step + N, 0);
    vst.clear();
    dfs(root, j, 1);
    if (step[j] == 0) return false;
    if (vst.size() < M - i - 1) return false;

    if (i == M - 1) {
        return (step[j] == K);
    } else {
        sort(vst.begin(), vst.end());
        int mn = 0, mx = 0;
        for (int k = 0; k < M - i - 1; k++) {
            mn += vst[k];
            mx += vst[vst.size() - 1 - k];
        }
        return (mn <= K - step[j] && K - step[j] <= mx);
    }
}

int main() {
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        int p;
        cin >> p;
        if (p == 0) {
            root = i;
        } else {
            child[p - 1].push_back(i);
        }
    }

    int ans[300];
    for (int i = 0; i < M; i++) {
        bool ok = false;
        for (int j = 0; j < N; j++) {
            if (used[j]) continue;
            if (check(i, j)) {
                ans[i] = j;
                used[j] = true;
                K -= step[j];
                ok = true;
                break;
            }
        }
        if (!ok) {
            cout << -1 << endl;
            return 0;
        }
    }

    for (int i = 0; i < M; i++) {
        cout << ans[i] + 1 << " ";
    }
    return 0;
}