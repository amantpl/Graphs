class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> mat(n,vector<int>(n,1e9));

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            mat[u][v]=wt;
            mat[v][u]=wt;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    mat[i][j]=0;
                }
            }
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
                }
            }
        }

        vector<int> res(n,0);
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(i!=j && mat[i][j]!=1e9 && mat[i][j]<=distanceThreshold){
                    count++;
                }
            }
            ans=min(ans,count);
            res[i]=count;
        }

        for(int i=n-1;i>=0;i--){
            if(res[i]==ans){
                ans=i;
                break;
            }
        }

        return ans;

    }
};