class Solution {
public:
    void bfs(int i,int j,vector<vector<char>>&grid,vector<vector<bool>>&vis){
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        vis[i][j]=true;
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx<0 || nx>=grid.size() || ny<0 || ny>=grid[0].size()) continue;
                if(!vis[nx][ny] && grid[nx][ny]=='1'){
                    vis[nx][ny]=true;
                    q.push({nx,ny});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    bfs(i,j,grid,vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};