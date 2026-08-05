class Solution {
public:
    void dfs(int node,vector<bool>&vis,vector<vector<int>>&adj){
        vis[node]=true;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        for(auto &i:invocations){
            adj[i[0]].push_back(i[1]);
        }
        vector<bool>vis(n,false);
        dfs(k,vis,adj);
        vector<bool>mark(n,false);
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                dfs(i,mark,adj);
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++) ans.push_back(i);
        for(int i=0;i<n;i++){
            if(mark[i] && vis[i]) return ans;
        }
        ans.clear();
        for(int i=0;i<n;i++){
            if(mark[i]) ans.push_back(i);
        }
        return ans;
    }
};