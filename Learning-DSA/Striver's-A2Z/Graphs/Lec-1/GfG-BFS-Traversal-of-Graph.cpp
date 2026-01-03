//o(v+e), o(v)

class Solution {
  public:
    
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        queue<int> q;
        q.push(0);
        vector<int> ans;
        vector<int> visited(adj.size(),0);
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            if (visited[node]==0)
            {
                visited[node]=1;
                ans.push_back(node);
                for (int v: adj[node])
                {
                    if(visited[v]==0)
                    {
                        q.push(v);
                        
                    }
                }
            }
            
        }
        return ans;
    }
};
