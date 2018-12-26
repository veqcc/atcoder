#include <algorithm>
#include <iostream>
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

int N, K, A;
string S[100000];
bool ok[100000];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;

    for (int i = 0; i < K; i++) {
        cin >> A;
        A--;
        ok[A] = true;
    }

    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    string s = S[A];
    // 検索したい
    int len = s.length();
    for (int i = 0; i < N; i++) {
        if (!ok[i]) continue;

        for (int j = 0; j < len; j++) {
            if (S[i][j] != s[j]) {
                len = j;
            }
        }
    }

    // 検索したくない
    int same = -1;
    for (int i = 0; i < N; i++) {
        if (ok[i]) continue;

        int j = 0;
        for (j = 0; j < len && j < S[i].length(); j++) {
            if (S[i][j] != s[j]) {
                break;
            }
        }
        same = max(same, j);
    }

    if (same >= len) {
        cout << -1 << "\n";
    } else {
        cout << s.substr(0, same + 1) << "\n";
    }
    return 0;
}