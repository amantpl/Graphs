class Solution {
public:
void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& vis,int n,int m){
    vis[row][col]=1;

    vector<pair<int,int>> directions={{1,0},{-1,0},{0,1},{0,-1}};

    for(auto it:directions){
        int x=it.first+row;
        int y=it.second+col;

        if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1 && vis[x][y]==0){
            dfs(x,y,grid,vis,n,m);
        }
    }
}
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            if(vis[i][0]==0 && grid[i][0]==1){
                dfs(i,0,grid,vis,n,m);
            }

            if(vis[i][m-1]==0 && grid[i][m-1]==1){
                dfs(i,m-1,grid,vis,n,m);
            }
        }

        for(int j=0;j<m;j++){
            if(vis[0][j]==0 && grid[0][j]==1){
                dfs(0,j,grid,vis,n,m);
            }

            if(vis[n-1][j]==0 && grid[n-1][j]==1){
                dfs(n-1,j,grid,vis,n,m);
            }
        }
        int count=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;
    }
};