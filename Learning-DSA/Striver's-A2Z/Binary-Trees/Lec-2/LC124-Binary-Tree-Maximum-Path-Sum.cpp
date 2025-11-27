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

public:
    int sum = INT_MIN;
    
    int checkSum(TreeNode* root){
        if (!root) return 0;
        int left = max(0,checkSum(root->left));
        int right = max(0,checkSum(root->right));
        sum = max(sum, left+right+(root->val));
        return root->val + max(left, right);
    }
    
   
    int maxPathSum(TreeNode* root) {
        checkSum(root);
        return sum;
    }
};
