#include <functional>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
typedef pair <int, int> P;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int r, c;
        cin >> r >> c;

        ll ans = 0, cur = 0;
        vector <P> eliminate;
        vector<vector<bool>> used(r, vector<bool>(c));
        vector<vector<int>> table(r, vector<int>(c));
        vector <set<int>> row(r), col(c);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> table[i][j];
                eliminate.push_back({i, j});
                cur += table[i][j];
                row[i].insert(j);
                col[j].insert(i);
            }
        }

        bool first = true;
        while (!eliminate.empty()) {
            ans += cur;
            vector <P> nxt, adj;
            for (P &p : eliminate) {
                int x = p.first, y = p.second;

                auto itr_r = row[x].lower_bound(y);
                if (itr_r != row[x].begin()) adj.push_back({x, *prev(itr_r)});
                if (next(itr_r) != row[x].end()) adj.push_back({x, *next(itr_r)});

                auto itr_c = col[y].lower_bound(x);
                if (itr_c != col[y].begin()) adj.push_back({*prev(itr_c), y});
                if (next(itr_c) != col[y].end()) adj.push_back({*next(itr_c), y});
            }

            if (!first) {
                for (P &p : eliminate) {
                    int x = p.first, y = p.second;
                    row[x].erase(y);
                    col[y].erase(x);
                }
            }

            sort(adj.begin(), adj.end());
            adj.erase(unique(adj.begin(), adj.end()), adj.end());

            for (P &p : adj) {
                int x = p.first, y = p.second;
                if (used[x][y]) continue;

                vector <P> neighbour;
                auto itr_r = row[x].lower_bound(y);
                if (itr_r != row[x].begin()) neighbour.push_back({x, *prev(itr_r)});
                if (next(itr_r) != row[x].end()) neighbour.push_back({x, *next(itr_r)});

                auto itr_c = col[y].lower_bound(x);
                if (itr_c != col[y].begin()) neighbour.push_back({*prev(itr_c), y});
                if (next(itr_c) != col[y].end()) neighbour.push_back({*next(itr_c), y});

                int sum = 0, num = 0;
                for (P &p : neighbour) {
                    num++;
                    sum += table[p.first][p.second];
                }

                if (sum > table[x][y] * num) {
                    used[x][y] = true;
                    nxt.push_back(p);
                    cur -= table[x][y];
                }
            }

            first = false;
            eliminate = move(nxt);
        }

        cout << "Case #" << t << ": " << ans << endl;
    }

    return 0;
}