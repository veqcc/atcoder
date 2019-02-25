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
typedef unsigned int uint;
using namespace std;

int par[150005];
vector <int> group[150005];

int merge(int x, int y) {
    if (group[x].size() < group[y].size()) swap(x, y);

    for (int element : group[y]) {
        group[x].push_back(element);
        par[element] = x;
    }

    return x;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        par[i] = i;
        group[i].push_back(i);
    }

    int mx;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        mx = merge(par[x], par[y]);
    }

    for (int element : group[mx]) {
        cout << element + 1 << " ";
    }
    cout << "\n";
    return 0;
}