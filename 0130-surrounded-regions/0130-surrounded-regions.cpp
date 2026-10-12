class Solution {
public:
    void bfs(int i,int j,vector<vector<char>>&board,vector<vector<bool>>&vis){
        queue<pair<int,int>>q;
        board[i][j]='#';
        q.push({i,j});
        vis[i][j]=true;
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx<0 || nx>=board.size() || ny<0 || ny>=board[0].size()) continue;
                if(!vis[nx][ny] && board[nx][ny]=='O'){
                    vis[nx][ny]=true;
                    board[nx][ny]='#';
                    q.push({nx,ny});
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<m;i++){
            if(!vis[0][i] && board[0][i]=='O'){
                bfs(0,i,board,vis);
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i][m-1] && board[i][m-1]=='O'){
                bfs(i,m-1,board,vis);
            }
        }
        for(int i=m-1;i>=0;i--){
            if(!vis[n-1][i] && board[n-1][i]=='O'){
                bfs(n-1,i,board,vis);
            }
        }
        for(int i=n-1;i>=0;i--){
            if(!vis[i][0] && board[i][0]=='O'){
                bfs(i,0,board,vis);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='#'){
                    board[i][j]='O';
                }else if(board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};