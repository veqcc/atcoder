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
typedef long long ll;
using namespace std;
typedef pair<int, int> P;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    int p[n];
    for (int i = 0; i < n; i++) cin >> p[i];

    int s[n];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        s[i]--;
    }

    int c[k];
    for (int i = 0; i < k; i++) cin >> c[i];

    vector <P> vec[m];
    for (int i = 0; i < n; i++) {
        vec[s[i]].push_back(P(p[i], i+1));
    }

    int cnt = k;
    for (int i = 0; i < m; i++) {
        int sz = vec[i].size();
        if (sz == 0) continue;
        sort(vec[i].begin(), vec[i].end());
        for (int j = 0; j < k; j++) {
            if (c[j] == vec[i][sz-1].second) {
                cnt--;
                break;
            }
        }
    }

    cout << cnt << "\n";
    return 0;
}