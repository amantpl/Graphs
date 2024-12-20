//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

//Back-end complete function Template for C++


// } Driver Code Ends
class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int n=adj.size();
        vector<int> ans(n,INT_MAX);
        
        queue<pair<int,int>> q;
        q.push({src,0});
        ans[src]=0;
        
        while(!q.empty()){
            auto it=q.front();
            int node=it.first;
            int dist=it.second;
            q.pop();
            
            for(auto it:adj[node]){
                if(dist+1<ans[it]){
                    ans[it]=dist+1;
                    q.push({it,dist+1});
                }
            }
        }
        for(int i=0;i<ans.size();i++){
            if(ans[i]==INT_MAX){
                ans[i]=-1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int src;
        cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(adj, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
        cout << "~\n";
    }
}

// } Driver Code Ends