#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;


// 以下はpairを用いた解法
//
//ll n, k, a, b;
//vector < pair<ll,ll> > vec;
//
//int main() {
//    cin >> n >> k;
//    for (int i = 0; i < n; i++) {
//        cin >> a >> b;
//        vec.push_back(make_pair(a,b));
//    }
//    sort(vec.begin(), vec.end());
//    for (int i = 0; i < n; i++) {
//        k -= vec[i].second;
//        if (k <= 0) {
//            cout << vec[i].first << endl;
//            break;
//        }
//    }
//
//    return 0;
//}


// 以下はバケツソートを用いた解法
const int AMAX = 100000;
ll cnt[AMAX+1];

int main(void) {
    int N;
    ll K;
    cin >> N >> K;

    for (int i = 0; i < N; ++i) {
        int A, B;
        cin >> A >> B;
        cnt[A] += B;
    }

    for (int ans = 1; ans <= AMAX; ++ans) {
        if (K <= cnt[ans]) {
            cout << ans << endl;
            break;
        }
        K -= cnt[ans];
    }

    return 0;
}