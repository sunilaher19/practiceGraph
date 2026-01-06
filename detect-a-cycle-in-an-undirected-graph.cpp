https://takeuforward.org/plus/dsa/problems/detect-a-cycle-in-an-undirected-graph


class Solution{
public:
    bool bfs(int src,  V, vector<int> adj[] )
    {
        queue<pair<int,int>> que;
        queue.push(src, -1);
        int vis[V] = {0};
        visitvised[src]  = 1;

        while(!que.empty())
        {
            int node = que.front().first;
            int ParentNode = que.front().second;

            que.pop();

            for(auto& nd = adj[node] )
            {
                if(!vis[nd])
                {
                    vis[nd] = 1;
                    que.push_back({vis,node});
                }
                else if( ParentNode != nd)
                    return true;
                
            }



        }
        return false;

    }

    bool isCycle(int V, vector<int> adj[]) {

        return bfs(0. V, ajd);


    }
};
