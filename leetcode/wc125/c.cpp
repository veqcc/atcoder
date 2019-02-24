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
    int v;
    TreeNode* dfs(TreeNode* cur, TreeNode* par) {
        if (v > cur->val) {
            TreeNode* T = new TreeNode(v);
            T->left = cur;
            if (par != NULL) par->right = T;
            return T;
        }

        if (cur->right == NULL) {
            cur->right = new TreeNode(v);
        } else {
            cur->right = dfs(cur->right, cur);
        }

        return cur;
    }
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        v = val;
        return dfs(root, NULL);
    }
};

int main() {
    return 0;
}