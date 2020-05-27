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

int main() {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i];

    for (int i = 1; i <= n; i++) {
        vector<bool> visited(n + 1, false);
        int cur = i;
        while (!visited[cur]) {
            visited[cur] = true;
            cur = p[cur];
        }
        cout << cur << ' ';
    }

    cout << endl;
    return 0;
}