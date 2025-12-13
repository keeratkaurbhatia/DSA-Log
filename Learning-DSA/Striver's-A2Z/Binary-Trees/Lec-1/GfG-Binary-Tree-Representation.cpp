//O(n), O(n)

class Solution {
  public:

    void create_tree(node* &root0, vector<int>& vec) {
        int n = vec.size();
        vector<node*>nvec(n);
        for(int i = 0; i<n; i++)
        {
            nvec[i]= new node();
            nvec[i]->data=vec[i];
        }
        
        root0= nvec[0];
        int l, r;
        
        for (int i=0; i<n;i++)
        {
            l=2*i+1;
            r=2*i+2;
            if (l<n) nvec[i]->left=nvec[l];
            if (r<n) nvec[i]->right=nvec[r];
        }
        
         
    }
};
