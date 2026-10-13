class DSU{
public:
    vector<int>size,parent;
    DSU(int n){
        size.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int ultParent(int node){
        if(parent[node]==node) return node;
        return parent[node]=ultParent(parent[node]);
    }
    void unionBySize(int u,int v){
        int ult_u=ultParent(u);
        int ult_v=ultParent(v);
        if(ult_u==ult_v) return;
        if(size[ult_u]<=size[ult_v]){
            parent[ult_u]=ult_v;
            size[ult_v]+=size[ult_u];
        }else{
            parent[ult_v]=ult_u;
            size[ult_u]+=size[ult_v];
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DSU ds(n+1);
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            int u=edges[i][0],v=edges[i][1];
            if(ds.ultParent(u)==ds.ultParent(v)) return {u,v};
            ds.unionBySize(u,v);
        }
        return {};
    }
};