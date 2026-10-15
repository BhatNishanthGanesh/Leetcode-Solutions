class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        if(grid[0][0]==1 || grid[n-1][m-1]==1) return -1;
        queue<pair<int,int>>q;
        q.push({0,0});
        vector<vector<int>>dist(n,vector<int>(m,-1));
        dist[0][0]=1;
        int dx[8]={-1,-1,-1,0,0,1,1,1};
        int dy[8]={-1,0,1,-1,1,-1,0,1};
        while(!q.empty()){
            auto [x,y]=q.front();
            if(x==n-1 && y==m-1) return dist[x][y];
            q.pop();
            for(int k=0;k<8;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
                if(grid[nx][ny]==1 || dist[nx][ny]!=-1) continue;
                dist[nx][ny]=dist[x][y]+1;
                q.push({nx,ny});
            }
        }
        return -1;
    }
};