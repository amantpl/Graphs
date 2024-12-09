//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void bfs(int row,int col,vector<vector<char>>& grid,vector<pair<int,int>>& directions,vector<vector<int>>& vis){
        queue<pair<int,int>> q;
        q.push({row,col});
        vis[row][col]=1;
        
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            for(auto it:directions){
                int x=row+it.first;
                int y=it.second+col;
                
                if(x>=0 && x<grid.size() && y>=0 && y<grid[0].size() && grid[x][y]=='1' && vis[x][y]==0){
                    vis[x][y]=1;
                    q.push({x,y});
                }
            }
            
            
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<pair<int, int>> directions = {{0, -1},{0, 1},{-1, 0},{1, 0},{1, -1},{-1, -1},{1, 1},  {-1, 1}};
        
        int count=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    count++;
                    bfs(i,j,grid,directions,vis);
                }
            }
        }
        
        
        return count;
        

    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends