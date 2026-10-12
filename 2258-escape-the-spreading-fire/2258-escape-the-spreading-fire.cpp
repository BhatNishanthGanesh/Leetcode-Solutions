class Solution {
public:
    bool func(vector<vector<int>>&grid,vector<vector<int>>&fireArrival,int time){
        int n=grid.size(),m=grid[0].size();
        int wait=0;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        queue<tuple<int,int,int>>q;
        if(grid[0][0]==1 || grid[0][0]==2) return false;
        if(time>=fireArrival[0][0]) return false;
        q.push({0,0,time});
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        vis[0][0]=true;
        while(!q.empty()){
            auto [x,y,currTime]=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
                if(vis[nx][ny] || grid[nx][ny]==2) continue;
                int nxtTime=currTime+1;
                if(nx==n-1 && ny==m-1){
                    if(nxtTime<=fireArrival[nx][ny]) return true;
                }
                if(nxtTime<fireArrival[nx][ny]){
                    vis[nx][ny]=true;
                    q.push({nx,ny,nxtTime});
                }
            }
        }
        return false;
    }

    vector<vector<int>>mbfs(int n,int m,vector<vector<int>>&grid){
        vector<vector<int>>v=grid;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        vector<vector<int>>ans(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]==1){
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        while(!q.empty()){
            int lvl=q.size();
            for(int i=0;i<lvl;i++){
                auto [x,y]=q.front();
                q.pop();
                vis[x][y]=true;
                for(int k=0;k<4;k++){
                    int nx=x+dx[k];
                    int ny=y+dy[k];
                    if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
                    if(v[nx][ny]==1 || v[nx][ny]==2) continue;
                    if(!vis[nx][ny]){
                        vis[nx][ny]=true;
                        v[nx][ny]=1;
                        ans[nx][ny]=ans[x][y]+1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return ans;
    }

    int maximumMinutes(vector<vector<int>>& grid) {
        int time=-1;
        int l=0,h=1e9;
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>fireArrival=mbfs(n,m,grid);
        while(l<=h){
            int mid=l+(h-l)/2;
            if(func(grid,fireArrival,mid)){
                time=mid;
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return time;
    }
};