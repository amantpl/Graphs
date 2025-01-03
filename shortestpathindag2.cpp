//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
  void dfs(int node,stack<int>& st,vector<int>& vis,vector<vector<pair<int,int>>>& adj){
      vis[node]=1;
      
      for(auto it:adj[node]){
            int node1=it.first;
            if(vis[node1]==0){
                dfs(node1,st,vis,adj);
            }
      }
      
      st.push(node);
  }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        // using topo sort
        
        vector<vector<pair<int,int>>> adj(V);
        for(int i=0;i<E;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        
        vector<int> vis(V,0);
        stack<int> st;
        
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                dfs(i,st,vis,adj);
            }
        }
        vector<int> ans(V,INT_MAX);
        ans[0]=0;
        while(!st.empty()){
            int node=st.top();
            int dist=ans[node];
            st.pop();
            
            if(ans[node]!=INT_MAX){
            for(auto it:adj[node]){
                int node1=it.first;
                int distance=it.second;
                if(distance+dist<ans[node1]){
                    ans[node1]=distance+dist;
                }
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends