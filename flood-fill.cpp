https://leetcode.com/problems/flood-fill/\


class Solution {
public:

    void bfs(vector<vector<int>>& image, int sr, int sc, int color, vector<vector<int>>& vis, int initColor)
    {
        vis[sr][sc]= 1;
        image[sr][sc] = color;

        int n = image.size();
    int m = image[0].size();


        queue<pair<int,int>> que;
        que.push({sr,sc});

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};


        while(!que.empty())
        {
            int row = que.front().first;
            int col = que.front().second;
            que.pop();

            for(int i = 0 ; i < 4 ;++i)
            {
                //for(int j = 0 ; j < 4 ; ++j)
                {
                    int nrow = row + delRow[i];
                    int ncol = col + delCol[i];
                    if(
                        nrow >= 0 && nrow < n &&
                        ncol >=0 && ncol < m && 
                        image[nrow][ncol] == initColor && 
                        vis[nrow][ncol] != 1 
                      )
                    {
                        image[nrow][ncol]  = color;
                        vis[nrow][ncol] = 1;
                        que.push({nrow, ncol});
                    }
                }
            }
            
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
            int row = image.size();
            int col = image[0].size();
            int initColor = image[sr][sc];

            vector<vector<int>> vis(row, vector<int>(col,0));

            bfs(image, sr, sc, color, vis, initColor)   ;    

            return image;
    }
};
