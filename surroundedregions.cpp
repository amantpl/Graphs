class Solution {
public:

void dfs(int row,int col,vector<vector<char>>& board,vector<vector<int>>& vis,vector<pair<int,int>>& directions){
    vis[row][col]=1;

    for(auto dir:directions){
        int x=row+dir.first;
        int y=col+dir.second;

        if(x>=0 && x<board.size() && y>=0 && y<board[0].size() && !vis[x][y] && board[x][y]=='O'){
            dfs(x,y,board,vis,directions);
        }
    }

    
}
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<pair<int,int>> directions={{1,0},{0,1},{-1,0},{0,-1}};

        for(int i=0;i<n;i++){
            if(vis[i][0]==0 && board[i][0]=='O'){
                dfs(i,0,board,vis,directions);
            }

            if(vis[i][m-1]==0 && board[i][m-1]=='O'){
                dfs(i,m-1,board,vis,directions);
            }
        }

        for(int j=0;j<m;j++){
            if(vis[0][j]==0 && board[0][j]=='O'){
                dfs(0,j,board,vis,directions);
            }

            if(vis[n-1][j]==0 && board[n-1][j]=='O'){
                dfs(n-1,j,board,vis,directions);
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