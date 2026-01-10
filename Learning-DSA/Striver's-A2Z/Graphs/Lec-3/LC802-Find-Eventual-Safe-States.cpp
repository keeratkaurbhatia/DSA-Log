//o(v+e),o(v+e)

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //kahn's algo 
        //flip edges direction
        unordered_map<int,vector<int>> revGraph;
        for (int i= 0; i<graph.size(); i++)
        {
            for (int v: graph[i])
            {
                if (revGraph.find(v)==revGraph.end())
                {
                    revGraph[v]={};
                }
                revGraph[v].push_back(i);
            }
        }
        queue<int> q;
        vector<int> ans;
        vector<int> indegree(graph.size(),0);
        for (int i = 0; i<revGraph.size(); i++)
        {
            for (int v:revGraph[i])
            {
                indegree[v]++;
            }
        }
        for (int i = 0; i<indegree.size(); i++)
        {
            if (indegree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (int v: revGraph[node])
            {
                indegree[v]--;
                if(indegree[v]==0)
                {
                    q.push(v);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;

    }
};
