class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto &e:edges) adj[e[0]].push_back({e[1],e[2]});
        vector<vector<int>>dist(n,vector<int>(k+1,INT_MAX));
        dist[0][1]=0;
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        pq.push({0,0,1});
        while(!pq.empty()){
            auto [d,node,cnt]=pq.top();
            pq.pop();
            if(d!=dist[node][cnt]) continue;
            for(auto it:adj[node]){
                int adjNode=it.first,wt=it.second;
                int newCnt=0;
                if(labels[node]==labels[adjNode]){
                    newCnt=cnt+1;
                }else{
                    newCnt=1;
                }
                if(newCnt>k) continue;
                if(d+wt<dist[adjNode][newCnt]){
                    dist[adjNode][newCnt]=d+wt;
                    pq.push({d+wt,adjNode,newCnt});
                }
            }
        }
        int mini=*min_element(dist[n-1].begin(),dist[n-1].end());
        return mini==INT_MAX?-1:mini;
    }
};