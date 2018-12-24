#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

const int N = 100005;
vector <int> vec[N];
int dp[N];

bool comp(int x, int y) {
    return dp[x] > dp[y];
}

void dfs(int x) {
    for (int i = 0; i < vec[x].size(); i++) {
        dfs(vec[x][i]);
    }

    sort(vec[x].begin(), vec[x].end(), comp);

    int tmp = 1;
    for (int i = 0; i < vec[x].size(); i++) {
        dp[x] = max(dp[x], dp[vec[x][i]] + tmp);
        tmp++;
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 2; i <= n; i++) {
        int a;
        cin >> a;
        vec[a].push_back(i);
    }

    dfs(1);

    cout << dp[1] << "\n";
    return 0;
}