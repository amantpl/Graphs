class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;


        for(int i=0;i<n;i++){
            if(grid[i][0]==1){
                q.push({i,0});
                vis[i][0]=1;
            }

            if(grid[i][m-1]==1){
                vis[i][m-1]=1;
                q.push({i,m-1});
            }
        }

        for(int i=0;i<m;i++){
            if(grid[0][i]==1){
                vis[0][i]=1;
                q.push({0,i});
            }

            if(grid[n-1][i]==1){
                vis[n-1][i]=1;
                q.push({n-1,i});
            }
        }

        vector<pair<int,int>> directions={{1,0},{0,1},{-1,0},{0,-1}};

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            for(auto dir:directions){
                int x=row+dir.first;
                int y=col+dir.second;

                if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1 && vis[x][y]==0){
                    vis[x][y]=1;
                    q.push({x,y});
                }
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