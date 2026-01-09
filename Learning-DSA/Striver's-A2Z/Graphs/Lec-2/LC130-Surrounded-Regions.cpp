//o(mn), o(mn)

class Solution {
public:
    void dfs(pair<int,int> p, vector<vector<int>>& visited,
    vector<vector<char>>& board)
    {
        int x = p.first;
        int y = p.second;
        visited[x][y]=1;
        vector<pair<int,int>> dir = 
        {{-1,0},{1,0},{0,-1},{0,1}};
        for (pair<int,int>t:dir)
        {
            int nx = x + t.first;
            int ny = y + t.second;
            if (nx>=0 && nx<board.size() && ny>=0 && ny<board[0].size())
            {
                if (!visited[nx][ny] && board[nx][ny]=='O')
                {
                    dfs({nx,ny},visited,board);
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        vector<vector<int>> visited (board.size(), vector<int>(board[0].size(),0));
        
        for (int j = 0; j<board[0].size(); j++)
        {
            if (board[0][j]=='O' && !visited[0][j])
            {
                dfs({0,j},visited,board);
            }
        }
        for (int j = 0; j<board[0].size(); j++)
        {
            if (board[board.size()-1][j]=='O' && !visited[board.size()-1][j])
            {
                dfs({board.size()-1,j},visited,board);
            }
        }
        for (int i = 0; i<board.size(); i++)
        {
            if (board[i][0]=='O' && !visited[i][0])
            {
                dfs({i,0},visited,board);
            }
        }
        for (int i = 0; i<board.size(); i++)
        {
            if (board[i][board[0].size()-1]=='O' && !visited[i][board[0].size()-1])
            {
                dfs({i,board[0].size()-1},visited,board);
            }
        }
        for (int i = 1; i<board.size()-1; i++)
        {
            for (int j = 1; j<board[0].size()-1; j++)
            {
                if (board[i][j]=='O' && !visited[i][j])
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
