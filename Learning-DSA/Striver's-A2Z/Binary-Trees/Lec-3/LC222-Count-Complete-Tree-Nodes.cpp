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
    int countNodes(TreeNode* root) {
        
        //O(n),O(h)
      // if (!root) return 0;
        // if(root->left && root->right) return countNodes(root->left)+countNodes(root->right)+1;
        // if(root->left) return countNodes(root->left)+1;
        // return countNodes(root->right)+1;

        
      //O(logn^2),O(logn)
      if (!root) return 0;
        TreeNode* temp = root;
        int level1 = 0;
        while(temp)
        {
            level1++;
            temp = temp->left;
        }
        temp = root;
        int level2 = 0;
        while(temp)
        {
            level2++;
            temp = temp->right;
        }
        if (level1!=level2)
        {
            return countNodes(root->left)+countNodes(root->right)+1;
        }
        return pow(2,level1)-1;


    }
};
