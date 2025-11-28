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
//O(n2),O(n2)

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()||inorder.empty()) return nullptr;
        TreeNode* root = new TreeNode (preorder[0]);
        int mid = find(inorder.begin(), inorder.end(),preorder[0]) - inorder.begin();
        vector<int> leftIn(inorder.begin(),inorder.begin()+mid);
        vector<int> rightIn(inorder.begin()+mid+1, inorder.end());
        vector<int> leftPre(preorder.begin()+1,preorder.begin()+mid+1);
        vector<int> rightPre(preorder.begin()+mid+1,preorder.end());
        root->left = buildTree(leftPre,leftIn);
        root->right = buildTree(rightPre, rightIn);
        return root;
    }
};

//O(n),O(n)

class Solution {

TreeNode* build(vector<int>& preorder, vector<int>& inorder, unordered_map<int,int>& indices, int& preIndex, int left, int right) 
{
    if (left>right) return nullptr;
    int rootVal = preorder[preIndex++];
    TreeNode* root = new TreeNode(rootVal);
    int mid = indices[rootVal];
    root->left = build(preorder,inorder,indices,preIndex,left,mid-1);
    root->right = build(preorder,inorder,indices,preIndex,mid+1, right);
    return root;
}

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> indices;

        for (int i = 0; i < inorder.size(); ++i)
            indices[inorder[i]] = i;
        int preIndex = 0;
        return build(preorder, inorder,indices, preIndex,0,inorder.size()-1);
    }
};
