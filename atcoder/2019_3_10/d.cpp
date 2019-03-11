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

int N, M, a, b;
vector <int> vec[100005];

struct SegmentTree {
private:
    int n;
    vector <int> node;

public:
    SegmentTree(vector <int> v) {
        int sz = v.size(); n = 1;
        while (n < sz) n *= 2;
        node.resize(2*n-1, 0);
    }
    void add(int x, int val) {
        x += n - 1;
        node[x] += val;
        while (x > 0) {
            x = (x - 1) / 2;
            node[x] = max(node[2*x+1], node[2*x+2]);
        }
    }
    int getmax(int a, int b, int k=0, int l=0, int r=-1) {
        if (r < 0) r = n;
        if (r <= a || b <= l) return 0;
        if (a <= l && r <= b) return node[k];
        int vl = getmax(a, b, 2*k+1, l, (l+r)/2);
        int vr = getmax(a, b, 2*k+2, (l+r)/2, r);
        return max(vl, vr);
    }
};

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) vec[i].push_back(i);
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        vec[--b].push_back(--a);
    }

    int front = 0, back = 0;
    int mn = N+1, l, r;
    SegmentTree seg(vector <int> (N, 0));
    while (back <= N) {
        if (seg.getmax(0, N) == back - front) {
            for (int x : vec[back++]) seg.add(x, 1);
        } else {
            if (mn > back - front) {
                mn = back - front;
                l = front; r = back;
            }
            for (int x : vec[front++]) seg.add(x, -1);
        }
    }

    if (mn == N + 1) cout << -1 << '\n';
    else cout << l + 1 << " " << r << "\n";
    return 0;
}