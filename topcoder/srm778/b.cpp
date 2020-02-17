#include <functional>
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
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
typedef pair <int, int> P;

class AlienOccupation {
public:
    vector <int> getInfo(int N, int A, vector <int> X, vector <int> Y) {
        int M = X.size();

        queue <P> q;
        q.push(P(A, 0));

        vector <bool> occupied(N, false);
        occupied[A] = true;

        vector <int> count(N, 0);
        count[0] = 1;

        while (q.size()) {
            P p = q.front();
            q.pop();

            for (int i = 0; i < M; i++) {
                int next = ((ll)X[i] * (ll)p.first + (ll)Y[i]) % (ll)N;
                if (!occupied[next]) {
                    q.push(P(next, p.second + 1));
                    count[p.second + 1]++;
                    occupied[next] = true;
                }
            }
        }

        int t = 0, u = 0, v = 0;
        for (int i = 0; i < N; i++) {
            t += count[i];
            if (count[i]) u = i;
            if (i) v = max(v, count[i]);
        }

        vector <int> ans = {t, u, v};
        return ans;
    }
};
