class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<int>>edges;   
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dis=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges.push_back({i,j,dis});
            }
        }
        vector<vector<pair<int,int>>>adj(n);
        for(auto &e:edges){
            int u=e[0],v=e[1],w=e[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        vector<bool>vis(n,false);
        int tot=0;
        while(!pq.empty()){
            auto [w,u]=pq.top();
            pq.pop();
            if(vis[u]) continue;
            vis[u]=true;
            tot+=w;
            for(auto [v,nw]:adj[u]){
                if(!vis[v]){
                    pq.push({nw,v});
                }
            }
        }
        return tot;
    }
};