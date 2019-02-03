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

const ll mod = 1000000007LL;
ll dpA[105][1005], dpB[105][1005], dpDiv[1500][1500];
vector <int> killA, killB;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int a, tmp, count = 1;
    cin >> tmp;
    int sumN = tmp;
    for (int i = 1; i < n; i++) {
        cin >> a;
        sumN += a;
        if (a == tmp) {
            count++;
        } else {
            killA.push_back(count);
            count = 1;
            tmp = a;
        }
    }
    killA.push_back(count);
    int sizeA = killA.size();

    cin >> tmp;
    int sumM = tmp;
    count = 1;
    for (int i = 1; i < m; i++) {
        cin >> a;
        sumM += a;
        if (a == tmp) {
            count++;
        } else {
            killB.push_back(count);
            count = 1;
            tmp = a;
        }
    }
    killB.push_back(count);
    int sizeB = killB.size();

    // i を j 個の自然数に分割する方法
    dpDiv[0][0] = 1;
    for (int i = 1; i < 1400; i++) {
        for (int j = 1; j <= i; j++) {
            dpDiv[i][j] = (dpDiv[i-1][j-1] + dpDiv[i-j][j]) % mod;
        }
    }

    dpA[0][0] = 1LL;
    for (int i = 0; i <= sizeA; i++) {
        for (int j = 0; j <= sumM; j++) {
            for (int k = 0; k <= j; k++) {
                dpA[i+1][j] = (dpA[i+1][j] + dpA[i][k] * dpDiv[j-k+killA[i]][killA[i]] % mod) % mod;
            }
        }
    }

    dpB[0][0] = 1LL;
    for (int i = 0; i <= sizeB; i++) {
        for (int j = 0; j <= sumN; j++) {
            for (int k = 0; k <= j; k++) {
                dpB[i+1][j] = (dpB[i+1][j] + dpB[i][k] * dpDiv[j-k+killB[i]][killB[i]] % mod) % mod;
            }
        }
    }

    cout << dpA[sizeA][sumM] * dpB[sizeB][sumN] % mod << "\n";
    return 0;
}