class Solution {
public:
    void bfs(int i,int j,vector<vector<char>>&board,vector<vector<bool>>&vis){
        vis[i][j]=true;
        queue<pair<int,int>>q;
        q.push({i,j});
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx<0 || nx>=board.size() || ny<0 || ny>=board[0].size()) continue;
                if(board[nx][ny]=='.') continue;
                if(!vis[nx][ny]){
                    vis[nx][ny]=true;
                    q.push({nx,ny});
                }
            }
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='X'){
                    bfs(i,j,board,vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};