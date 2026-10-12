class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) q.push({i,j});
            }
        }
        int time=0;
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        while(!q.empty()){
            int lvl=q.size();
            bool f=false;
            for(int i=0;i<lvl;i++){
                auto [x,y]=q.front();
                vis[x][y]=true;
                q.pop();
                for(int k=0;k<4;k++){
                    int nx=x+dx[k];
                    int ny=y+dy[k];
                    if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
                    if(grid[nx][ny]==0 || grid[nx][ny]==2) continue;
                    if(!vis[nx][ny]){
                        vis[nx][ny]=true;
                        f=true;
                        grid[nx][ny]=2;
                        q.push({nx,ny});
                    }
                }
            }
            if(f) time++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return time;
    }
};