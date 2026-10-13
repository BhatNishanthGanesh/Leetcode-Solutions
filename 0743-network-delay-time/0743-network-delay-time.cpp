class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n+1,INT_MAX);
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        dist[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        while(!pq.empty()){
            auto [curr_dis,node]=pq.top();
            pq.pop();
            for(auto it:adj[node]){
                auto [next_node,next_dis]=it;
                if(curr_dis+next_dis<dist[next_node]){
                    dist[next_node]=curr_dis+next_dis;
                    pq.push({dist[next_node],next_node});
                }
            }
        }
        int mx=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX) return -1;
            mx=max(mx,dist[i]);
        }
        return mx;
    }
};