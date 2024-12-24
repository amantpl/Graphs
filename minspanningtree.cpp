//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        int sum=0;
        
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> q;
        q.push({0,0});
        
        vector<int> vis(V,0);
        
        while(!q.empty()){
            auto it=q.top();
            int wt=it.first;
            int node=it.second;
            q.pop();
            
            if(vis[node]==0){
                sum+=wt;
            }
            vis[node]=1;
            
            for(auto it:adj[node]){
                int node1=it[0];
                int weight=it[1];
                if(vis[node1]==0){
                    q.push({weight,node1});
                }
            }
        }
        
        return sum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends