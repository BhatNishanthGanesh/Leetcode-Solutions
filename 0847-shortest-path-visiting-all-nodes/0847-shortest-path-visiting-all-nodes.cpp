class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        int tot=(1<<n);
        queue<pair<int,int>>q;
        vector<vector<bool>>vis(tot,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            int mask=(1<<i);
            q.push({i,mask});
            vis[mask][i]=true;
        }
        int steps=0;
        int target=tot-1;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto [node,mask]=q.front();
                q.pop();
                if(mask==target) return steps;
                for(auto it:graph[node]){
                    int newMask=mask|(1<<it);
                    if(!vis[newMask][it]){
                        vis[newMask][it]=true;
                        q.push({it,newMask});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};