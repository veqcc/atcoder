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

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    map<int, int> mp;
    for (char c : s) mp[c - '0']++;

    vector<bool> ans(10, false);

    // 2 * 7 のチェック
    int need;
    int count = 0;
    bool flag = true;
    for (auto itr = mp.begin(); itr != mp.end(); itr++) {
        if (itr->second == 1) {
            if (count > 0) flag = false;
            need = itr->first;
            count++;
        } else if (itr->second > 2) {
            flag = false;
        }
    }
    if (flag) ans[need] = true;

    // 2 3 3 3 3 のチェック
    for (int i = 1; i < 10; i++) {
        // 挿入する数字がiの時
        if (mp[i] == 4) continue;

        mp[i]++;
        bool possible = false;

        for (int j = 1; j < 10; j++) {
            // 2のペアがjの時
            if (mp[j] < 2) continue;
            mp[j] -= 2;

            map<int, int> mp2;
            for (auto itr = mp.begin(); itr != mp.end(); itr++) mp2[itr->first] = itr->second;

            bool pos = true;
            for (int k = 1; k < 12; k++) {
                if (mp2[k] < 0) pos = false;

                if (mp2[k] >= 3) mp2[k] -= 3;
                if (mp2[k] > 0) {
                    mp2[k + 1] -= mp2[k];
                    mp2[k + 2] -= mp2[k];
                }
            }

            if (pos) possible = true;
            mp[j] += 2;
        }

        if (possible) ans[i] = true;
        mp[i]--;
    }

    for (int i = 1; i < 10; i++) {
        if (ans[i]) {
            cout << i << "\n";
        }
    }

    return 0;
}