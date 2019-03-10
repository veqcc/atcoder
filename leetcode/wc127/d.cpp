/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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