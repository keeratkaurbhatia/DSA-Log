//O(n),O(n)

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

    TreeNode* build(vector<int>& postorder, vector<int>& inorder, unordered_map<int,int>& indices, int& postIndex, int left, int right) 
{
    if (left>right) return nullptr;
    int rootVal = postorder[postIndex--];
    TreeNode* root = new TreeNode(rootVal);
    int mid = indices[rootVal];
    root->right = build(postorder,inorder,indices,postIndex,mid+1,right);
    root->left = build(postorder,inorder,indices,postIndex,left,mid-1);
    return root;
}

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> indices;

        for (int i = 0; i < inorder.size(); ++i)
            indices[inorder[i]] = i;
        int postIndex = postorder.size()-1;
        return build(postorder, inorder,indices, postIndex,0,inorder.size()-1);
    }
};
