class Solution {
public:
    void dfs(int node,int n,vector<vector<int>>&graph,vector<vector<int>>&v,vector<int>&temp){
        temp.push_back(node);
        if(node==n){
            v.push_back(temp);
            temp.pop_back();
            return;
        }
        for(auto it:graph[node]){
            dfs(it,n,graph,v,temp);
        }
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>v;
        vector<int>temp;
        int n=graph.size();
        dfs(0,n-1,graph,v,temp);
        return v;
    }
};