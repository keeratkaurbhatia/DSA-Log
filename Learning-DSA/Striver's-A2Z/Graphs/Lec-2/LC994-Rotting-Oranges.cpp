class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        /*
        queue = pair<int,int> 
        grid traversal push i,j wherever val is 2
        until q is not empty,
            level size = q size
            until level size
                pop value
                for each neighbour
                    if fresh 
                        change to rotten
                        push to q
            time++
        if any fresh still in grid return -1
        else return time-1 
        
        */
        queue<pair<int,int>> q;
        int time = 0;
        int fresh = 0;
        for (int i = 0; i<grid.size(); i++)
        {
            for (int j = 0; j<grid[0].size(); j++)
            {
                if (grid[i][j]==2)
                {
                    q.push({i,j});
                }
                else if (grid[i][j]==1)
                {
                    fresh++;
                }
            }
        }
        if (fresh==0) return 0;
        while (!q.empty())
        {
            int levelSize = q.size();
            for (int i = 0; i<levelSize; i++)
            {
                pair<int,int> node = q.front();
                q.pop();
                int x = node.first;
                int y = node.second;

                vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};

                for (pair<int,int> p : dir)
                {
                    int nx = x + p.first;
                    int ny = y + p.second;

                    if (nx>=0 && nx<grid.size() && ny>=0 && ny<grid[0].size())
                    {
                        if (grid[nx][ny] == 1) 
                        {
                            grid[nx][ny] = 2;
                            q.push({nx,ny});
                        }
                    }
                }
            }
            time++;
        }
        for (int i = 0; i<grid.size(); i++)
        {
            for (int j = 0; j<grid[0].size(); j++)
            {
                if (grid[i][j]==1)
                    return -1;
            }
        }
        return time-1;
    }
};
