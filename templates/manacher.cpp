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

vector<int> manacher(string &str) {
    vector<char> newstr(2 * str.size() - 1);
    for (int i = 0; i < newstr.size(); i++) {
        if (i % 2 == 0) newstr[i] = str[i / 2];
        else newstr[i] = '.';
    }
    vector<int> cnt(newstr.size());
    int i = 0, j = 0;
    while (i < newstr.size()) {
        while (i - j >= 0 && i + j < newstr.size() && newstr[i - j] == newstr[i + j]) j++;
        cnt[i] = j;
        int k = 1;
        while (i - k >= 0 && i + k < newstr.size() && k + cnt[i - k] < j) { cnt[i + k] = cnt[i - k]; k++; }
        i += k; j -= k;
    }
    for (int i = 0; i < cnt.size(); i++) {
        if (i % 2 == 1) cnt[i] = 2 * ceil(1.0 * (cnt[i] - 1) / 2);
        else cnt[i] = (ceil(1.0 * cnt[i] / 2) - 1) * 2 + 1;
    }
    return move(cnt);
}

int main() {
    string str1 = "aabb";
    vector<int> cnt = manacher(str1);
    for (int x : cnt) cout << x; // 1210121 (各文字/文字間を中心とした最長の回文の直径)
    return 0;
}

