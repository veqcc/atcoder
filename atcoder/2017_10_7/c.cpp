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

    int n, c;
    cin >> n >> c;

    vector <int> l(n);
    for (int i = 0; i < n; i++) cin >> l[i];

    sort(l.begin(), l.end());

    int front = 0, back = n - 1;
    for (; back >= 0; back--) {
        if (front > back) {
            break;
        } else if (front == back) {
            back--;
            break;
        } else {
            if (l[front] + l[back] < c) {
                front++;
            }
        }
    }

    cout << n - back - 1 << "\n";
    return 0;
}