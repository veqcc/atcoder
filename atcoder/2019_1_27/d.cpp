#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
#include <iterator>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

set <int> in[100005], out[100005];
int ans[100005];

void bfs(int root) {
    queue<int> q;
    q.push(root);

    while (q.size()) {
        int p = q.front();
        q.pop();
        set <int> :: iterator itr;
        for (itr = out[p].begin(); itr != out[p].end(); itr++) {
            if (in[*itr].size() == 1) {
                ans[*itr] = p+1;
                q.push(*itr);
            }
            in[*itr].erase(p);
        }
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n + m - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        in[b].insert(a);
        out[a].insert(b);
    }

    int root;
    for (int i = 0; i < n; i++) {
        if (in[i].size() == 0) {
            root = i;
            break;
        }
    }

    bfs(root);

    for (int i = 0; i < n; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}