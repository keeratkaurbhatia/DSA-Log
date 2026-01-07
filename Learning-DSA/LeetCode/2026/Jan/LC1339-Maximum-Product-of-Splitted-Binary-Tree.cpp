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
    long long maxProd = 0;
    int mod = 1e9+7; 
    long long total = 0;

    long long sum (TreeNode* root, long long total)
    {
        if (root==nullptr) return 0;
        long long left = sum(root->left, total);
        long long right = sum(root->right, total);
        long long ans = left+right+root->val;
        maxProd = max(maxProd,ans*(total-ans));
        return ans;
    }
    long long totalSum(TreeNode* root)
    {
        if (root==nullptr) return 0;
        long long full = totalSum(root->left)+totalSum(root->right)+root->val;
        return full;
    }
    int maxProduct(TreeNode* root) {
        total = totalSum(root);
        sum(root,total);
        return maxProd%mod;

    }
};
