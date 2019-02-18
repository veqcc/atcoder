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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    map <int, int> depth;
    map <int, TreeNode*> parent;

    void dfs(TreeNode* node, TreeNode* par) {
        if (node != NULL) {
            depth[node->val] = par == NULL ? 0 : depth[par->val] + 1;
            parent[node->val] = par;
            dfs(node->left, node);
            dfs(node->right, node);
        }
    }

public:
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, NULL);
        return (depth[x] == depth[y]) && (parent[x] != parent[y]);
    }
};

int main() {
    return 0;
}