#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

const int MAX_N = 100005;
const int ST_SIZE = (1 << 15) - 1;

int N, C;
int L[MAX_N];
int S[MAX_N], A[MAX_N];

double vx[ST_SIZE], vy[ST_SIZE];
double ang[ST_SIZE];
double prv[MAX_N];

void init (int k, int l, int r) {
    ang[k] = vx[k] = 0.0;
    if (r-1 == 1) {
        vy[k] = L[1];
    } else {
        int chl = k * 2 + 1;
        int chr = k * 2 + 2;
        init(chl, 1, (1 + r) / 2);
        init(chr, (1 + r) / 2, r);
        vy[k] = vy[chl] + vy[chr];
    }
}

void change(int s, double a, int v, int l, int r) {
    if (s <= 1) {
        return;
    } else if (s < r) {
        int chl = v * 2 + 1;
        int chr = v * 2 + 2;
        int m = (l + r) / 2;
        change(s, a, chl, l, m);
        change(s, a, chr, m, r);
        if (s <= m) ang[v] += a;
        double s = sin(ang[v]);
        double c = cos(ang[v]);
        vx[v] = vx[chl] + (c * vx[chr] - s * vy[chr]);
        vy[v] = vy[chl] + (s * vx[chr] - c * vy[chr]);

    }
}

int main() {
    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        cin >> L[i];
    }
    for (int i = 0; i < C; i++) {
        cin >> S[i] >> A[i];
    }

    init(0, 0, N);
    for (int i = 0; i< N; i++) {
        prv[i] = M_PI;
    }

    for (int i = 0; i < C; i++) {
        int s = S[i];
        double a = A[i] / 360.0 * 2 * M_PI;

        change(s, a - prv[s], 0, 0, N);
        prv[s] = a;

        cout << vx[0] << " " << vy[0] << endl;
    }

    return 0;
}