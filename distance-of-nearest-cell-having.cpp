https://www.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1class Solution {
  public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // code here
        
        int n =  grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(grid.size() , vector<int>(grid[0].size(),0));
        
        vector<vector<int>> distance(grid.size() , vector<int>(grid[0].size(),0));
        
        queue<pair<pair<int,int>,int>> que;
        
        for(int i =0 ; i < n ; ++i)
        {
            for(int j = 0 ; j < m; ++j)
            {
                if(grid[i][j] == 1)
                {
                    que.push({{i,j}, 0});
                    vis[i][j] = 1;
                }
            }
        }
        
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        
        
        while(!que.empty())
        {
            auto node = que.front();
            int row = node.first.first;
            int col = node.first.second;
            int dis = node.second ;
            
            que.pop();
            
            for(int i =0 ; i< 4 ; ++i)
            {
                //for(int j =0 ; j < 4 ; ++j)
                {
                    int nrow = row + drow[i];
                    int ncol =  col + dcol[i];
                    
                    if( 
                        nrow >= 0  && nrow < n &&
                        ncol >= 0 && ncol < m &&
                        !vis[nrow][ncol] &&
                        grid[nrow][ncol] == 0
                    )
                    {
                        distance[nrow][ncol] = dis +1;
                        que.push({{nrow,ncol}, dis + 1});
                        vis[nrow][ncol] = 1;
                    }
                }
            }
            
        }
        
        
    }
};
