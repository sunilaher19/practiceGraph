
https://leetcode.com/problems/surrounded-regions/submissions/1876425137/
class Solution {
public:
    int dcol[5] = {-1,0,1,0};
    int drow[5] = {0,-1,0,1};
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& board)
    {
        int n = board.size();
        int m = board[0].size();
        vis[row][col] = 1;

        //check all side
        for(int i = 0 ; i <4 ; ++i)
        {
            {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(
                    nrow >= 0 && nrow < n &&
                    ncol >=0 && ncol < m && 
                    !vis[nrow][ncol] &&
                    board[nrow][ncol] == 'O'
                )
                {
                    vis[nrow][ncol] = 1;
                    dfs(nrow,ncol, vis, board);
                }
            }
        }
        
    }

    void solve(vector<vector<char>>& board) {
        
        vector<vector<int>> vis(board.size() , vector<int>(board[0].size(), 0 ));
        int n = board.size();
        int m = board[0].size();

       

        //first 0,j
        for(int i =0 ; i < m ; ++i )//col
        {
            if(board[0][i] == 'O')
            {
                dfs(0,i,vis, board);
            }
        }

        //seocnd j,0
        for(int i =0 ; i < n ; ++i )//col
        {
            if(board[i][0] == 'O')
            {
                dfs(i,0,vis, board);
            }
        }

        //thrid n,j
        for(int i =0 ; i < m ; ++i )//col
        {
            if(board[n-1][i] == 'O')
            {
             dfs(n-1,i,vis, board);
            }
        }

        //forth j,m
        for(int i =0 ; i < n ; ++i )//col
        {
            if(board[i][n-1] == 'O')
            {
                dfs(i,m-1,vis, board);
            }
        }

        for(int i = 0 ; i< n ; ++i )
        {
            for(int j = 0 ; j< m ; ++j )
            {
                if(vis[i][j] != 1 && board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }   
            }
        }

    }
};
