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
//O(n2),O(n)

class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        TreeNode* tempL = root->left;
        TreeNode* tempR = root->right;
        root->left = NULL;
        root->right = tempL;
        flatten(tempL);
        flatten(tempR);
        
        if (tempL)
        {
            while(tempL->right)
            {
                tempL = tempL->right;
            }
            tempL->right = tempR;
        }
        else
        {
            root->right = tempR;
        }

        return;


    }
};
