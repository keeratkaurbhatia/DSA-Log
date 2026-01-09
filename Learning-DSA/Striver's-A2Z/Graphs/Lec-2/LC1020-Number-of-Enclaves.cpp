//o(mn), o(mn)

class Solution {
public:
    void dfs(pair<int,int> p, vector<vector<int>>& visited, vector<vector<int>>& grid)
    {
        int i = p.first;
        int j = p.second;
        visited[i][j]=1;
        vector<pair<int,int>> dir =
        {{-1,0},{1,0},{0,-1},{0,1}};
        for(pair<int,int> p: dir)
        {
            int nx = i + p.first;
            int ny = j + p.second;
            if(nx>=0 && nx<grid.size() && ny>=0 && ny<grid[0].size())
            {
                if(!visited[nx][ny] && grid[nx][ny]==1)
                {
                    dfs({nx,ny},visited, grid);
                }
            }
        }

    }
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(),0));
        //first row = 0 j
        for (int j = 0; j<grid[0].size(); j++)
        {
            if (grid[0][j]==1 && visited[0][j]!=1)
            {
                dfs({0,j},visited, grid);
            }
        }
        //first col = i 0
        for (int i = 0; i<grid.size(); i++)
        {
            if (grid[i][0]==1 && visited[i][0]!=1)
            {
                dfs({i,0},visited, grid);
            }
        }
        // last row grid.size-1 j
        for (int j = 0; j<grid[0].size(); j++)
        {
            if (grid[grid.size()-1][j]==1 && visited[grid.size()-1][j]!=1)
            {
                dfs({grid.size()-1,j},visited, grid);
            }
        }
        //last col = i grid[0].size()-1
        for (int i = 0; i<grid.size(); i++)
        {
            if (grid[i][grid[0].size()-1]==1 && visited[i][grid[0].size()-1]!=1)
            {
                dfs({i,grid[0].size()-1},visited, grid);
            }
        }
        //boundary ones wont count either ways
        int count = 0;
        for (int i = 1; i<grid.size()-1; i++)
        {
            for (int j = 1; j<grid[0].size()-1; j++)
            {
                if (grid[i][j]==1 && visited[i][j]==0)
                {
                    count++;
                }
            }
        }
        return count;
    }
};
