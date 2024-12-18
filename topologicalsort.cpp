//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return list containing vertices in Topological order.
    void dfs(int node,vector<int>& vis,stack<int>& res,vector<vector<int>>& adj){
        vis[node]=1;
        
        for(auto it:adj[node]){
            if(vis[it]==0){
                dfs(it,vis,res,adj);
            }
        }
        
        res.push(node);
    }
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        // Your code here
        int n=adj.size();
        vector<int> vis(n,0);
        vector<int> ans;
        stack<int> res;
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,res,adj);
            }
        }
        
        while(!res.empty()){
            ans.push_back(res.top());
            res.pop();
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<vector<int>> adj(N);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topologicalSort(adj);

        cout << check(N, res, adj) << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends