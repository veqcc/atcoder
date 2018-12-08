#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int main() {
    int N, L, P;
    cin >> N >> L >> P;

    vector < pair<int, int> > vec;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        vec.push_back(make_pair(a, b));
    }

    sort(vec.begin(), vec.end());

    priority_queue<int> q;

    int cur = 0;
    int gas = P;
    int count = 0;
    for (int i = 1; i < L; i++) {
        gas--;

        if (vec[cur].first == i) {
            q.push(vec[cur].second);
            cur++;
        }

        if (gas == 0) {
            if (q.empty()) {
                cout << -1 << "\n";
                return 0;
            }

            int addi = q.top();
            q.pop();
            gas = addi;
            count++;
        }
    }

    cout << count << "\n";
    return 0;
}