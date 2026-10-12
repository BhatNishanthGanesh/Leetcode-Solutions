class Solution {
public:
    int bfs(int i,int j,vector<vector<int>>&grid,vector<vector<bool>>&vis){
        vis[i][j]=true;
        queue<pair<int,int>>q;
        q.push({i,j});
        int sum=grid[i][j];
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx<0 || nx>=grid.size() || ny<0 || ny>=grid[0].size()) continue;
                if(grid[nx][ny]==0) continue;
                if(!vis[nx][ny]){
                    vis[nx][ny]=true;
                    sum+=grid[nx][ny];
                    q.push({nx,ny});
                }
            }
        }
        return sum;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int mx=0;
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]>0){
                    mx=max(mx,bfs(i,j,grid,vis));
                }
            }
        }
        return mx;
    }
};