class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));

        

 priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0,{0,0}});
        vector<pair<int, int>> directions = {
            {-1, 0},  // Up
            { 1, 0},  // Down
            { 0, -1}, // Left
            { 0, 1}   // Right
        };

        dist[0][0]=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int diff=it.first;
            int row=it.second.first;
            int col=it.second.second;


            for(auto it:directions){
                int x=it.first+row;
                int y=it.second+col;

                if(x>=0 && x<n && y>=0 && y<m){
                    int neweffort=max(abs(heights[row][col]-heights[x][y]),diff);
                    if(neweffort<dist[x][y]){
                        dist[x][y]=neweffort;
                        pq.push({neweffort,{x,y}});
                    }
                }
            }
        }

        return dist[n-1][m-1];
    }

};