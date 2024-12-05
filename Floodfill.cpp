class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int prev=image[sr][sc];
        if(prev==color){
            return image;
        }

        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc]=color;
        
        while(!q.empty()){
            auto it=q.front();
            int row=it.first;
            int col=it.second;
            
            int row1=row-1;
            int row2=row+1;
            int col1=col-1;
            int col2=col+1;
            q.pop();

            if(row1>=0 && image[row1][col]==prev){
                image[row1][col]=color;
                q.push({row1,col});
            }

            if(row2<image.size() && image[row2][col]==prev){
                image[row2][col]=color;
                q.push({row2,col});
            }

            if(col1>=0 && image[row][col1]==prev){
                image[row][col1]=color;
                q.push({row,col1});
            }

            if(col2<image[0].size() && image[row][col2]==prev){
                image[row][col2]=color;
                q.push({row,col2});
            }
        }

        return image;
    }
};