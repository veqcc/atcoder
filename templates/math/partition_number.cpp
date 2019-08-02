#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;

// 分割数は、写像12相のうち以下に相当する
//  ・玉の区別をしない
//  ・箱の区別をしない
//  ・箱に入る玉の数に制限はない
// cf: http://drken1215.hatenablog.com/entry/2018/01/16/222843

// 定義
//  P(n,k): 区別のないn個の玉を、区別のないk個の箱に、中身が0個以上になるように分ける方法
//  Q(n,k): 区別のないn個の玉を、区別のないk個の箱に、中身が1個以上になるように分ける方法

// PとQの関係
//  Q(n,k) = P(n-k,k)

// Pの初期化
//  P(0,?) = P(?,1) = 1

// Pの漸化式
//  P(n,k) = P(n,k-1) + P(n-k,k)  if n >= k > 1
//  P(n,k) = P(n,n)               if n < m

// Qの初期化
//  Q(?,1) = Q(?,?) = 1

// Qの漸化式
//  Q(n,k) = Q(n-1,k-1) + Q(n-k,k)  if n >= k >= 2


class PartitionNumber {
    vector <vector<ll>> P, Q;

    void initP(int N) {
        for (int k = 0; k <= N; k++) P[0][k] = P[k][1] = 1;
        for (int n = 1; n <= N; n++) {
            for (int k = 2; k <= n; k++) P[n][k] = (P[n][k - 1] + P[n - k][k]) % MOD;
            for (int k = n + 1; k <= N; k++) P[n][k] = P[n][n];
        }
    }

    void initQ(int N) {
        for (int n = 0; n <= N; n++) Q[n][1] = Q[n][n] = 1;
        for (int n = 2; n <= N; n++) {
            for (int k = 2; k <= n; k++) Q[n][k] = (Q[n - 1][k - 1] + Q[n - k][k]) % MOD;
        }
    }

public:
    PartitionNumber(int N) {
        P.assign(N + 1, vector<ll>(N + 1, 0));
        Q.assign(N + 1, vector<ll>(N + 1, 0));
        initP(N);
        initQ(N);
    }

    ll p(int n, int k) { return P[n][k]; }

    ll q(int n, int k) { return Q[n][k]; }
};


// verified
//   https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_J
void AOJ_DPL_5_J() {
    int n, k;
    cin >> n >> k;
    PartitionNumber pn(1000);
    cout << pn.p(n, k) << "\n";
}


// verified
//   https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_L
void AOJ_DPL_5_L() {
    int n, k;
    cin >> n >> k;
    PartitionNumber pn(1000);
    cout << pn.q(n, k) << "\n";
}


// verified
//   https://yukicoder.me/problems/no/269
void yuki269() {
    int N, S, K;
    cin >> N >> S >> K;
    S -= K * N * (N - 1) / 2;
    if (S < 0) cout << 0 << '\n';
    else {
        PartitionNumber pn(S);
        cout << pn.p(S, N) << "\n";
    }
}

int main() {
    // AOJ_DPL_5_J();
    AOJ_DPL_5_L();
    //yuki269();
    return 0;
}