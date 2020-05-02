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
typedef pair <int, char> P;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int u;
        cin >> u;

        map<char, ll> head, total;
        for (int i = 1; i <= 10000; i++) {
            ll q;
            string r;
            cin >> q >> r;

            for (char c : r) total[c]++;
            if (r.size() == u) head[r[0]]++;
        }

        char zero;
        for (auto itr = total.begin(); itr != total.end(); itr++) {
            if (head[itr->first] == 0) {
                zero = itr->first;
                break;
            }
        }

        vector <P> vec;
        for (auto itr = head.begin(); itr != head.end(); itr++) {
            int c = itr->first;
            ll num = itr->second;
            if (num > 0) vec.push_back({num, c});
        }

        sort(vec.begin(), vec.end(), greater<P>());

        cout << "Case #" << t << ": " << zero;
        for (P p : vec) cout << p.second;
        cout << endl;
    }

    return 0;
}