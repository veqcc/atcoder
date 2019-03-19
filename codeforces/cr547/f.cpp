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
typedef pair <int, int> P;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    map<int, vector<P> > mp;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            mp[a[j] - a[i - 1]].push_back(P(j, i));
        }
    }

    int mx = 0;
    int ans = 0;
    for (auto itr = mp.begin(); itr != mp.end(); itr++) {
        vector <P> vec = itr->second;
        int sz = vec.size();
        if (sz <= mx) continue;

        sort(vec.begin(), vec.end()); // rightの小さい順にソート

        int pos = 0;
        int cnt = 0;
        for (int i = 0; i < sz; i++) {
            if (vec[i].second > pos) {
                cnt++;
                pos = vec[i].first;
            }
        }

        if (cnt > mx) {
            mx = cnt;
            ans = itr->first;
        }
    }

    cout << mx << '\n';

    vector <P> vec = mp[ans];
    sort(vec.begin(), vec.end());

    int pos = 0;
    for (int i = 0; i < vec.size(); i++) {
        int left = vec[i].second;
        int right = vec[i].first;
        if (left > pos) {
            pos = right;
            cout << left << " " << right << "\n";
        }
    }

    return 0;
}