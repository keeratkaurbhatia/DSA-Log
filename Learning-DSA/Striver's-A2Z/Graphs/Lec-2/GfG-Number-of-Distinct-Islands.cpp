// User function Template for C++
//o(nm*log(nm)), o(nm)
class Solution {
  public:
    void dfs(pair<int,int> p, vector<vector<int>>& visited, vector<vector<int>>& grid, pair<int,int> b, vector<pair<int,int>>& ans)
    {
        visited[p.first][p.second]=1;
        int x = p.first-b.first;
        int y = p.second-b.second;
        ans.push_back({x,y});
        
        vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
        for (pair<int,int> t: dir)
        {
            int nx = p.first + t.first;
            int ny = p.second + t.second;
            if (nx>=0 && nx<grid.size() && ny>=0 && ny<grid[0].size())
            {
                if(!visited[nx][ny] && grid[nx][ny]==1)
                {
                    dfs({nx,ny},visited,grid,b,ans);
                }
            }
        }
        
        
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        set<vector<pair<int,int>>> shapes;
        vector<vector<int>> visited (grid.size(), vector<int>(grid[0].size(),0));
        for (int i = 0; i<grid.size(); i++)
        {
            for (int j =0; j<grid[0].size(); j++)
            {
                if (grid[i][j]==1 && !visited[i][j])
                {
                    vector<pair<int,int>> shape;
                    dfs({i,j},visited,grid,{i,j},shape);
                    sort(shape.begin(), shape.end());
                    shapes.insert(shape);
                }
            }
        }
        return shapes.size();
    }
};
