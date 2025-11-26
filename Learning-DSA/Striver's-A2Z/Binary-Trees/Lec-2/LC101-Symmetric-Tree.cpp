//O(n),O(h)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    bool mirror(TreeNode* rootA, TreeNode* rootB)
    {
        if (rootA==NULL && rootB==NULL) return true;
        if (rootA==NULL || rootB==NULL) return false;
        if (rootA->val==rootB->val)
        {
            return mirror(rootA->left,rootB->right) && 
            mirror(rootA->right,rootB->left);
        }
        return false;
    }
public:
    bool isSymmetric(TreeNode* root) {
        // if (root==NULL) return true;
        // if (root->left==root->right) return isSymmetric(root->left)&&isSymmetric(root->right);
        // else return false;
        if (root==NULL) return true;
        return mirror(root->left, root->right);
    }
};
