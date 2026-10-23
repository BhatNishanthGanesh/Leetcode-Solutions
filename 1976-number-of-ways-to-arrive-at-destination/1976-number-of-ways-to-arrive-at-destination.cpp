class Solution {
public:
    const int mod=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto &e:roads){
            int u=e[0],v=e[1],w=e[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<long long>dist(n,LLONG_MAX);
        vector<int>ways(n,0);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,0});
        dist[0]=0;
        ways[0]=1;
        while(!pq.empty()){
            auto [d,node]=pq.top();
            pq.pop();
            if(d<dist[node]) continue;
            for(auto [nei,wt]:adj[node]){
                if(d+wt<dist[nei]){
                    dist[nei]=d+wt;
                    ways[nei]=ways[node];
                    pq.push({dist[nei],nei});
                }else if(d+wt==dist[nei]){
                    ways[nei]=(ways[nei]+ways[node])%mod;
                }
            }
        }
        return ways[n-1];
    }
};