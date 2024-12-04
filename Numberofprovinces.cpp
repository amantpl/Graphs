class Solution {
public:

void dfs(int node,vector<vector<int>>& adj,vector<int>& vis){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> vis(n,0);
        vector<vector<int>> adj;
        for(int i=0;i<n;i++){
            vector<int> res;
            for(int j=0;j<isConnected[0].size();j++){
                if(i!=j && isConnected[i][j]==1){
                    res.push_back(j);
                }
            }
            adj.push_back(res);
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                count++;
                dfs(i,adj,vis);
            }
        }
        return count;
    }
};