class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>color(n+1,-1);
        vector<vector<int>>adj(n+1);
        for(auto it:dislikes){
            int u=it[0],v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=1;i<=n;i++){
            if(color[i]!=-1) continue;
            color[i]=0;
            queue<int>q;
            q.push(i);
            while(!q.empty()){
                int node=q.front();
                q.pop();
                for(auto it:adj[node]){
                    if(color[it]==-1){
                        color[it]=1-color[node];
                        q.push(it);
                    }else if(color[node]==color[it]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};