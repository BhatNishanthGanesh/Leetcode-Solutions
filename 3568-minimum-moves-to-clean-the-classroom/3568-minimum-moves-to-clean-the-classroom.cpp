class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m=classroom[0].size();
        int n=classroom.size();
        queue<tuple<int,int,int,int,int>>q;
        vector<vector<int>>id(n,vector<int>(m,-1));
        int littercount=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(classroom[i][j]=='L'){
                    id[i][j]=littercount;
                    littercount++;
                }
            }
        }
        if(littercount==0) return 0;
        int fullmask=(1<<littercount)-1;
        vector<vector<vector<int>>>vis(n,vector<vector<int>>(m,vector<int>(1<<littercount,-1)));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(classroom[i][j]=='S'){
                    q.push({i,j,0,energy,0});
                    vis[i][j][0]=energy;
                    break;
                }
            }
        }
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        while(!q.empty()){
            auto [x,y,msk,e,steps]=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
                if(classroom[nx][ny]=='X') continue;
                int nergy=e-1;
                if(classroom[nx][ny]=='R') nergy=energy;
                int newmsk=msk;
                if(classroom[nx][ny]=='L') newmsk|=(1<<id[nx][ny]);
                if(newmsk==fullmask) return steps+1;
                if(nergy==0) continue;
                if(nergy<=vis[nx][ny][newmsk]) continue;
                vis[nx][ny][newmsk]=nergy;
                q.push({nx,ny,newmsk,nergy,steps+1});
            }
        }
        return -1;
    }
};