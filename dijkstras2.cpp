//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template
class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Code here
        set<pair<int,int>> st;
        int n=adj.size();
        vector<int> dist(n,INT_MAX);
        st.insert({0,src});
        dist[src]=0;
        
        while(!st.empty()){
            auto it=st.begin();
            int distance=it->first;
            int node=it->second;
            st.erase(it);

            for(auto it1:adj[node]){
                int dis_from_node=it1.second;
                int node_connected=it1.first;
                int dis_from_src=distance+dis_from_node;
                
                if(dis_from_src<dist[node_connected]){
                    dist[node_connected]=dis_from_src;
                    st.insert({dis_from_src,node_connected});
                }
            }
            
        }
        
        return dist;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends