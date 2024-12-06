class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            if(board[i][m-1]=='O'){
                q.push({i,m-1});
                vis[i][m-1]=1;
            }

            if(board[i][0]=='O'){
                q.push({i,0});
                vis[i][0]=1;
            }
        }

        for(int i=0;i<m;i++){
            if(board[0][i]=='O'){
                q.push({0,i});
                vis[0][i]=1;
            }

            if(board[n-1][i]=='O'){
                q.push({n-1,i});
                vis[n-1][i]=1;
            }
        }

        vector<pair<int,int>> directions={{0,1},{0,-1},{-1,0},{1,0}};

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;

            q.pop();

            for(auto dir:directions){
                int x=row+dir.first;
                int y=col+dir.second;

                if(x>=0 && x<n && y>=0 && y<m && board[x][y]=='O' && vis[x][y]==0){
                    vis[x][y]=1;
                    q.push({x,y});
                }
            }
            
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0){
                    board[i][j]='X';
                }
            }
        }
    }
};