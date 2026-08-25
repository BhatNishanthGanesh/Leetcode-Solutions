class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        int time=0;
        while(!q.empty()){
            int lvl=q.size();
            bool rotted=false;
            for(int i=0;i<lvl;i++){
                auto [r,c]=q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int nr=r+dx[k];
                    int nc=c+dy[k];
                    if(nr<0 || nr>=n || nc<0 || nc>=m) continue;
                    if(grid[nr][nc]==0 || grid[nr][nc]==2) continue;
                    q.push({nr,nc});
                    grid[nr][nc]=2;
                    rotted=true;
                }
            }
            if(rotted)time++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return time;
    }
};