class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        // [[r,c],t]
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
            }
        }
        int ans=0;
        while(!q.empty()){
            auto it=q.front();

            int row=it.first.first;
            int col=it.first.second;
            int time=it.second;

            q.pop();

            ans=max(ans,time);

            int row1=row-1;
            int row2=row+1;
            int col1=col-1;
            int col2=col+1;

            if(row1>=0 && grid[row1][col]==1){
                grid[row1][col]=2;
                q.push({{row1,col},time+1});
            }

            if(row2<n && grid[row2][col]==1){
                grid[row2][col]=2;
                q.push({{row2,col},time+1});
            }

            if(col1>=0 && grid[row][col1]==1){
                grid[row][col1]=2;
                q.push({{row,col1},time+1});
            }

            if(col2<m && grid[row][col2]==1){
                grid[row][col2]=2;
                q.push({{row,col2},time+1});
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }

        return ans;
    }
};