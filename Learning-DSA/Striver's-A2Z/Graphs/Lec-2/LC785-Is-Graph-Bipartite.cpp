//o(v+e), o(v)

class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& colors)
    {
        for(int j = 0; j<graph[node].size(); j++)
        {
            if (colors[graph[node][j]]==-1)
            {
                colors[graph[node][j]]=1-colors[node];
                if(!dfs(graph[node][j],graph,colors))
                return false;
            }
            else if (colors[graph[node][j]]==colors[node])
            {
                return false;
            }
        }
        return true;

    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colors (graph.size(),-1);
    
        for (int i = 0; i < graph.size(); i++)
        {
            if (colors[i] == -1)
            {
                colors[i] = 0;
                if (!dfs(i, graph, colors))
                    return false;
            }
        }
        return true;
    }
};
