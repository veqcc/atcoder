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

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        bool table[N][N];
        fill(table[0], table[N], false);
        for (int i = 0; i < trust.size(); i++) {
            table[trust[i][0] - 1][trust[i][1] - 1] = true;
        }

        vector <int> ans;
        for (int i = 0; i < N; i++) {
            bool trust_nobody = true;
            bool trusted_by_everyone = true;

            for (int j = 0; j < N; j++) {
                if (i == j) continue;

                // iがjudgeかどうか確かめる

                // iは誰も信用してない -> table[i][xxx] = all false
                if (table[i][j]) trust_nobody = false;

                // iはされからも信頼されている -> table[xxx][i] = all true
                if (!table[j][i]) trusted_by_everyone = false;
            }

            if (trust_nobody && trusted_by_everyone) {
                ans.push_back(i);
            }
        }

        if (ans.size() != 1) {
            return -1;
        } else {
            return ans[0] + 1;
        }
    }
};

int main() {
    return 0;
}