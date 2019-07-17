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
using namespace std;

// S と S(i:) の共通prefixの長さの配列を返す。 O(|S|)
vector <int> ZAlgorithm(const string& S) {
    int sz = S.size();
    vector <int> ret(sz);
    ret[0] = sz;

    int i = 1, j = 0;
    while (i < sz) {
        while (i+j < sz && S[j] == S[i+j]) j++;
        ret[i] = j;
        if (j == 0) { i++; continue; }
        int k = 1;
        while (i+k < sz && k+ret[k] < j) ret[i+k] = ret[k], k++;
        i += k; j -= k;
    }

    return ret;
}

int main() {
    string s = "aaabcdabaacaaabd";
    //          *210001021042100
    auto v = ZAlgorithm(s);
    for (int x : v) cout << x << " ";
    return 0;
}