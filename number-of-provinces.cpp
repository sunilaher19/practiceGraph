https://leetcode.com/problems/number-of-provinces/description/

void dfs(int node ,  vector<int>& vis , vector<vector<int>>& adj)
{
    vis[node] = 1;
    for(const auto& i: adj[node])
    {
        if(!vis[i])
        {
            vis[i] = 1;
            dfs(i, vis, adj);
        }
    }
}


int findNumOfProvinces(vector<vector<int>>& roads, int n) {
    // Write your code here.

    vector<int> adj[n];
    vector<int> vis(n,0);
    int cnt=0;
    for(int row= 0 ; row < road.size() ; ++row)
    {
        for(int col=0; col < road[row].size() ; ++col)
        {
            if(roads[row][col] && i !=j)
            {
                adj[row].push_back(col); 
                adj[col].push_back(row); 
            }
        }
    }

    for(int i =0 ; i < n+1; ++i)
    {
        if(!vis[i])
        {
            ++cnt;
            dfs(i, vis, adj);
        }
    }
    return cnt;

}
