#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;
typedef pair<int, int> P;

bool check(vector<int> v, int md) {
    vector <P> now;
    now.push_back(P(0, -1));
    for (int i = 0; i < v.size(); i++) {
        int t = now[now.size() - 1].first;
        if (t < v[i]) {
            now.push_back(P(v[i], 0));
        } else {
            for (;;) {
                P z = now[now.size() - 1];
                if (z.first > v[i]) {
                    now.pop_back();
                } else {
                    int x = v[i];
                    for (;;) {
                        if (x <= 0) {
                            return false;
                        }
                        if (now[now.size() - 1].first != x) {
                            now.push_back(P(x, 0));
                        }
                        if (now[now.size() - 1].second < md - 1) {
                            now[now.size() - 1].second++;
                            break;
                        } else {
                            x--;
                            now.pop_back();
                        }
                    }
                    break;
                }
            }
        }
    }
    return true;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v;
    bool is_1 = true;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
        if (i > 0) {
            if (v[i-1] >= v[i]) {
                is_1 = false;
            }
        }
    }

    if (is_1) {
        cout << "1\n";
        return 0;
    }

    int bg = 2;
    int ed = 1000000005;
    while (bg < ed) {
        int md = (bg + ed) / 2;
        if (check(v, md)) {
            ed = md;
        } else {
            bg = md + 1;
        }
    }

    cout << bg << "\n";
    return 0;
}