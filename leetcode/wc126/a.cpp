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
    vector<string> commonChars(vector<string>& A) {
        map<int, int> mp[A.size()];
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                mp[i][A[i][j] - 'a']++;
            }
        }

        vector <string> ans;
        for (int i = 0; i < 26; i++) {
            int mn = 1000000;
            for (int j = 0; j < A.size(); j++) {
                mn = min(mn, mp[j][i]);
            }

            while (mn > 0) {
                char c = 'a' + i;
                ans.push_back(string(1, c));
                mn--;
            }
        }

        return ans;
    }
};

int main() {
    return 0;
}