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
typedef pair<int, int> P;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<queue<int>> customer(n);
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        for (int j = 0; j < p; j++) {
            int a;
            cin >> a;
            customer[i].push(a);
        }
    }

    queue<P> q;
    for (int i = 0; i < n; i++) {
        if (customer[i].size()) {
            q.push(P(customer[i].front(), i));
            customer[i].pop();
        }
    }

    while (q.size()) {
        P p = q.front();
        q.pop();

        cout << p.first << ' ';
        if (customer[p.second].size()) {
            q.push(P(customer[p.second].front(), p.second));
            customer[p.second].pop();
        }
    }

    cout << "\n";
    return 0;
}