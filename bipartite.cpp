//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  bool dfs(int node,int col,vector<int>& color,vector<vector<int>>& adj){
      color[node]=col;
      
      for(auto it:adj[node]){
          if(color[it]==-1){
              if(dfs(it,!col,color,adj)==false){
                  return false;
              }
          }else{
              if(color[it]==col){
                  return false;
              }
          }
      }
      return true;
  }
    bool isBipartite(vector<vector<int>>& adj) {
        // Code here
        int n=adj.size();
        vector<int> color(n,-1);
        
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(dfs(i,0,color,adj)==false){
                    return false;
                }
            }
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isBipartite(adj);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends