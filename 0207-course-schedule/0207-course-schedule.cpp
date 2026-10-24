class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indeg(numCourses);
        for(auto &e:prerequisites){
            int u=e[0],v=e[1];
            adj[v].push_back(u);
            indeg[u]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0) q.push(i);
        }
        int cnt=0;
        while(!q.empty()){
            int node=q.front();
            cnt++;
            q.pop();
            for(auto it:adj[node]){
                indeg[it]--;
                if(indeg[it]==0) q.push(it);
            }
        }
        return cnt==numCourses;
    }
};