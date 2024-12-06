class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }

        vector<pair<int,int>> directions={{0,1},{1,0},{-1,0},{0,-1}};
        while(!q.empty()){
            auto it=q.front();
            int row=it.first.first;
            int col=it.first.second;
            int distance=it.second;
            q.pop();

            dist[row][col]=distance;

            for(auto dir:directions){
                int x=row+dir.first;
                int y=col+dir.second;
                if(x>=0 && x<n && y>=0 && y<m && !vis[x][y]){
                    vis[x][y]=1;
                    q.push({{x,y},distance+1});
                }
            }
        }

        return dist;
    }
};