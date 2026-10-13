class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans;
        if(prerequisites.empty()){
            for(int i=numCourses-1;i>=0;i--) ans.push_back(i);
            return ans;
        }
        vector<vector<int>>adj(numCourses);
        vector<int>indeg(numCourses);
        for(auto ele:prerequisites){
            int u=ele[0],v=ele[1];
            adj[v].push_back(u);
            indeg[u]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        int cnt=0;
        while(!q.empty()){
            int node=q.front();
            ans.push_back(node);
            cnt++;
            q.pop();
            for(auto it:adj[node]){
                indeg[it]--;
                if(indeg[it]==0) q.push(it);
            }
        }
        if(cnt==numCourses) return ans;
        return {};
    }
};