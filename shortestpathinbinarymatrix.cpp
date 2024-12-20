class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1){
            return -1;
        }
        vector<vector<int>> vis(n,vector<int>(n,0));

        queue<pair<pair<int,int>,int>> q;
        int dist=1;
        q.push({{0,0},dist});
        vis[0][0]=1;
        vector<pair<int, int>> directions = {
        {-1, -1}, // Top-left
        {-1,  0}, // Top
        {-1,  1}, // Top-right
        { 0, -1}, // Left
        { 0,  1}, // Right
        { 1, -1}, // Bottom-left
        { 1,  0}, // Bottom
        { 1,  1}  // Bottom-right
        };

        while(!q.empty()){
            auto it=q.front();
            int row=it.first.first;
            int col=it.first.second;
            int distance=it.second;
            q.pop();


            if(grid[row][col]==0 && row==n-1 && col==n-1){
                return distance;
            }
            for(auto it1:directions){
                int x=row+it1.first;
                int y=col+it1.second;
                if(x>=0 && x<n && y>=0 && y<n && vis[x][y]==0 && grid[x][y]==0){
                    vis[x][y]=1;
                    q.push({{x,y},distance+1});
                }
            }
           
        }
        return -1;
    }
};