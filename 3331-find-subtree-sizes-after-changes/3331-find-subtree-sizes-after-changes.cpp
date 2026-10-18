class Solution {
public:
    void dfs(int node,vector<vector<int>>&newadj,vector<int>&sz){
        sz[node]=1;
        for(auto it:newadj[node]){
            dfs(it,newadj,sz);
            sz[node]+=sz[it];
        }
    }
    void findParent(int node,vector<int>&newparent,vector<vector<int>>&adj,string &s,vector<int>&last){
        int old=last[s[node]-'a'];
        if(node!=0 && old!=-1){
            newparent[node]=old;
        }
        last[s[node]-'a']=node;
        for(auto it:adj[node]){
            findParent(it,newparent,adj,s,last);
        }
        last[s[node]-'a']=old;
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        vector<int>newparent=parent;
        int n=parent.size();
        vector<vector<int>>adj(n),newadj(n);
        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
        }
        vector<int>last(26,-1);
        findParent(0,newparent,adj,s,last);
        for(int i=1;i<n;i++){
            newadj[newparent[i]].push_back(i);
        }
        vector<int>sz(n);
        dfs(0,newadj,sz);
        return sz;
    }
};