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
    int maxLevelSum(TreeNode* root) {
        //level order traversal (bfs-ing)
        //maintain level and check max at each point. 
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        long long maxSum = LLONG_MIN;
        int ans = -1;
        while (!q.empty())
        {
            long long levelSum = 0;
            int size = q.size();
            for (int i = 0; i<size; i++)
            {
                TreeNode* t = q.front();
                q.pop();
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
                levelSum += t->val;
            }
            level ++;
            if (maxSum<levelSum)
            {
                maxSum = levelSum;
                ans = level;
            }
        }
        return ans;
    }
};
