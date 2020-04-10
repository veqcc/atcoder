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

    int n, m;
    cin >> n >> m;

    deque<int> d;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        d.push_back(a);
    }

    string s;
    cin >> s;

    for (int i = 0;  i< m; i++) {
        if (s[i] == 'L') {
            int a = d.front();
            d.pop_front();
            int b = d.front();
            d.pop_front();
            d.push_front(a + b);
            d.push_back(0);
        } else {
            int a = d.back();
            d.pop_back();
            int b = d.back();
            d.pop_back();
            d.push_back(a + b);
            d.push_front(0);
        }
    }

    for (int i = 0; i < n; i++) {
        int x = d.front();
        d.pop_front();
        cout << x << ' ';
    }

    cout << endl;
    return 0;
}