class Solution {
public:
    void dfs(int node,int d,vector<int>&depth,int &h,vector<vector<int>>&adj){
        depth[node]=d;
        h=max(h,d);
        for(auto it:adj[node]){
            dfs(it,d+1,depth,h,adj);
        }
    }
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n=parent.size();
        vector<vector<int>>adj(n);
        for(int i=1;i<n;i++) adj[parent[i]].push_back(i);
        int h=0;
        vector<int>depth(n);
        dfs(0,1,depth,h,adj);
        long long ans=0;
        for(int i=0;i<n;i++){
            ans+=1ll*nums[i]*(h-depth[i]+1);
        }
        return ans;
    }
};