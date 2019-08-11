#include <iostream>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;

// Z Algorithm
//  最長共通prefix長列を返す
//  計算量: O(|S|)

// アルゴリズム
//  k > r           -> それまで計算したzの結果は利用できず、ナイーブに計算する
//  z[k-l] < r-k+1  -> S[0:r-l] == S[l:r] であり、kがすっぽり入っているので一発
//  z[k-l] >= r-k+1 -> S[0:r-k+1] == S[k:r] であるので、追加分を計算する

vector <int> ZAlgorithm(const string& S) {
    int N = S.size();
    vector<int> z(N);
    z[0] = -1;

    int l = 0, r = 0;
    for (int k = 1; k < N; k++) {
        if (k > r) {
            int i = 0;
            while (k + i < N && S[i] == S[k + i]) i++;
            l = k;
            r = k + i - 1;
            z[k] = i;
        } else if (z[k - l] < r - k + 1) {
            z[k] = z[k - l];
        } else if (z[k - l] >= r - k + 1) {
            int i = r - k + 1;
            while (k + i < N && S[i] == S[k + i]) i++;
            l = k;
            r = k + i - 1;
            z[k] = i;
        }
    }

    return z;
}


// verified (TLE)
//  https://yukicoder.me/problems/no/430
void yuki430() {
    string S, C;
    int M, ans = 0;
    cin >> S >> M;
    while (M--) {
        cin >> C;
        vector <int> Z = ZAlgorithm(C + S);
        for (int i = C.size(); i < Z.size(); i++) if (Z[i] >= C.size()) ans++;
    }
    cout << ans << "\n";
}


// verified
//  https://yukicoder.me/problems/no/599
vector <ll> dp(10005);
vector <bool> used(10005, false);
ll dfs(const string &S, int L, int R) {
    if (R <= L) return 1;
    if (used[L]) return dp[L];
    string s = S.substr(L, R - L);
    vector <int> z = ZAlgorithm(s);
    ll ret = 1;
    int l = 1, r = s.size() - 1;
    while (l <= r) {
        if (z[r] == l) ret = (ret + dfs(S, L + l, L + r)) % MOD;
        l++; r--;
    }
    used[L] = true;
    return dp[L] = ret;
}
void yuki599() {
    string s;
    cin >> s;
    cout << dfs(s, 0, s.size()) << '\n';
}

int main() {
    // yuki430();
    yuki599();
    return 0;
}