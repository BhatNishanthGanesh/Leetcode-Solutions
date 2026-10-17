class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector<int>ans(queries.size());
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        vector<pair<int,int>>q;
        for(int i=0;i<queries.size();i++) q.push_back({queries[i],i});
        sort(q.begin(),q.end());
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size()));
        vis[0][0]=1;
        int cnt=0;
        pq.push({grid[0][0],0,0});
        for(auto ele:q){
            while(!pq.empty() && get<0>(pq.top())<ele.first){
                auto [_,x,y]=pq.top();
                pq.pop();
                cnt++;
                for(int k=0;k<4;k++){
                    int nx=x+dx[k];
                    int ny=y+dy[k];
                    if(nx<0 || nx>=grid.size() || ny<0 || ny>=grid[0].size()) continue;
                    if(vis[nx][ny]!=0) continue;
                    vis[nx][ny]=1;
                    pq.push({grid[nx][ny],nx,ny});
                }
            }
            ans[ele.second]=cnt;
        }
        return ans;
    }
};