class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>>dist(n,vector<int>(k+2,INT_MAX));
        dist[src][0]=0;
        vector<vector<pair<int,int>>>adj(n);
        for(auto &e:flights){
            int u=e[0],v=e[1],w=e[2];
            adj[u].push_back({v,w});
        }
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        pq.push({0,src,0});
        while(!pq.empty()){
            auto [d,node,stops]=pq.top();
            pq.pop();
            if(node==dst) return d;
            if(d>dist[node][stops]) continue;
            if(stops==k+1) continue;
            for(auto &[nei,wt]:adj[node]){
                if(d+wt<dist[nei][stops+1]){
                    dist[nei][stops+1]=d+wt;
                    pq.push({dist[nei][stops+1],nei,stops+1});
                }
            }
        }
        return -1;
    }
};