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
public:
    int maxDepth(TreeNode* node)
    {
        if (node==nullptr) return 0;
        int leftDepth = maxDepth(node->left);
        int rightDepth = maxDepth(node->right);
        return max(leftDepth, rightDepth)+1;
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        //lowest common ancestor of maxDepth
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        if (left>right) return subtreeWithAllDeepest(root->left);
        else if (left<right) return subtreeWithAllDeepest(root->right);
        else if (left==right) return root;
        return nullptr;
    }
};
