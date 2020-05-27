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
    vector<int> par(n + 1);
    for (int i = 2; i <= n; i++) cin >> par[i];

    stack<int> ans;
    int cur = n;
    while (cur) {
        ans.push(cur);
        cur = par[cur];
    }

    while (!ans.empty()) {
        cout << ans.top() << ' ';
        ans.pop();
    }

    cout << endl;
    return 0;
}