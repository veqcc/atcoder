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
typedef unsigned int uint;
using namespace std;

const int MAX_N = 1 << 17;
const int MAX = 1 << 30;

// セグメント木を持つグローバル配列
int n, dat[2 * MAX_N - 1];

void init (int n_) {
    // 要素数を2の冪乗に
    n = 1;
    while (n < n_) {
        n *= 2;
    }

    // 全ての値をINT_MAXに。
    for (int i = 0; i < n; i++) {
        dat[i] = MAX;
    }
}

// k番目の値をaに変更
void update(int k, int a) {
    //　葉の節点
    k += n-1;
    dat[k] = a;

    // 登りながら更新
    while (k > 0) {
        k = (k - 1) / 2;
        dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
    }
}

// [a, b)の最小値
// k : 節点  l, r : kが[l, r)に対応していることを表す
int query(int a, int b, int k, int l, int r) {
    // [a,b)と[l,r)が交差しない
    if (r <= a || b <= l) {
        return MAX;
    }

    // [a,b)が[l,r)を完全に含んでいれば
    if (a <= l && r <= b) {
        return dat[k];
    }

    // 上記のどちらでもなければ、二つの子の最小値
    int mid = (l + r) / 2;
    int vl = query(a, b, k * 2 + 1, l, mid);
    int vr = query(a, b, k * 2 + 2, mid, r);
    return min(vl, vr);
}

// for debug
void show(int p) {
    for (int i = 0; i < p; i++) {
        cout << dat[i] << " ";
    }
    cout << "\n";
}

int main() {
    init(10);
    for (int i = 0; i < 10; i++) {
        update(i, (i+1) * (i%2*2 - 1));
    }

    cout << query(1, 2, 0, 0, n) << "\n"; // 2
    update(1, -2);
    cout << query(1, 2, 0, 0, n) << "\n"; // -2
    cout << query(0, 10, 0, 0, n) << "\n"; // -9
    cout << query(1, 8, 0, 0, n) << "\n"; // -7
    update(0, 10);
    update(1, 100);
    cout << query(0, 2, 0, 0, n) << "\n"; // 10
    cout << query(1, 2, 0, 0, n) << "\n"; // 100
    cout << query(1, 5, 0, 0, n) << "\n"; // -5

    return 0;
}