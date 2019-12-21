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

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        string p, h;
        cin >> p >> h;

        int exist = 0;
        vector <int> p_count(26);
        for (int i = 0; i < p.size(); i++) {
            p_count[p[i] - 'a']++;
            if (p_count[p[i] - 'a'] == 1) exist++;
        }

        bool ans = false;
        for (int i = 0; i < h.size(); i++) {
            vector <int> h_count(26);
            int same = 0;
            for (int j = i; j < h.size(); j++) {
                h_count[h[j] - 'a']++;
                if (h_count[h[j] - 'a'] == p_count[h[j] - 'a']) {
                    same++;
                } else if (h_count[h[j] - 'a'] > p_count[h[j] - 'a']) {
                    same = -1;
                    break;
                }

                if (same == exist) {
                    ans = true;
                    break;
                }
            }
        }

        cout << (ans ? "YES" : "NO") << '\n';
    }

    return 0;
}