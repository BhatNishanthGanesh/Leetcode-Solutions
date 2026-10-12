class Solution {
public:
    bool bfs(int i,int j,vector<vector<int>>&grid,vector<vector<bool>>&vis,int k){
        vis[i][j]=true;
        queue<pair<int,int>>q;
        long long sum=grid[i][j];
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        q.push({i,j});
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
                    sum+=1ll*grid[nx][ny];
                    q.push({nx,ny});
                } 
            }
        }
        return sum%k==0;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]>0){
                    if(bfs(i,j,grid,vis,k)) cnt++;
                }
            }
        }
        return cnt;
    }
};