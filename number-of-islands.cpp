//https://leetcode.com/problems/number-of-islands/description/


class Solution {
public:

    void bfs(int i, int j , vector<vector<int>>& vis, vector<vector<char>>& grid)
    {
        vis[i][j] = 1;
        queue<pair<int,int>> que;

        que.push({i,j});

        while(!que.empty())
        {
            int row = que.front().first;
            int col = que.front().second;
            que.pop();

            for(int p = -1; p <= 1 ; ++p)
            {
                for(int q= -1; q <= 1; ++q)
                {
                    int n = grid.size();
                int m = grid[0].size();

                    int nrow= row + p;
                    int ncol = col +q;
                    if(
                        (nrow >= 0 && nrow < n &&  ncol >= 0 && ncol < m)
                    && (grid[nrow][ncol] == '1') 
                    && (!vis[nrow][ncol])
                    )
                    {
                        vis[nrow][ncol] = 1;
                        que.push({nrow , ncol});
                    }
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int cnt =0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n , vector<int>(m,0));

        for(int i =0 ; i < n ; ++i)
        {
            for(int j = 0 ; j < m ; ++j)
            {
                if(!vis[i][j] && grid[i][j] == '1')
                {
                    cnt++;
                    bfs(i, j, vis, grid);
                }
            }
        }
        return cnt;
    }
};
