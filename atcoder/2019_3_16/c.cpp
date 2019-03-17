#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

void rec(int a, int b, int v) {
    if (a == b) {
        cout << a << " ";
        return;
    }

    int c = (a^b) & -(a^b); // a^bのうちの一番小さい1
    v ^= c; // cを使用済みにする
    int d = v & -v; // vのうち未使用のbit
    rec(a, a^d, v);
    rec(a^d^c, b, v);
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, A, B;
    cin >> N >> A >> B;

    if (__builtin_popcount(A ^ B) % 2 == 1) {
        cout << "YES\n";
        rec(A, B, (1 << N) - 1);
    } else {
        cout << "NO\n";
    }

    return 0;
}
