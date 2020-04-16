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
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, l;
    cin >> n >> l;

    vector <int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    deque <int> deq;
    for (int i = 0; i < l; i++) {
        while (!deq.empty() && a[deq.back()] >= a[i]) {
            deq.pop_back();
        }

        deq.push_back(i);
    }

    cout << a[deq.front()];

    for (int i = l; i < n; i++) {
        if (deq.front() == i - l) {
            deq.pop_front();
        }

        while (!deq.empty() && a[deq.back()] >= a[i]) {
            deq.pop_back();
        }

        deq.push_back(i);

        cout << ' ' << a[deq.front()];
    }

    cout << endl;
    return 0;
}