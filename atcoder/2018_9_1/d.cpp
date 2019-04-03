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
using namespace std;

struct Edge { int to, weight; };
vector <Edge> edges[100];

int main() {
    int L;
    cin >> L;

    int n = 0;
    while ((1 << n) <= L) n++;

    for (int i = 1; i < n; i++) {
        edges[i].push_back((Edge){i+1, 0});
        edges[i].push_back((Edge){i+1, 1 << (i - 1)});
    }

    int m = 2 * (n - 1);
    int cur = 1 << (n - 1);
    for (int i = n - 1; i > 0; i--) {
        int p = 1 << (i - 1);
        if (cur + p <= L) {
            edges[i].push_back((Edge){n, cur});
            cur += p; m++;
        }
    }

    cout << n << " " << m << "\n";
    for (int i = 0; i < n; i++) {
        for (Edge e : edges[i]) {
            cout << i << " " << e.to << " " << e.weight << "\n";
        }
    }

    return 0;
}