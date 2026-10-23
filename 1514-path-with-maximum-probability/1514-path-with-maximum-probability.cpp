class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>>adj(n);
        for(int i=0;i<edges.size();i++){
            double w=succProb[i];
            int u=edges[i][0],v=edges[i][1];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        priority_queue<pair<double,int>>pq;
        vector<double>prob(n,0.0);
        prob[start_node]=1.0;
        pq.push({1.0,start_node});
        while(!pq.empty()){
            auto [d,node]=pq.top();
            pq.pop();
            if(d<prob[node]) continue;
            if(node==end_node) return d;
            for(auto &[nei,wt]:adj[node]){
                if(d*wt>prob[nei]){
                    prob[nei]=d*wt;
                    pq.push({prob[nei],nei});
                }
            }
        }
        return 0.0;
    }
};