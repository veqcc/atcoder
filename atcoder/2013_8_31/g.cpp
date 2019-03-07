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
using namespace std;

const ll INF = 1LL << 60;
ll dp[1000005][26]; // i文字目以降について文字cから始まる部分列の個数

void add(ll &a, ll b) {
    a += b;
    if (a > INF) a = INF;
}

int main() {
    string S;
    ll K;
    cin >> S >> K;
    int n = S.size();

    dp[n-1][S[n-1] - 'a'] = 1;
    for (int i = n - 2; i >= 0; i--) {
        for (int c = 0; c < 26; c++) {
            if (c != S[i] - 'a') {
                add(dp[i][c], dp[i+1][c]);
            } else {
                add(dp[i][c], 1);
                for (int c2 = 0; c2 < 26; c2++) {
                    add(dp[i][c], dp[i+1][c2]);
                }
            }
        }
    }

    ll sm = 0;
    for (int c = 0; c < 26; c++) add(sm, dp[0][c]);

    if (sm < K) {
        cout << "Eel\n";
    } else {
        string ret = "";
        for (int i = 0; i < n; i++) {
            int j;
            for (j = 0; j < 26; j++) {
                if (K - dp[i][j] <= 0) break;
                K -= dp[i][j];
            }

            char c = j + 'a';
            ret += c;
            K--;
            if (K <= 0) break;
            while (S[i] != c) i++;
        }
        cout << ret << "\n";
    }

    return 0;
}