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
const int MAX = 1 << 30;
const ll MOD = 1000000007LL;
typedef pair <int, int> P;

struct S {
    int idx1, idx2;
    int op3_count;
};

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    string s;
    cin >> n >> k >> s;

    vector <S> j_border;
    vector <int> J;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'J') {
            J.push_back(i);
            if (J.size() >= k) {
                int idx1 = J[J.size() - k];
                int idx2 = J.back();
                int op3_count = idx2 - idx1 + 1 - k;
                j_border.push_back(S{idx1, idx2, op3_count});
            }
        }
    }

    vector <int> o_sum(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'O') o_sum[i]++;
        if (i) o_sum[i] += o_sum[i - 1];
    }

    vector <S> i_border;
    vector <int> I;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'I') {
            I.push_back(i);
            if (I.size() >= k) {
                int idx1 = I[I.size() - k];
                int idx2 = I.back();
                int op3_count = idx2 - idx1 + 1 - k;
                i_border.push_back(S{idx1, idx2, op3_count});
            }
        }
    }

    int ans = MAX;
    int i_idx = 0;
    for (auto j : j_border) {
        int front = j.idx2;
        while (true) {
            if (i_idx >= i_border.size()) break;

            int back = i_border[i_idx].idx1;
            if (o_sum[back] - o_sum[front] >= k) break;

            i_idx++;
        }

        if (i_idx >= i_border.size()) break;

        int back = i_border[i_idx].idx1;

        int tmp = j.op3_count + i_border[i_idx].op3_count;
        tmp += back - front - 1 - k;

        ans = min(ans, tmp);
    }

    cout << (ans == MAX ? -1 : ans) << "\n";
    return 0;
}